#ifndef RSPCONTAINERLISTITEM__H
#define RSPCONTAINERLISTITEM__H

#include <ulog/ulogResponse.h>

using namespace std;

// rspContainerListItem: è il messaggio di risposta alla richiesta di recupero
// elenco container
struct rspContainerListItem : public ulogResponse
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////    
    
    rspContainerListItem()
        :ulogResponse("",ulogMessageType::r_containerListItem) {
    }

    // Il costruttore principale
    // @param requestId         RequestId originaria
    // @param containerId       Il containerId 
    // @param last              Flag ultimo elemento
    rspContainerListItem(const string& requestId, const string& containerId,
        bool const last)
        :ulogResponse(requestId, ulogMessageType::r_containerListItem,last) {
        _containerId = containerId;
    }
    
    // Il costruttore in caso di errore
    // @param errCode           Il codice di errore
    // @param errMessage        Il messaggio di errore
    rspContainerListItem(const string& requestId, const int errCode,
       const string& errMessage)
       :ulogResponse(requestId, ulogMessageType::r_containerListItem,
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
        rspContainerListItem* obj = new rspContainerListItem();
        obj->_containerId = _containerId;
        return obj;
    }

private:

    string _containerId;                // container id

};

#endif // end of RSPCONTAINERLISTITEM__H