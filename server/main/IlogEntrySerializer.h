/* 
 * File:   logEntrySerializer.h
 * Author: sverduci
 *
 * Created on 9 marzo 2016, 21.45
 */

#ifndef ILOGENTRYSERIALIZER_H
#define	ILOGENTRYSERIALIZER_H

#include <ulog/logEntry.h>

class IlogEntrySerializer {
    
    virtual bool serialize(ulogBuffer* buf,logEntry* entry) = 0;
    
    virtual bool deserialize(ulogBuffer* buf,logEntry* entry) = 0;
};

#endif	/* ILOGENTRYSERIALIZER_H */

