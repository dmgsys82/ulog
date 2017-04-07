#ifndef REQDESTROYCONTAINER__H
#define REQDESTROYCONTAINER__H

#include <ulog/ulogRequest.h>

using namespace std;

// reqDestroyContainer: la richiesta di distruzione di un container
struct reqDestroyContainer: public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqDestroyContainer()
        :ulogRequest("",ulogMessageType::c_destroyContainer) {
    }

    // Costruttore principale
    // @param requestId                 L'id della richiesta
    // @param containterId              L'id del contenitore 
    reqDestroyContainer(const string& requestId, const string& containerId) 
        :ulogRequest(requestId,ulogMessageType::c_destroyContainer) {   
        _containerId = containerId;
    }
    /// PUBLIC METHODS /////////////////////////////////////////////////////////

    /// Retrieve container id
    string containerId() {
        return _containerId;
    }

    /// Update container id
    string containerId(const string& containerId) {
        return _containerId = containerId;
    }

    // Clone current object
    ulogMessage* clone() {
        reqDestroyContainer* cmd = new reqDestroyContainer();

        cmd->_containerId = _containerId;

        return cmd;
    }

private: 

    string _containerId;        // container id

};

#endif // end of REQDESTROYCONTAINER__H

