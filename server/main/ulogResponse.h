#ifndef ULOGRESPONSE__H
#define ULOGRESPONSE__H

#include <string>
#include <ulog/ulogMessage.h>

using namespace std;

// ulogResponse: rappresenta un messaggio di risposta da parte del server ulog
// Viene usato per comunicare l'esito di una richiesta pervenuta dal client,
// sia nel caso di elaborazione completata con successo sia nel caso siano
// stati rilevati degli errori; nell'ultimo caso la struttura consente di 
// memorizzare il codice e il messaggio di errore
struct ulogResponse: public ulogMessage
{
    
public:
    
    // STRUCT CONSTRUCTORS /////////////////////////////////////////////////////

    // Il costruttore principale
    // @param requestId             La requestId originaria
    // @param type                  La tipologia di messaggio
    // @param lastItem              Il flag di last item
    ulogResponse(const string& requestId,ulogMessageType type,
        bool lastItem=false)
        :ulogResponse(requestId,type, lastItem, 0,"") {
    }
        
    // Il costruttore in caso di errori
    // @param requestId             La requestId originaria
    // @param type                  La tipologia di messaggio
    // @param errCode               Il codice di errore
    // @param errMessage            Il messaggio di errore
    ulogResponse(const string& requestId, const ulogMessageType type,
        const int errCode, const string& errMessage)
        :ulogResponse(requestId, type,errCode, errMessage) {
    }
    
    // PUBLIC METHODS //////////////////////////////////////////////////////////

    // Restituisce true se è l'ultimo elemento di una collection
    bool lastItem() {
        return _lastItem;
    }

    // Restituisce true se non è stato indicato alcun errore
    bool success() {
        return _errCode == 0;
    }

    // Restituisce l'eventuale messaggio di errore
    string errorMessage() {
        return _errMessage;
    }

    // Restituisce l'eventuale codice di errore
    int errorCode() {
        return _errCode;
    }

    // clone
    virtual ulogMessage* clone() = 0;

private:

    // Construttore privato: consente di impostare tutte le proprietà di un
    // messaggio di risposta di ulog
    // @param requestId         RequestId originaria
    // @param type              Tipologia messaggio
    // @param lastItem          Indica se il messaggio corrisponde a l'ultimo 
    //                          di una serie di messaggi di risposta
    // @param errCode           Eventuale codice di errore
    // @param errMessage        Eventuale messaggio di errore
    ulogResponse(const string& requestId, const ulogMessageType type,
        bool lastItem, const int errCode, const string& errMessage) 
        :ulogMessage(requestId, type) {
        _lastItem   = lastItem;
        _errCode    = errCode;
        _errMessage = errMessage;
    }
    
    bool    _lastItem;		// flag ultimo elemento
    string  _errMessage;        // messaggio di errore
    int     _errCode;		// codice di errore
	
};

#endif // end of ULOGRESPONSE__H