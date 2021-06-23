//
// Created by Mikhail on 23.06.2021.
//

#pragma once
#include "SocketAddress.hpp"

class SocketAddressFactory
{
public:
    static SocketAddressPtr CreateIPv4FromString(const std::string& str);
};