#ifndef ULOGEXCEPTION__H
#define ULOGEXCEPTION__H

#include <exception>
#include <ulog/ulogErrors.h>

using namespace std;

class ulogException : public exception  {

public:

    /// Main constructor
    ulogException(ulogErrorCode error) {
        _error = error;
    }

    /// Retrieve error code
    ulogErrorCode code() {
        return _error;
    }

    /// Retrive message error
    virtual const char* what() = 0;

private:
	
    ulogErrorCode _error;

};

#endif // end of ULOGEXCEPTION__H