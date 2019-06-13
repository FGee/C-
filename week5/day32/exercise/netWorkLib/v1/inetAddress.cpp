#include "inetAddress.h"

namespace wd
{

InetAddress::InetAddress(const string& ip, const unsigned short& port)
: _addr()
{
    _addr.sin_family = AF_INET;
    _addr.sin_addr.s_addr = inet_addr(ip.c_str());
    _addr.sin_port = htons(port);
}

InetAddress::InetAddress(const struct sockaddr_in& addr)
: _addr(addr) {}

string InetAddress::ip() const
{
    return inet_ntoa(_addr.sin_addr);
}

unsigned short InetAddress::port() const
{
    return ntohs(_addr.sin_port);
}

struct sockaddr_in* sockaddrInPtrGet()
{
    return &_addr;
}

}
