#ifndef REQUNLOCKAPPLICATION__H
#define REQUNLOCKAPPLICATION__H

#include <ulog/ulogRequest.h>

using namespace std;

// reqUnlockProfile è la richiesta di rilascio di un profilo
struct reqUnlockProfile: public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqUnlockProfile()
        :ulogRequest("",ulogMessageType::c_unlockProfile) {
    }

    reqUnlockProfile(const string& requestId, const string& profileId)
        :ulogRequest(requestId, ulogMessageType::c_unlockProfile) {
        _profileId = profileId;    
    }
    
    /// ACCESSORS //////////////////////////////////////////////////////////////

    /// Update application id
    string profileId() {
        return _profileId;
    }

    /// Retrieve application id
    string profileId(const string& profileId) {
        return _profileId = profileId;
    }

    // Clone current object
    ulogMessage* clone() {
        reqUnlockProfile* cmd = new reqUnlockProfile();        
        cmd->_profileId = _profileId;
        return cmd;
    }

private:

    string _profileId;

};

#endif // end of REQUNLOCKAPPLICATION__H