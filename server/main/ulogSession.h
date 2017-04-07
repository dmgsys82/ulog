/* 
 * File:   ulogSession.h
 * Author: test
 *
 * Created on 5 aprile 2017, 23.04
 */

#ifndef ULOGSESSION_H
#define ULOGSESSION_H

class ulogSession {
    
public :
    ulogSession(unsigned id, ulogProfile* profile) {
        _id = id;
        _profile = profile;
    }
    
    /**
     * Session id
     * @return Id della sessione
     */
    unsigned id() {
        return _id;
    }
    
    /**
     * Riferimento al profilo ulog
     * @return  L'istanza del profilo ulog
     */
    const ulogProfile* profile() {
        return _profile;
    }
    
private:
    
    unsigned _id;                   // id della sessione
    ulogProfile* _profile;          // riferimento al profilo
};

#endif /* ULOGSESSION_H */

