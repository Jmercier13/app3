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
#include "menu.h"
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
		enum _state {open,close,paid};	
		Menu _menu;	
        
    public:
        Facture(Menu menu);
        ~Facture();
        string currentDateTime();
		
        void addWCode(int code, int qt);
        void showFac();             //tell if close,open or paid
        void choseWCode(int code);
        void choseFirst();
        void choseLast();
		void choseNext();
		void choseBefore();
        void eraseCurrent();
        void resetFact();
        void closeFact();
        void reopenFact();
        void payFact();
		void showClosePaidFact();
		double calculTps(double tot);
		double calculTvq(double tot);
        
        void setpos(int);
        int getpos();
        void setdate(string);
        string getdate();

};

#endif //FACTURE_H
