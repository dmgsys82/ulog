#ifndef RSPAPPLICATIONUNLOCK__H
#define RSPAPPLICATIONUNLOCK__H

#include <ulog/ulogResponse.h>

using namespace std;

// rspProfileUnlock: è il messaggio di risposta alla richiesta di rilascio di 
// un profilo
struct rspProfileUnlock : public ulogResponse
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    rspProfileUnlock()
        :ulogResponse("",ulogMessageType::r_profileUnlock) { /* empty body */ }

    // Il costruttore principale
    // @param requestId             RequestId originaria
    // @param profileId             ProfileId 
    rspProfileUnlock(const string& requestId, const string& profileId)
        :ulogResponse(requestId, ulogMessageType::r_profileUnlock) 
    {
        _profileId = profileId;
    }       
    
    // Il costruttore in caso di errore
    // @param requestId             RequestId originaria
    // @param errCode               Codice di errore
    // @param errMessagge           Messaggio di errore    
    rspProfileUnlock(const string& requestId, const int errCode, 
        const string& errMessage)
        :ulogResponse(requestId, ulogMessageType::r_profileUnlock,
        errCode, errMessage) 
    { 
        /* emtpy body */ 
    }
    
    // PUBLIC METHODS //////////////////////////////////////////////////////////
    
    /// Update application id
    string profileId(const string& applicationId) 
    {
        return _profileId = applicationId;
    }

    /// Retrieve application id
    string profileId() 
    {
        return _profileId;
    }

    // Clone current object
    ulogMessage* clone() 
    {
        rspProfileUnlock* obj = new rspProfileUnlock();
        obj->_profileId = _profileId;
        return obj;
    }

private:

    string _profileId;          // application id

};

#endif // end of RSPAPPLICATIONUNLOCK__H