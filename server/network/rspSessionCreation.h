#ifndef RSPSESSIONCREATION__H
#define RSPSESSIONCREATION__H

#include <ulog/ulogResponse.h>

using namespace std;

// rspSessionCreation: è il messaggio di risposta alla richiesta di creazione
// di una nuova sessione
struct rspSessionCreation : public ulogResponse
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    rspSessionCreation()
        :ulogResponse("",ulogMessageType::r_sessionCreation) {
    }

    // Il costruttore principale
    // @param requestId                 RequestId originaria
    // @param sessionId                 SessionId create
    rspSessionCreation(const string& requestId, const string sessionId)
        :ulogResponse(requestId, ulogMessageType::r_sessionCreation) {
        _sessionId = sessionId;
    } 
    
    // Il costruttore in caso di errore
    // @param requestId                 RequestId originaria
    // @param errCode                   Il codice di errore
    // @param errMessage                Il messaggio di errore
    rspSessionCreation(const string& requestId, const int errCode,
        const string& errMessage)
        :ulogResponse(requestId, ulogMessageType::r_sessionCreation, errCode,
        errMessage) {       
    }
    
    // PUBLIC METHODS //////////////////////////////////////////////////////////
    
    /// Retrieve session id
    string sessionId() {
        return _sessionId;
    }

    /// Update session id
    string sessionId(const string& sessionId) {
        _sessionId = sessionId;
    }

    ulogMessage* clone() {
        rspSessionCreation* obj = new rspSessionCreation();
        obj->_sessionId = _sessionId;
        return obj;
    }

private:

    string _sessionId;              // session id

};

#endif // end of RSPSESSIONCREATION__H