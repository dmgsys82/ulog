#ifndef IULOGSERIALIZER__H
#define IULOGSERIALIZER__H

#include <ulog/ulogMessage.h>
#include <ulog/ulogBuffer.h>

using namespace std;


class IulogMessageSerializer
{

public: 

    /// Serialize a ulog message to target buffer
    virtual bool serialize(ulogBuffer* buf,ulogMessage* msg) = 0;

    /// Deserialize a ulog message from source buffer
    virtual bool deserialize(ulogBuffer* buf,ulogMessage* msg) = 0;

    /// Retrieve message type
    virtual ulogMessageType msgType() = 0;
};

#endif // end of IULOGSERIALIZER__H