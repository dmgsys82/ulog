#ifndef REQCREATESESSION__H
#define REQCREATESESSION__H

#include <ulog/ulogRequest.h>

using namespace std;

// reqCreateSession è la richiesta di creazione di una nuova sessione
struct reqCreateSession : public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqCreateSession() 
        :ulogRequest("",ulogMessageType::c_createSession) {
    }
        
    // Il costruttore principale
    // @param requestId             L'id della richiesta
    // @param applicationId         L'id della applicazione
    // @param containerId           L'id del container
    // @param configuration         La configurazione in XML
    // @param targetSystemId        L'id del target system
    reqCreateSession(const string &requestId, const string& applicationId, 
        const string& containerId, const string& configuration,  
        const string& targetSystemId)
        :ulogRequest(requestId,ulogMessageType::c_createSession) {  
        
        _applicationId  = applicationId;
        _containerId    = containerId;
        _configuration  = configuration;
        _targetSystem   = targetSystemId;
    }

    /// PUBLIC METHODS /////////////////////////////////////////////////////////

    /// Update application id
    string application(const string& applicationId) {
        return _applicationId = applicationId;
    }

    /// Retrieve application id
    string application() {
        return _applicationId;
    }

    /// Retrieve container
    string container() {
        return _containerId;
    }

    /// Update container
    string container(const string& containerId) {
        return _containerId = containerId;
    }

    /// Retrieve configuration
    string configuration() {
        return _configuration;
    }

    /// Update configuration
    string configuration(const string& configuration) {
        return _configuration = configuration;
    }

    /// Retrieve target system
    string targetSystem() {
        return _targetSystem;
    }

    /// Update target system
    string targetSystem(const string& targetSystem) {
        return _targetSystem = targetSystem;
    }

    // Clone current object
    ulogMessage* clone() {
        reqCreateSession *cmd = new reqCreateSession();

        cmd->_applicationId = _applicationId;
        cmd->_configuration = _configuration;
        cmd->_targetSystem  = _targetSystem;
        cmd->_containerId   = _containerId;

        return cmd;
    }

private:

    string _applicationId;	// application id
    string _containerId;        // container
    string _configuration;	// configuration
    string _targetSystem;	// target system

};

#endif // end of REQCREATESESSION__H