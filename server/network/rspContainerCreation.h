#ifndef RSPCONTAINERCREATION__H
#define RSPCONTAINERCREATION__H

#include <ulog/ulogResponse.h>

using namespace std;

// rspContainerCreation: è il messaggio di risposta alla richiesta di creazione
// di un container 
struct rspContainerCreation : public ulogResponse
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    rspContainerCreation()
        :ulogResponse("",ulogMessageType::r_containerCreation) {
    }

    // Il costruttore principale
    // @param requestId         RequestId originaria
    // @param containerId       ContainerId creato
    rspContainerCreation(const string& requestId, const string& containerId)
        :ulogResponse(requestId,ulogMessageType::r_containerCreation) {
        _containerId = containerId;
    }
    
    // Il costrutorre che deve essere richiamato in caso di errore
    // @param requestId         RequestId originaria
    // @param errCode           Codice errore
    // @param errMessage        Messaggio errore
    rspContainerCreation(const string& requestId, const int errCode, 
    const string& errMessage) 
        :ulogResponse(requestId, ulogMessageType::r_containerCreation,
        errCode, errMessage) {    
    }
    
    // PUBLIC METHODS //////////////////////////////////////////////////////////
    
    /// Retrieve container id
    string containerId() {
        return _containerId;
    }

    /// Update container id
    string containerId(const string& containerId) {
        return _containerId = containerId;
    }

    ulogMessage* clone() {
        rspContainerCreation* obj = new rspContainerCreation();
        obj->_containerId = _containerId;
        return obj;
    }

private:

    string _containerId;            // container id


};

#endif // end of RSPCONTAINERCREATION__H