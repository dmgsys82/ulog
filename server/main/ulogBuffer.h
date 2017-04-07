#ifndef ULOGBUFFER__H
#define ULOGBUFFER__H

////////////////////////////////////////////////////////////////////////////////
//
//
// ULog Buffer
// Si occupa della gestione dei buffer di supporto per l'invio e la ricezione 
// comandi tra client e server
//
//
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <Poco/Foundation.h>
#include <Poco/Types.h>

using namespace std;
using namespace Poco;

class ulogBuffer
{

public:

    /// CLASS CONSTRUCTORS /////////////////////////////////////////////////////

    /// Constructor 
    /// @capactiy			Max size of buffer
    ulogBuffer(int capacity);

    ulogBuffer(Int8* buffer, int size);

    /// Distructor
    ~ulogBuffer();

    /// PUBLIC METHODS /////////////////////////////////////////////////////////

    /// Retrieve current position
    int position();

    /// Retrieve current size of buffer
    int size();

    /// Retrive capacity of buffer
    int capacity();

    /// Write a 8 bit integer
    void insertInt8(Int8 value);

    /// Write a 16 bit integer
    void insertInt16(Int16 value);

    /// Insert a 32 bit integer
    void insertInt32(Int32 value);
    
    /// Insert a string
    void insertString(const string& value);

    /// Extract a 8 bit integer
    Int8 extractInt8();

    /// Extract a 16 bit integer
    Int16 extractInt16();

    /// Extract a 32 bit integer
    Int32 extractInt32();

    /// Extract a string
    string extractString();

private:

    /// Check if data of contentSize byte can be stored in to buffer
    inline bool checkBounds(int contentSize);

    Int8* _buffer;			// internal buffer
    int	_capacity;			// total capacity of buffer
    int	_size;				// current size of buffer
    int	_position;			// current position

};

#endif // end of ULOGBUFFER__H