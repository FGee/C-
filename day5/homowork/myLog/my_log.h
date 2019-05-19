#ifndef __MY_LOG_H__
#define __MY_LOG_H__

#include <stdio.h>

#include <iostream>
#include <string>
#include <sstream>

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

#define __func_info_ __FILE__,__LINE__,__func__

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using namespace log4cpp;

class Mylog
{
public:
    void warn(const char * msg, const char* file, const int& line, const char* func)
    {
        string _tempStr;
        ostringstream oss;
        oss << "file: " << file << " line: " << line << " func: " << func << ": " << msg;
        _tempStr = oss.str();
        _root.warn(_tempStr.c_str());
    }
    void error(const char * msg, const char* file, const int& line, const char* func)
    {
        string _tempStr;
        ostringstream oss;
        oss << "file: " << file << " line: " << line << " func: " << func << ": " << msg;
        _tempStr = oss.str();
        _root.error(_tempStr.c_str());
    }
    void debug(const char * msg, const char* file, const int& line, const char* func)
    {
        string _tempStr;
        ostringstream oss;
        oss << "file: " << file << " line: " << line << " func: " << func << ": " << msg;
        _tempStr = oss.str();
        _root.debug(_tempStr.c_str());
    }
    void info(const char * msg, const char* file, const int& line, const char* func)
    {
        string _tempStr;
        ostringstream oss;
        oss << "file: " << file << " line: " << line << " func: " << func << ": " << msg;
        _tempStr = oss.str();
        _root.info(_tempStr.c_str());
    }

    static Mylog* getInstance() 
    {
        if (nullptr == _pMylog) {
            _pMylog = new Mylog;
        }
        return _pMylog;
    }

    static void destory()
    {
        if (nullptr != _pMylog) {
            delete _pMylog;
        }
    }

private:
    const char* getInfo(const char* msg);
    Mylog();
    ~Mylog();
private:
    Category& _root;
    static Mylog* _pMylog;
};

#endif
