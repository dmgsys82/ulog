#ifndef ULOGERRORS__H
#define ULOGERRORS__H

#include <map>

using namespace std;

enum ulogErrorCode : int {
	errUnknow,
	errUnsupportedMessage,
        errInvalidMessage
};

// Create default message error
map<ulogErrorCode, string> defaultErrorMessages();

// Retrieve message error from error code
const string* errorMessage(ulogErrorCode errType);

static map<ulogErrorCode, string> _errorMessages = defaultErrorMessages();

#endif // end of ULOGERRORS__H