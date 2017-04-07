#ifndef ULOGCHANNEL__H
#define ULOGCHANNEL__H

#include <ulog/ulogMessage.h>
#include <ulog/ulogRequest.h>
#include <ulog/ulogResponse.h>
#include <ulog/IulogChannelImpl.h>
#include <ulog/IulogMessageSerializer.h>

using namespace std;

class ulogChannel
{

    ulogChannel(IulogChannelImpl* channelImpl, IulogMessageSerializer* serializer) {
        _channelImpl = channelImpl;
        _serializer  = serializer;		
    }

    void connect();

    void disconnect();

    void send(ulogMessage* cmd);

    ulogMessage* receive();

private:

    IulogChannelImpl* _channelImpl;
    IulogMessageSerializer* _serializer;
};

#endif // end of ULOGCHANNEL__H