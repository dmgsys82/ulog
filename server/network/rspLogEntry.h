#ifndef RSPLOGENTRY__H
#define RSPLOGENTRY__H

#include <ulog/ulogResponse.h>
#include <ulog/logEntry.h>

using namespace std;

// rspLogEntry: la risposta alla richiesta di recupero di una log entry o di un
// elenco di log entry
struct rspLogEntry : public ulogResponse
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    rspLogEntry()
        :ulogResponse("",ulogMessageType::r_logEntry) {
    }
            
    // Il costruttore principale
    // @param requestId         RequestId originaria
    // @param entry             Log entry
    // @param last              Flag ultimo elemento        
    rspLogEntry(const string& requestId, const logEntry& entry, const bool last)
        :ulogResponse(requestId, ulogMessageType::r_logEntry, last) {
        _entry = entry;
    }

    // Il costruttore in caso di errore
    // @param requestId         RequestId originaria
    // @param errCode           Il codice di errore
    // @param errMessage        Il messaggio di errore
    rspLogEntry(const string& requestId, const int errCode, 
        const string& errMessage) 
        :ulogResponse(requestId, ulogMessageType::r_logEntry, errCode, 
        errMessage) {        
    }

    // PUBLIC METHODS //////////////////////////////////////////////////////////
    
    /// Retrieve log entry
    logEntry& entry() {
        return _entry;
    }

    /// Update log entry
    logEntry entry(const logEntry& entry) {
        return _entry = entry;
    }

    ulogMessage* clone() {
        rspLogEntry* obj = new rspLogEntry();
        obj->_entry = _entry;
        return obj;
    }

private:

    logEntry _entry;            // log entry

};

#endif // end of RSPLOGENTRY__H