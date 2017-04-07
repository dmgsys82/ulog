#ifndef ULOGREQUEST__H
#define ULOGREQUEST__H

#include <string>
#include <ulog/ulogMessage.h>

using namespace std;

/// Class ULogRequest rappresent a request to ULogServer
struct ulogRequest: public ulogMessage
{

protected:

    /// CLASS CONSTRUCTOR /////////////////////////////////////////////////////////////////////////////////////////////

    ulogRequest(ulogMessageType msgType)
        :ulogMessage(msgType) {
    }
        
    ulogRequest(const string& requestId, const ulogMessageType msgType)
        :ulogMessage(requestId, msgType) {

    }

};

#endif // end of ULOGREQUEST__H