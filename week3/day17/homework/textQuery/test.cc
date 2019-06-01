#include "text_query.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char ** argv)
{
    string queryWrd(argv[1]);

    TextQuery tq;
    tq.readFile("china_daily.txt");
    
    tq.query(queryWrd);

    return 0;
}

