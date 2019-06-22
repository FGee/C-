#include "../include/workThreadTask.h"
#include "../include/tcpConnection.h"
#include "../include/dictoryary.h"
#include "../include/cacheManager.h"
#include "../include/LRUcache.h"
#include "../include/myLog.h"

#include <json/json.h>

#include <iostream>
#include <functional>
#include <sstream>
#include <cstdlib>

extern __thread const char* threadName;

namespace wd
{

WorkThreadTask::WorkThreadTask(shared_ptr<TcpConnection> sp, const string& m)
    : _sptrConn(sp), _msg(m) {}

void WorkThreadTask::process()
{
    // <<decode>>
    string queryWrd = jsonToQueryWrd(_msg);

    // <<compute>>
    string jsonStr;
    auto pCacheMan = CacheManager::getInstance();
    if (pCacheMan->isUpdating()) {
        matchWrdIntoResult(queryWrd);    
        jsonStr = obtainResultJson(RESULT_NUM);
    } else {
        LogDebug("Thread %d handle query task", atol(threadName));
        auto& cache = pCacheMan->getCache(atol(threadName));
        jsonStr = cache.searchInCache(queryWrd);
        if (jsonStr == string()) {
            matchWrdIntoResult(queryWrd);    
            jsonStr = obtainResultJson(RESULT_NUM);
            cache.addIntoCache(queryWrd, jsonStr);
        }
    }

    // <<encode>>
    _sptrConn->sendInLoop(jsonStr);
}

string WorkThreadTask::jsonToQueryWrd(const string& jsonData)
{
    Json::Reader readInfo;

    Json::Value root;
    if (readInfo.parse(jsonData, root)) {
        if (root["QueryWord"].isString()) {
            return root["QueryWord"].asString();
        } 
    }
    return string();
}


size_t WorkThreadTask::minEditDistance(const string& srcWrd, const string& destWrd)
{
    //function<size_t(size_t, size_t, size_t)>
    auto minNumFunc = [](size_t a, size_t b, size_t c) {
        size_t minNum = 0;
        minNum = (a < b) ? a : b;
        minNum = (minNum < c) ? minNum : c;
        return minNum;
    };

    size_t srcLen = srcWrd.size();
    size_t destLen = destWrd.size();
    size_t coordinateArr[srcLen + 1][destLen + 1];
    
    for (size_t i = 0; i < srcLen + 1; ++i) {
        coordinateArr[i][0] = i;
    }
    for (size_t j = 0; j < destLen + 1; ++j) {
        coordinateArr[0][j] = j;
    }

    for (size_t i = 1; i < srcLen + 1; ++i) {
        for (size_t j = 1; j < destLen + 1; ++j) {
            size_t replaceNum = coordinateArr[i - 1][j - 1];
            ++replaceNum;
            if (srcWrd[i - 1] == destWrd[j - 1]) {
                --replaceNum;
            }
            coordinateArr[i][j] = minNumFunc(replaceNum, 
                                             coordinateArr[i][j - 1] + 1,
                                             coordinateArr[i - 1][j] + 1);
        }
    }
    
    return coordinateArr[srcLen][destLen];
}

void WorkThreadTask::matchWrdIntoResult(const string& queryWrd)
{
    auto dicVec = Dictionary::getInstance()->dictVecGet();
    auto indexUnorderedMap = Dictionary::getInstance()->indexUnorderMapGet();

    const char* pos = queryWrd.c_str();
    
    int bitMapSz = (dicVec.size() / (sizeof(int) * 8)) + 1;
    int bitMapArr[bitMapSz];
    memset(bitMapArr, 0, sizeof(bitMapArr));
    while (*pos != '\0') {
        int byteNum = readNBytes(pos);
        string indexWrd(pos, byteNum);
        pos += byteNum;
        auto retIter = indexUnorderedMap.find(indexWrd);
        if (retIter == indexUnorderedMap.end()) { continue; }
        set<size_t> lineNoSet(retIter->second);
        for (auto & lineNo : lineNoSet) {
            size_t indexBitMap = lineNo / 32;
            size_t offset = lineNo % 32;
            if (bitMapArr[indexBitMap] & (1 << offset)) {
                continue;
            }
            bitMapArr[indexBitMap] = bitMapArr[indexBitMap] | (1 << offset);
            pair<string, size_t> retPair = dicVec[lineNo];
            Result newResult;
            newResult._editLenth = minEditDistance(retPair.first, queryWrd);
            newResult._frequency = retPair.second;
            newResult._candidateWrd = retPair.first;
            
            _resultQue.push(newResult);
        }
    }
}

int WorkThreadTask::readNBytes(const char* ch)
{
    int byteNum = 1;
    int offset = 7;
    while ((*ch) & (1 << offset)) {
        --offset;
        ++byteNum;
    }
    if (byteNum > 1) {
        return byteNum - 1;
    }
    return byteNum; 
}

string WorkThreadTask::obtainResultJson(int resultNum)
{
    //Json::StyledWriter writerInfo;
    Json::FastWriter writerInfo;

    Json::Value root;

    for (int i = 0; i < resultNum; ++i) {
        if (_resultQue.empty()) { break; }
        Result tmp = _resultQue.top();
        _resultQue.pop();
        Json::Value resultValue;

        resultValue["Word"] = tmp._candidateWrd;
        resultValue["Frequency"] = (int)tmp._frequency;

        ostringstream oss;
        oss << "CandidateWord" << i;
        root[oss.str()] = resultValue;
    }

    return writerInfo.write(root);
}

}
