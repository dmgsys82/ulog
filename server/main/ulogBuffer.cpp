#include "ulogBuffer.h"
#include <Poco/ByteOrder.h>
#include <cstdlib>

ulogBuffer::ulogBuffer(int capacity)
{
    _capacity = capacity;
    _buffer   = (Int8*) malloc(capacity);
    _position = 0;
    _size     = 0;
}

ulogBuffer::ulogBuffer(Int8* buffer, int size)
{
    _capacity = size;
    _buffer   = buffer;
    _position = 0;
    _size     = size;
}

ulogBuffer::~ulogBuffer()
{
    free(_buffer);
}

int ulogBuffer::size() {
    return _size;
}

int ulogBuffer::position() {
    return _position;
}

int ulogBuffer::capacity() {
    return _capacity;
}

void ulogBuffer::insertInt16(Int16 value) {
    if (checkBounds(2)) {

        Int16 nvalue = ByteOrder::toNetwork(value);

        _buffer[_position++] = nvalue & 0xFF00;
        _buffer[_position++] = nvalue & 0x00FF;

        _size = _position;
    }	
}

void ulogBuffer::insertInt8(Int8 value) {
    if (checkBounds(1)) {
        _buffer[_position++] = value;
        _size = _position;
    }
}

void ulogBuffer::insertInt32(Int32 value) {
    if (checkBounds(4)) {
        Int32 nValue = ByteOrder::toNetwork(value);

        _buffer[_position++] = nValue & 0xFF000000;
        _buffer[_position++] = nValue & 0x00FF0000;
        _buffer[_position++] = nValue & 0x0000FF00;
        _buffer[_position++] = nValue & 0x000000FF;

        _size = _position;
    }
}

void ulogBuffer::insertString(const string& value) {
    if (checkBounds(value.length() + 2)) {
        // write: 2 byte for size + string content
        insertInt16(value.size());
        for (std::string::const_iterator it = value.begin(); it != value.end(); ++it) {
                _buffer[_position++] = (Int8)*it;;
        }
        _size = _position;
    }
}

Int8 ulogBuffer::extractInt8() {
    Int8 value = -1;

    if (checkBounds(1)) {
        value = _buffer[_position++];
    }

    return value;
}

Int16 ulogBuffer::extractInt16() {
    Int16 value = -1;

    if (checkBounds(2)) {
        Int16 nvalue = ((Int16)_buffer[_position++]) << 8;
        nvalue |= ((Int16)_buffer[_position++]);

        value = ByteOrder::fromNetwork(nvalue);
    }

    return value;
}

Int32 ulogBuffer::extractInt32() {
    Int32 value = -1;

    if (checkBounds(4)) {
        Int16 nvalue = ((Int32)_buffer[_position++]) << 24;
        nvalue |= ((Int32)_buffer[_position++]) << 16;
        nvalue |= ((Int32)_buffer[_position++]) << 8;
        nvalue |= ((Int32)_buffer[_position++]);

        value = ByteOrder::fromNetwork(nvalue);
    }

    return value;
}

string ulogBuffer::extractString() {
    string value = "";

    if (checkBounds(2)) {
        Int16 size = extractInt16();
        if (checkBounds(size)) {
            char* temp = (char*) _buffer + _position;
            value = string(temp);
        }		
    }

    return value;
}

bool ulogBuffer::checkBounds(int contentSize) {
    bool retVal = _position + contentSize +1 < _capacity;
    return retVal;
}
