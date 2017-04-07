#ifndef UNSUPPORTEDMESSAGE__H
#define UNSUPPORTEDMESSAGE__H

#include <exception>
#include <string>
#include <stdlib.h>
#include <ulog/ulogErrors.h>
#include <ulog/ulogException.h>

using namespace std;

class unsupportedMessage : public ulogException {

public:
	
    unsupportedMessage(int requiredTypeId) 
        :ulogException(ulogErrorCode::errUnsupportedMessage) {
        _requiredType = requiredTypeId;
    }

    virtual const char* what() {
        sprintf(_message, 
            errorMessage(ulogErrorCode::errUnsupportedMessage), 
            _requiredType
        );
        return _message;
    }

private:

    int _requiredType;		// message type requested
    char _message[200];         // error message

};

#endif // end of UNSUPPORTEDMESSAGE__H