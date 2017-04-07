#include "ulogErrors.h"

// init default error messages
map<ulogErrorCode, string> defaultErrorMessages() {
    map<ulogErrorCode, string> messages;

    messages[errUnsupportedMessage] = 
        "Message type (id: %d) unsupported. You asked for non existant or " \
        "not compatibile with current operation message type";
    return messages;
}

// retrieve error message from type
const string* errorMessage(ulogErrorCode errType) {
    const string* errMessage;

    if (_errorMessages.find(errType) != _errorMessages.end()) {
        errMessage = &_errorMessages[errType];
    }
    else {
        errMessage = &_errorMessages[ulogErrorCode::errUnknow];
    }

    return errMessage;
}
