//
// Created by Mikhail on 22.06.2021.
//

#include "SocketAddress.hpp"

SocketAddress::SocketAddress(uint32_t address, uint16_t port)
{
    GetAsSockAddrIn()->sin_family = AF_INET;
    GetAsSockAddrIn()->sin_addr.S_un.S_addr = htonl(address);
    GetAsSockAddrIn()->sin_port = htons(port);
}

SocketAddress::SocketAddress(const sockaddr &sockaddr)
{
    memcpy(&m_SockAddr, &sockaddr, GetSize());
}

size_t SocketAddress::GetSize() const
{
    return sizeof(sockaddr);
}

sockaddr_in * SocketAddress::GetAsSockAddrIn()
{
    return reinterpret_cast<sockaddr_in*>(&m_SockAddr);
}