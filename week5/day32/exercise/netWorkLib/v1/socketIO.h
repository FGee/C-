#pragma once

namespace wd
{

class SocketIO
{
public:
    SocketIO(int);
    void readN(char* buf, int len);
    void writeN(const char* buf, int len);
    void readLine(char* buf, int maxLen);
private:
    void recvPeer(char* buf, int Len);
    int _acceptFd;
};

}
