#ifndef ULOGMESSAGE__H
#define ULOGMESSAGE__H

#include <string>

using namespace std;

enum ulogMessageType:int {
    c_createSession,
    r_sessionCreation,
    c_containerList,
    r_containerListItem,
    c_sessionList,
    r_sessionListItem,
    c_addLogEntry,
    r_logEntry,
    c_getLogEntry,
    c_queryLog,
    r_lockProfile,
    c_unlockProfile,
    r_profileLock,
    r_profileUnlock,
    c_createContainer,
    c_destroyContainer,
    r_containerCreation,
    r_containerDistruction
};

struct ulogMessage
{

public:

    ulogMessage(ulogMessageType msgType) {
        _msgType   = msgType;
    }
    
    ulogMessage(const string& requestId, ulogMessageType msgType) {
        _msgType = msgType;
        _requestId = requestId;
    }

    ulogMessageType msgType() {
        return _msgType;
    }

    string requestId() {
        return _requestId;
    }

    string requestId(string requestId) {
        return _requestId = requestId;
    }

    // Clone
    virtual ulogMessage* clone() = 0;

private:

    ulogMessageType _msgType;
    string          _requestId;

};

#endif // end of ULOGMESSAGE__H