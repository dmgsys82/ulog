#ifndef IULOGCHANNELIMPL__H
#define IULOGCHANNELIMPL__H

#include <ulog/ulogBuffer.h>

using namespace std;

class IulogChannelImpl {

public:

    virtual void connect() = 0;

    virtual void disconnect() = 0;

    virtual void write(ulogMessage* msg) = 0;

    virtual ulogMessage* read() = 0;

};

#endif // end of IULOGCHANNELIMPL__H