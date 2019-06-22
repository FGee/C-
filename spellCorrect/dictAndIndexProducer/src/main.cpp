#include "../include/macro.h"
#include "../include/configuration.h"
#include "../include/dictProducer.h"
#include "../include/cppJiebaSplitTool.h"
#include "../include/indexProducer.h"

#include <iostream>

using namespace wd;
using namespace std;

int main()
{

    Configuration::getInstance()->loadConfigFile("../conf/config.txt");
    
    //DictProducer dictPro;
    //dictPro.start();
    
    CppJiebaSplitTool cppJieba;

    DictProducer dictPro(&cppJieba);
    dictPro.start();

    IndexProducer indexProducer;
    indexProducer.produceIndex();

    return 0;
}

