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

using std::cout;
using std::endl;
using std::string;
using namespace log4cpp;

class Mylog
{
public:
    void warn(const char * msg)
    {
        _root.warn(getInfo(msg));
    }
    void error(const char * msg)
    {
        _root.error(getInfo(msg));
    }
    void debug(const char * msg)
    {
        _root.debug(getInfo(msg));
    }
    void info(const char * msg)
    {
        _root.info(getInfo(msg));
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
    string _tempStr;
};

//Mylog * Mylog::_pMylog = nullptr;

#endif
