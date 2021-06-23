//
// Created by Mikhail on 22.06.2021.
//

#pragma once

#include <iostream>
#include <WinSock2.h>

class SocketAddress
{
public:
    SocketAddress(uint32_t address, uint16_t port);
    SocketAddress(const sockaddr& sockaddr);
private:
    sockaddr m_SockAddr;
    sockaddr_in* GetAsSockAddrIn();
};

typedef std::shared_ptr<SocketAddress> SocketAddressPtr;