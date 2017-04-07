#ifndef RSPCONTAINERDISTRUCTION__H
#define RSPCONTAINERDISTRUCTION__H

#include <ulog/ulogResponse.h>

using namespace std;

// rspContainerDistruction: il messaggio di risposta alla richiesta di 
// rimozione di un container
struct rspContainerDistruction : public ulogResponse
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    rspContainerDistruction()
        :ulogResponse("",ulogMessageType::r_containerDistruction) {	
    }

    // Il costruttore principale
    // @param requestId         RequestId originaria
    // @param containerId       Il container id
    rspContainerDistruction(const string& requestId, const string& containerId)
        :ulogResponse(requestId, ulogMessageType::r_containerDistruction) {
        _containerId = containerId;
    }
    
    // Il costruttore in caso di errore
    // @param requestId         RequestId originaria
    // @param errCode           Il codice di errore
    // @param errMessage        Il messaggio di errore
    rspContainerDistruction(const string& requestId, const int errCode, 
        const string& errMessage) 
        :ulogResponse(requestId, ulogMessageType::r_containerDistruction,
        errCode, errMessage) {
    }
    
    /// Retrieve container id
    string& containerId() {
        return _containerId;
    }

    /// Update container id
    string containerId(const string& containerId) {
        _containerId = containerId;
    }

    ulogMessage* clone() {
        rspContainerDistruction* obj = new rspContainerDistruction();
        obj->_containerId = _containerId;
        return obj;
    }

private:

    string _containerId;            // container distruction


};

#endif // end of RSPCONTAINERDISTRUCTION__H