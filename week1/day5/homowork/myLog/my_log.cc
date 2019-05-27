#include "my_log.h"

Mylog * Mylog::_pMylog = nullptr;

Mylog::Mylog() : _root(Category::getRoot().getInstance("RootName"))
{
    PatternLayout* pLayout1 = new PatternLayout();
    pLayout1->setConversionPattern("%d: %p %c %x: %m%n");
    PatternLayout* pLayout2 = new PatternLayout();
    pLayout2->setConversionPattern("%d: %p %c %x: %m%n");

    OstreamAppender* pOstreamAppender = new OstreamAppender("OstreamAppender", &cout);
    pOstreamAppender->setLayout(pLayout1);

    FileAppender* pFileAppender = new FileAppender("fileAppender", "my.log");
    pFileAppender->setLayout(pLayout2);

    _root.addAppender(pOstreamAppender);
    _root.addAppender(pFileAppender);
    _root.setPriority(Priority::DEBUG);

    cout << "Mylog()" << endl;
}

Mylog::~Mylog()
{
    Category::shutdown(); 
    cout << "~Mylog()" << endl;
}
