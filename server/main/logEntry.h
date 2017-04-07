#ifndef LOGENTRY__H
#define LOGENTRY__H

#include <string>
#include <stdexcept> 
#include <Poco/Foundation.h>
#include <ulog/ulogMessage.h>
#include <ulog/ulogBuffer.h>

using namespace std;
using namespace Poco;

const int MAX_CUSTOM_FIELDS=32;

struct logEntry
{

public:

    logEntry() {
    }

    string logId() {
        return _logId;
    }

    string userId() {
        return _userId;
    }

    string machineName() {
        return _machineName;
    }

    string application() {
        return _application;
    }

    UInt32 timestamp() {
        return _timestamp;
    }

    string message() {
        return _message;
    }

    string customField(int index) {       
        if (index >=0 && index < MAX_CUSTOM_FIELDS) {
            return _fields[index];
        }
        else {
            throw std::out_of_range("Illegal field index");
        }
    }

    string logId(const string& logId) {
        return _logId = logId;
    }

    string userId(const string& userId) {
        return _userId = userId;
    }

    string machineName(const string& machineName) {
        return _machineName = machineName;
    }

    string application(const string& application) {
        return _application = application;
    }

    UInt32 timestamp(UInt32 timestamp) {
        return _timestamp = timestamp;
    }

    string message(const string& message) {
        return _message = message;
    }
    
    string customField(int index, string value) {
        if (index>=0 && index<MAX_CUSTOM_FIELDS) {
            _fields[index] = value;
        }
        else {
            throw std::out_of_range("Illegal field index");
        }
    }

private: 
    
    string _logId;
    string _userId;
    string _machineName;
    string _application;	 
    UInt64 _timestamp;
    string _message;
    string _fields[MAX_CUSTOM_FIELDS];
};

#endif // end of LOGENTRY__H