#include "TcpServer.h"

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
    TcpServer server("192.168.198.131", 8888);

    server.setTcpOnConnectCallBack(doOnConnect);
    server.setTcpOnMessageCallBack(doOnMessage);
    server.setTcpOnCloseCallBack(doOnClose);

    server.start();

    return 0;
}

