#ifndef IULOGCHANNELLISTENERIMPL__H
#define IULOGCHANNELLISTENERIMPL__H

#include <ulog/IulogChannelImpl.h>

using namespace std;

class IulogChannelListenerImpl {

public:

    /// Stat channel listening
    virtual void open() = 0;

    /// Accept a channel
    virtual IULogChannelImpl* accept() = 0;

    /// Close channel
    virtual void close() = 0;

};

#endif // end of IULOGCHANNELLISTENERIMPL__H