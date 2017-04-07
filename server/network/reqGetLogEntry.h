#ifndef REQGETLOGENTRY__H
#define REQGETLOGENTRY__H

#include <ulog/ulogRequest.h>
#include <ulog/logEntry.h>

using namespace std;

// reqGetLogEntry è la richiesta di recupero di una log entry
struct reqGetLogEntry : public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqGetLogEntry()
        :ulogRequest("",ulogMessageType::c_getLogEntry) {
    }
        
    // Il costruttore principale
    // @param requestId         L'id della richiesta
    // @param logEntryId        L'id del log entry
    reqGetLogEntry(const string& requestId, const string& logEntryId)
        :ulogRequest(requestId,ulogMessageType::c_getLogEntry) {
        _logEntryId = logEntryId;
    }

    /// PUBLIC METHODS /////////////////////////////////////////////////////////

    // Retrieve log entry id
    string logId() {
        return _logEntryId;
    }

    /// Update log entry id
    string entry(const string& logEntryId) {
        _logEntryId = logEntryId;
    }

    // Clone current object
    ulogMessage* clone() {
        reqGetLogEntry* cmd = new reqGetLogEntry();

        cmd->_logEntryId = _logEntryId;

        return cmd;
    }

private:

    string _logEntryId;         // log entry id

};

#endif // end of REQGETLOGENTRY__H