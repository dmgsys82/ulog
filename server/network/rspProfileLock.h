#ifndef RSPAPPLICATIONLOCK__H
#define RSPAPPLICATIONLOCK__H

#include <ulog/ulogResponse.h>

using namespace std;

// rspProfileLock: E' il messaggio di risposta alla richiesta di lock di un 
// profilo
struct rspProfileLock : public ulogResponse
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    rspProfileLock()
        :ulogResponse("", ulogMessageType::r_profileLock) {
    }
        
    // Il costruttore principale
    // @param requestId             RequestId originaria
    // @param profileId             ProfileId
    rspProfileLock(const string& requestId, const string& profileId)
        :ulogResponse(requestId, ulogMessageType::r_profileLock) {
        _profileId = profileId;
    }

    // Il costruttore in caso di errore
    // @param requestId             RequestId originaria
    // @param errCode               Il codice di errore
    // @param errMessage            Il messaggio di errore
    rspProfileLock(const string& requestId, const int errCode, 
       const string& errMessage)
        :ulogResponse(requestId, ulogMessageType::r_profileLock,
        errCode, errMessage) {
        
    }
        
    // PULIC METHODS ///////////////////////////////////////////////////////////
    
    /// Update application id
    string profileId(const string& profileId) {
        return _profileId = profileId;
    }

    /// Retrieve application id
    string profileId() {
        return _profileId;
    }

    // Clone current object
    ulogMessage* clone() {
        rspProfileLock* obj = new rspProfileLock();
        obj->_profileId = _profileId;
        return obj;
    }

private:

    string _profileId;          // application id

};

#endif // end of RSPAPPLICATIONLOCK__H