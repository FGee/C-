#include "TcpServer.h"
#include "threadPool.h"

#include <unistd.h>

#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace wd;

ThreadPool* gpThreadPool = nullptr;

class Task
{
public:
    Task(SPtrConn sp, const string& m)
        : _sptrConn(sp), _msg(m) {}

    void process()
    {
        cout << threadName << " >> decoding" << endl;
        _msg += "<<decode>>";

        cout << threadName << " >> computing" << endl;
        _msg += "<<compute>>";

        cout << threadName << " >> encoding" << endl;
        _msg += "<<encode>>";

        _sptrConn->sendInLoop(_msg);
    }
private:
    wd::SPtrConn _sptrConn;
    string _msg;
};

void doOnConnect(const SPtrConn spConn) {
    cout << spConn->toString() << endl;
    spConn->send(">> Welcome to server!");
}

void doOnMessage(const SPtrConn spConn) {
    string recvMsg = spConn->recv();
    cout << threadName << " >> Msg recv: " << recvMsg;

    gpThreadPool->addTask(bind(&::Task::process, ::Task(spConn, recvMsg)));
}

void doOnClose(const SPtrConn spConn) {
    cout << ">> " << spConn->toString() 
        << " had closed by peer edge!" << endl;
}

int main()
{
    ThreadPool threadPool(4, 2, "Work Thread(child thread)");
    threadPool.start();

    gpThreadPool = &threadPool;

    threadName = "IO Thread(main thread)";

    TcpServer server("192.168.198.131", 8888);

    server.setTcpOnConnectCallBack(doOnConnect);
    server.setTcpOnMessageCallBack(doOnMessage);
    server.setTcpOnCloseCallBack(doOnClose);

    server.start();

    return 0;
}

