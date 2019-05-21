#ifndef __MY_LOG_H__
#define __MY_LOG_H__

#include <stdio.h>

#include <iostream>
#include <string>
#include <sstream>

#include <log4cpp/Category.hh>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using namespace log4cpp;

#define prefix(msg) (string("[").append(__FILE__)\
                     .append(": ").append(std::to_string(__LINE__))\
                     .append(": ").append(__FUNCTION__)\
                     .append("]").append(": ").append(msg))

#define LogDebug(msg) Mylog::getInstance()->debug(prefix(msg).c_str()) 

#define LogInfo(msg) Mylog::getInstance()->info(prefix(msg).c_str()) 

#define LogWarn(msg) Mylog::getInstance()->warn(prefix(msg).c_str()) 

#define LogError(msg) Mylog::getInstance()->error(prefix(msg).c_str()) 

namespace wd 
{
class Mylog
{
public:
    void warn(const char* msg);
    void error(const char* msg);
    void debug(const char* msg);
    void info(const char* msg);

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
}

#endif
