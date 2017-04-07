#ifndef REQLOCKAPPLICATION__H
#define REQLOCKAPPLICATION__H

#include <ulog/ulogRequest.h>

using namespace std;

// reqLockProfile è la richiesta di lock di un profilo
struct reqLockProfile: public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqLockProfile()
        :ulogRequest("",ulogMessageType::r_lockProfile) {
    }
        
    // Costruttore principale
    // @param requestId                 Id richiesta
    // @param profileId                 Id profilo
    reqLockProfile(const string& requestId, const string& profileId)
        :ulogRequest(requestId, ulogMessageType::r_lockProfile) {
        _profileId = profileId;
    }

    /// ACCESSORS //////////////////////////////////////////////////////////////

    /// Retrieve application id
    string applicationId() {
        return _profileId;
    }

    /// Update application id
    string profileId(const string& profileId) {
        return _profileId = profileId;
    }

    /// Clone current object
    ulogMessage* clone() {
        reqLockProfile* cmd = new reqLockProfile();

        cmd->_profileId = _profileId;

        return cmd;
    }

private:

    string _profileId;          // application id
	
};

#endif // end of REQLOCKAPPLICATION__H

