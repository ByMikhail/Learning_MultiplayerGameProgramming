//
// Created by Mikhail on 23.06.2021.
//

#include <WS2tcpip.h>
#include "SocketAddressFactory.hpp"

using std::string;
using std::make_shared;

SocketAddressPtr SocketAddressFactory::CreateIPv4FromString(const string &str)
{
    const auto hostPortSeparator = ':';
    auto separatorPosition = str.find_last_of(hostPortSeparator);

    string host, port;
    if (separatorPosition != string::npos) {
        host = str.substr(0, separatorPosition);
        port = str.substr(separatorPosition + 1);
    } else {
        host = str;
        port = "0";
    }

    addrinfo hint = {};
    hint.ai_family = AF_INET;

    addrinfo *info;
    int error = getaddrinfo(host.c_str(), port.c_str(), &hint, &info);
    if(error && info != nullptr)
    {
        freeaddrinfo(info);
        return nullptr;
    }

    while(!info->ai_addr && info->ai_next)
    {
        info = info->ai_next;
    }

    if(!info->ai_addr)
    {
        freeaddrinfo(info);
        return nullptr;
    }

    auto result = make_shared<SocketAddress>(*info->ai_addr);

    freeaddrinfo(info);

    return result;
}