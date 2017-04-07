#ifndef REQCREATECONTAINER__H
#define REQCREATECONTAINER__H

#include <ulog/ulogRequest.h>

using namespace std;

// reqCreateContainer: è la richiesta di creazione di un nuovo container 
struct reqCreateContainer: public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqCreateContainer()
        :ulogRequest("",ulogMessageType::c_createContainer) {
    }
        
    // Il costruttore principale
    // @param requestId                 Id richiesta
    // @param containerId               Id container richiesto
    reqCreateContainer(const string& requestId, const string& containerId)
        :ulogRequest(requestId,ulogMessageType::c_createContainer) {   
        _containerId = containerId;
    }

    /// PUBLIC METHODS /////////////////////////////////////////////////////////

    /// Retrieve container id
    string containerId() {
        return _containerId;
    }

    // Clone current object
    ulogMessage* clone() {
        reqCreateContainer* obj = new reqCreateContainer();
        obj->_containerId = _containerId;
        return obj;
    }
private:

    string _containerId;        // container id

};

#endif // end of REQCREATECONTAINER__H

