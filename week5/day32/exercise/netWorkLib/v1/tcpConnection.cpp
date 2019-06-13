#include "tcpConnection.h"
#include "macro.h"

#include <sstream>

namespace wd
{

TcpConnection::TcpConnection(int acceptFd)
    : _acceptFd(acceptFd), _sockIO(acceptFd),
    _localInetAddr(getLocalInetAddr(acceptFd)),
    _peerInetAddr(getPeerInetAddr(acceptFd)),
    _isShutdownWrite(false) {}

InetAddress TcpConnection::getLocalInetAddr(int acceptFd)
{
    struct sockaddr_in tmp;
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = getsockname(acceptFd, (struct sockaddr*)&tmp, &len);
    if (-1 == ret) { ERROR_EXIT("getsockname"); }
    return InetAddress(tmp);
}

InetAddress TcpConnection::getPeerInetAddr(int acceptFd)
{
    struct sockaddr_in tmp;
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = getpeername(acceptFd, (struct sockaddr*)&tmp, &len);
    if (-1 == ret) { ERROR_EXIT("getsockname"); }
    return InetAddress(tmp);
}

string TcpConnection::recv()
{
    char buf[65536] = { 0 };
    _sockIO.readLine(buf, sizeof(buf));
    return string(buf);
}

void TcpConnection::send(const string& str)
{
    _sockIO.writeN(str.c_str(), str.size());
}

string TcpConnection::toString()
{
    ostringstream oss;
    oss << _localInetAddr.ip() << ":" << _localInetAddr.port()
        << "---->" 
        << _peerInetAddr.ip() << ":" << _peerInetAddr.port();
    return oss.str();
}

TcpConnection::~TcpConnection()
{
    if (!_isShutdownWrite) {
        _isShutdownWrite = true;
        _acceptFd.shutDownWrite();
    }
}

}
