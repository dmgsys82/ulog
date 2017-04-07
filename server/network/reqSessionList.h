#ifndef REQSESSIONLIST__H
#define REQSESSIONLIST__H

#include <ulog/ulogRequest.h>

using namespace std;

// reqSessionList: è la richiesta di recupero elenco sessioni
struct reqSessionList:  public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqSessionList()
        :ulogRequest("",ulogMessageType::c_sessionList) {
    }

    // Il costruttore principale
    // @param requestId             Id richiesta
    reqSessionList(const string& requestId)
        :ulogRequest(requestId, ulogMessageType::c_sessionList) {        
    }
        
    // Clone current object
    ulogMessage* clone() {
        reqSessionList* cmd = new reqSessionList();
        return cmd;
    }
};

#endif // end of REQSESSIONLIST__H