#ifndef REQADDLOGENTRY__H
#define REQADDLOGENTRY__H

#include <ulog/ulogRequest.h>
#include <ulog/logEntry.h>

using namespace std;

// reqAddLogEntry: è il comando di aggiunta di un entry al log
struct reqAddLogEntry: public ulogRequest
{

public:

    /// STRUCT CONSTRUCTOR /////////////////////////////////////////////////////

    reqAddLogEntry()
        :ulogRequest("",ulogMessageType::c_addLogEntry) {
    }
        
    // Il costruttore principale
    // @param requestId             Id della richiesta
    // @param entry                 Log entry        
    reqAddLogEntry(const string& requestId, const logEntry& entry) 
        :ulogRequest(requestId, ulogMessageType::c_addLogEntry) {     
        _entry = entry;
    }
    
    /// PUBLIC METHODS /////////////////////////////////////////////////////////

    /// Retrieve log entry
    logEntry entry() {
        return _entry;
    }

    /// Clone method
    virtual ulogMessage* clone() {
        reqAddLogEntry* obj = new reqAddLogEntry();

        obj->_entry = _entry;

        return obj;
    }

    logEntry	_entry;         // log entry

};

#endif // end of REQADDLOGENTRY__H

