#ifndef REQCONTAINERLIST__H
#define REQCONTAINERLIST__H

#include <ulog/ulogRequest.h>

using namespace std;

// reqContainerList è la richiesta dei container presenti sul server
struct reqContainerList: public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqContainerList() 
        :ulogRequest("",ulogMessageType::c_containerList) {
    }
        
    // Il costruttore principale
    // @param requestId                 Id richiesta
    reqContainerList(const string& requestId) 
        :ulogRequest(requestId,ulogMessageType::c_containerList) {

    }

    // PUBLIC METHODS //////////////////////////////////////////////////////////
        
    ulogMessage* clone() {
        reqContainerList* msg = new reqContainerList();
        return msg;
    }

};

#endif // end of REQCONTAINERLIST__H
