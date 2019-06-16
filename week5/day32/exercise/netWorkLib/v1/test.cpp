#include <iostream>
#include "acceptor.h"
#include "tcpConnection.h"

using namespace std;
using namespace wd;

int main()
{
    Acceptor acc(8888);
    acc.ready();

    TcpConnection conn(acc.accept());

    cout << conn.toString() << " has connected!" << endl;
    conn.send("welcome to server.");
    cout << "client data: ";
    cout << conn.recv();

    return 0;
}

