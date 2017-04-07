/* 
 * File:   IulogStorage.h
 * Author: test
 *
 * Created on 5 aprile 2017, 22.55
 */

#ifndef IULOGSTORAGE_H
#define IULOGSTORAGE_H

/**
 * iulogStorage è l'interfaccia principale verso il sistema di storage di 
 * ulog. 
 */
class IulogStorage {
    
public:
    /**
     * Effettua la scrittura di una entry nel registro dei log
     * @param session       L'istanza della sessione di riferimento
     * @param entry         La entry del log da scrivere
     */
    void write(const ulogSession* session,const* ulogEntry entry);
    
    /**
     * Effettua l'interrogazione del registro dei log
     * @param session       L'istanza della sessione di riferimento
     * @param query         La query da eseguire
     * @return 
     */
    list<LogEntry*> inquiry(const ulogSession* session, const ulogQuery& query);
    
};

#endif /* IULOGSTORAGE_H */

