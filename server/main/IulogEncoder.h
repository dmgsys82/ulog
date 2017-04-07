#ifndef IULOGSERIALIZATION__H
#define IULOGSERIALIZATION__H

#include <ulog/ulogMessage.h>
#include <ulog/ulogBuffer.h>

using namespace std;
using namespace Poco;

#pragma once

class IulogEncoder
{
    
public:

    virtual void serialize(const ulogMessage* msg, const ulogBuffer& trg) = 0;

    virtual ulogMessage* deserialize(const ulogBuffer& src) = 0;

};

#endif // end of IULOGSERIALIZATION__H