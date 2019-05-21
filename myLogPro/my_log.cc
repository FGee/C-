#include "my_log.h"
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

using namespace wd;

Mylog * Mylog::_pMylog = nullptr;

Mylog::Mylog() : _root(Category::getRoot().getInstance("RootName"))
{
    PatternLayout* pLayout1 = new PatternLayout();
    pLayout1->setConversionPattern("%d [%c] [%p] %m%n");
    PatternLayout* pLayout2 = new PatternLayout();
    pLayout2->setConversionPattern("%d [%c] [%p] %m%n");

    OstreamAppender* pOstreamAppender = new OstreamAppender("OstreamAppender", &cout);
    pOstreamAppender->setLayout(pLayout1);

    FileAppender* pFileAppender = new FileAppender("fileAppender", "my.log");
    pFileAppender->setLayout(pLayout2);

    _root.addAppender(pOstreamAppender);
    _root.addAppender(pFileAppender);
    _root.setPriority(Priority::DEBUG);

    cout << "Mylog()" << endl;
}

void Mylog::warn(const char* msg)
{
    _root.warn(msg);
}

void Mylog::debug(const char* msg)
{
    _root.debug(msg);
}

void Mylog::info(const char* msg)
{
    _root.info(msg);
}

void Mylog::error(const char* msg)
{
    _root.error(msg);
}

Mylog::~Mylog()
{
    Category::shutdown(); 
    cout << "~Mylog()" << endl;
}
