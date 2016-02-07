//!  Definition de classes
/**
    \file  facture.h
    \author xxxxx
    \date AAAA-MM-JJ
    \version 1.00
  
    A developper pour menufact02    
*/

#ifndef FACTURE_H
#define FACTURE_H

/// Determine une Facture (a developper pour menufact02) ...
/** \class Facture
  A developper ...
*/

class Facture
{
    private:
        int pos;
    public:
        facture();
        ~facture();
        
        void choseplat(int code);
        
        
        void setpos(int);
        int getpos();
        
// A developper ...
};

#endif //FACTURE_H
