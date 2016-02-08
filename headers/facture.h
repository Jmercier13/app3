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

#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <time.h>
#include "liste.h"
#include "plats.h"
#include "plat_choisi.h"
using namespace std;
/// Determine une Facture (a developper pour menufact02) ...
/** \class Facture
  A developper ...
*/

class Facture
{
    private:
        int pos;
        string date;
        Liste liste;
        
    public:
        Facture();
        ~Facture();
        string currentDateTime();
        void addwcode(int code, int qt);
        void showFac();             //tell if close,open or paid
        void chosewcode(int code);
        void chosefirst();
        void choselast();
		void chosenext();
		void chosebefore();
        void eraseCurrent();
        void resetFact();
        void closeFact();
        void reopenFact();
        void payFact();
        
        void setpos(int);
        int getpos();
        void setdate(string);
        string getdate();

};

#endif //FACTURE_H
