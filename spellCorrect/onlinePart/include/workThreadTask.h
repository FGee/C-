#pragma once
#include "result.h"

#include <string.h>

#include <memory>
#include <queue>
#include <iostream>

#define RESULT_NUM 3

using namespace std;

namespace wd
{

class TcpConnection;

class WorkThreadTask
{
    struct ResultComparator {
        bool operator()(const Result& lhs, const Result& rhs) {
            if (lhs._editLenth != rhs._editLenth) {
                return lhs._editLenth > rhs._editLenth;
            } else if (lhs._frequency != rhs._frequency) {
                return lhs._frequency < rhs._frequency;
            } else {
                int ret = strcmp(lhs._candidateWrd.c_str(), rhs._candidateWrd.c_str());
                if (ret > 0) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    };

public:
    WorkThreadTask(shared_ptr<TcpConnection>, const string&);

    void process();
private:
    string jsonToQueryWrd(const string&);
    size_t minEditDistance(const string& src, const string& dest);
    void matchWrdIntoResult(const string& wrd);
    int readNBytes(const char* ch);

    string obtainResultJson(int);

    shared_ptr<TcpConnection> _sptrConn;
    string _msg;
    priority_queue<Result, vector<Result>, WorkThreadTask::ResultComparator> _resultQue;
};

}
