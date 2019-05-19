#include <log4cpp/Category.hh>//record
#include <log4cpp/BasicLayout.hh>// log formate
#include <log4cpp/Priority.hh>//record's priority or log priority
#include <log4cpp/OstreamAppender.hh> // the output target of log

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    using namespace log4cpp;

    OstreamAppender * pOstreamAppender = new OstreamAppender("OstreamAppender", &cout);
    pOstreamAppender->setLayout(new BasicLayout);

    Category & root = Category::getRoot(); //why use reference???

    root.addAppender(pOstreamAppender);
    
    root.setPriority(Priority::DEBUG);
    
    root.error("Hello log4cpp in a Error Message!");
    root.warn("Hello log4cpp int a Warning Message!");

    Category::shutdown();

    return 0;
}

