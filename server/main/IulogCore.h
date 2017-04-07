
/* 
 * File:   ulogCore.h
 * Author: test
 *
 * IulogCore rappresenta la componente principale di ulog. Si occupa di fornire 
 * l'interfaccia ad alto livello per tutte le funzionalità di ulog, mettendo in 
 * comunicazione le diverse componenti del sistema. 
 */

#ifndef ULOGCORE_H
#define ULOGCORE_H

#include <list>

using namespace std;

class IulogCore {
    
    
public:
    /**
     * Crea una nuova sessione ulog
     * @param profile       L'identificatore del profilo
     * @return              L'istanza della sessione creata
     */
    virtual ulogSession* openSession(const string& profileId);
    
    /**
     * Chiude la sessione indicata
     * @param session       L'istanza della sessione da chiudere
     */
    virtual void closeSession(const ulogSession* session);
    
    /**
     * L'elenco delle sessioni attive
     * @return La lista delle sessioni attive
     */
    virtual list<ulogSession*> sessions();
    
    /**
     * Effettua la scrittura di una entry nel registro log corrispondente
     * alla sessione indicata
     * @param session       L'istanza della sessione di riferimento
     * @param entry         L'istanza della entry da scrivere
     */
    virtual void writeEntry(const ulogSession* session, const ulogEntry* entry);
    
    /**
     * Effettua una interrogazione del registro log corrispondente alla sessione
     * indicata
     * @param session       L'istanza della sessione
     * @param query         La query da eseguire
     */
    virtual void inquiryLog(const ulogSession* session, const ulogQuery& query);
    
    /**
     * Crea una nuovo profilo in base alla configurazione indicata
     * @param session       L'istanza della sessione corrente
     * @param profile       La configurazione del profilo da creare 
     */
    virtual void createProfile(const ulogSession* session, 
        const ulogProfileConfiguration& profile);
    
    /**
     * Distrugge il profilo di id specificato
     * @param session       L'istanza della sessione corrente
     * @param profileId     L'id del profilo da distrugere
     */
    virtual void destroyProfile(const ulogSession* session, 
        const string& profileId);
    
    /**
     * Effettua il lock del profilo di id indicato
     * @param session       L'istanza della sessione corrente
     * @param profileId     L'id del profilo da bloccare
     */
    virtual void lockProfile(const ulogSession* session, 
        const string& profileId);
    
    /**
     * Effettua l'unlock del profilo di id specificato
     * @param session       L'istanza della sessione corrente
     * @param profileId     L'id del profilo da sbloccare
     */
    vvirtual oid unlockProfile(const ulogSession* session, 
        const string& profileId);
    
};

#endif /* ULOGCORE_H */

