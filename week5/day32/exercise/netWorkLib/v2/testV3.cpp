#include "acceptor.h"
#include "eventLoop.h"
#include "tcpConnection.h"

#include <iostream>

using namespace std;
using namespace wd;

void doOnConnect(const SPtrConn spConn) {
    cout << spConn->toString() << endl;
    spConn->send(">> Welcome to server!");
}

void doOnMessage(const SPtrConn spConn) {
    string recvMsg = spConn->recv();
    cout << ">> Msg recv: " << recvMsg;
}

void doOnClose(const SPtrConn spConn) {
    cout << ">> " << spConn->toString() 
        << " had closed by peer edge!" << endl;
}

int main()
{
    Acceptor acc(8888);
    acc.ready();

    EventLoop eventLoop(acc);

    eventLoop.setOnConnect(doOnConnect);
    eventLoop.setOnMessage(doOnMessage);
    eventLoop.setOnClose(doOnClose);

    eventLoop.loop();

    return 0;
}

