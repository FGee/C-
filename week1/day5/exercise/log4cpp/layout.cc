#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

using std::cout;
using std::endl;
using namespace log4cpp;

int main(int argc, char ** argv)
{
    OstreamAppender* osAppender = new OstreamAppender("osAppender", &cout);
    
    PatternLayout* pLayout = new PatternLayout();
    pLayout->setConversionPattern("%d: %p %c %x %m: %m%n");
    osAppender->setLayout(pLayout);

    Category & root = Category::getRoot();
    Category & infoCategory = root.getInstance("infoCategory");
    infoCategory.addAppender(osAppender);
    infoCategory.setPriority(Priority::INFO);
    
    infoCategory.info("system is running");
    infoCategory.warn("system has a warning");
    infoCategory.error("system has a error, can't find a file");
    infoCategory.fatal("system has a fatal error, must be shutdown");
    infoCategory.info("system shutdown, you can find some information in system in systemlog");

    Category::shutdown();

    return 0;
}
