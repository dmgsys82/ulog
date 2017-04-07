#ifndef RSPSESSIONLISTITEM__H
#define RSPSESSIONLISTITEM__H

#include <ulog/ulogResponse.h>

using namespace std;

// rspProfileListItem: è la risposta della richiesta di recupero elenco profili
struct rspProfileListItem : public ulogResponse
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    rspProfileListItem()
        :ulogResponse("",ulogMessageType::r_sessionListItem) {
    }

    // Il costruttore principale
    // @param requestId             RequestId originaria
    // @param profileId             ProfileId
    // @param last                  Flag ultimo elemento
    rspProfileListItem(const string& requestId, const string& applicationId,
        const string& profileId, const bool last)
        :ulogResponse(requestId,ulogMessageType::r_sessionListItem, last) {
        _applicationId  = applicationId;
        _profileId      = profileId;       
    }
    
    // Il costruttore in caso di errore
    // @param requestId             RequestId originaria
    // @param errCode               Codice di errore 
    // @param errMessage            Messaggio di errore
    rspProfileListItem(const string& requestId, const int errCode, 
       const string& errMessage)
        :ulogResponse(requestId, ulogMessageType::r_sessionListItem,
        errCode, errMessage) {        
    }
    
    // PUBLIC METHODS //////////////////////////////////////////////////////////
    
    /// Retrieve application id
    string applicationId() {
        return _applicationId;
    }

    /// Update application id
    string applicationId(const string& applicationId) {
        _applicationId = applicationId;
    }

    /// Retrieve session id
    string profileId() {
        return _profileId;
    }

    /// Update session id
    string profileId(const string& sessionId) {
        return _profileId = sessionId;
    }

    // clone current object
    ulogMessage* clone() {
        rspProfileListItem* obj = new rspProfileListItem();
        obj->_profileId = _profileId;
        obj->_applicationId = _applicationId;
        return obj;
    }

private:

    string _applicationId;          // application id
    string _profileId;              // session id

};

#endif // end of RSPSESSIONLISTITEM__H