#ifndef ULOGCHANNELLISTENER__H
#define ULOGCHANNELLISTENER__H

#include <ulog/IulogChannelListenerImpl.h>
#include <ulog/IulogChannelImpl.h>
#include <ulog/ulogChannel.h>

using namespace std;

class ulogChannelListener {

public:

    ulogChannelListener(IULogChannelListenerImpl* impl) {
        _listerImpl = impl;
    }

    void open() {
        _listerImpl->open();
    }


    void close() {
        _listerImpl->close();
    }

    ulogChannel* accept() {
        ulogChannel* channel = NULL;

        IULogChannelImpl* channelImpl = _listerImpl->accept();
        if (channelImpl != NULL) {
            channel = new ulogChannel(channelImpl);
        }

        return channel;
    }

private:
    
    IULogChannelListenerImpl* _listerImpl;	
    
};

#endif // end of ULOGCHANNELLISTENER__H