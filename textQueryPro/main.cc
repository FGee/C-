#include "query.h"

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while (true) {
        cout << ">>pls input the word you want to query: " << endl;;
        string wordQuery;
        if (!(cin >> wordQuery) || "q" == wordQuery) {
            break;
        }
        //Query resQuer = wordQuery;
        Query resQuer = ~Query("and")&Query("the")|Query("in");
        cout << resQuer.eval(tq);
    }
}

int main(int argc, char ** argv)
{
    ifstream ifs;
    ifs.open(argv[1], std::ios::out);
    runQueries(ifs);

    return 0;
}

