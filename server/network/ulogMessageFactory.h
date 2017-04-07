#ifndef ULOGMESSAGEFACTORY__H
#define ULOGMESSAGEFACTORY__H

#include <ulog/ulogRequests.h>
#include <ulog/ulogResponses.h>
#include <ulog/ulogErrors.h>
#include <ulog/exceptions/unsupportedMessage.h>
#include <Poco/Types.h>
#include <map>

using namespace std;
using namespace Poco;

class ulogMessageFactory {

public: 

    // Default class constructor
    ulogMessageFactory();

    // Class distructor
    ~ulogMessageFactory();

    // Create a instance of a specific response message
    ulogMessage* createMessage(ulogMessageType t, const string& rid);
    
private:

    // PRIVATE METHODS /////////////////////////////////////////////////////////

    // initialize message prototypes
    void initMessagePrototypes();

    // destroy message prototypes
    void doneMessagePrototypes();

    // CLASS FIELDS ////////////////////////////////////////////////////////////

    // map of message types
    map<ulogMessageType, ulogMessage*> _messages;
        
    void prototype(map<ulogMessageType, ulogMessage*> &map, ulogMessage* m);

};

#endif // end of ULOGMESSAGEFACTORY__H