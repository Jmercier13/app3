//Classe plat sante qui herite de la classe Plats

#ifndef PLAT__SANTE_H
#define PLAT__SANTE_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class PlatSante: public Plats{
    
    private:
        int cal;       //Calories
        float gras;        //gras
        float chol;       //Cholesterol
    
    public:
        PlatSante();
        PlatSante(int, float, float);
        ~PlatSante();
      
        void setcal(int);
        void setgras(float);
        void setchol(float);
        
        int getcal();
        float getgras();
        float getchol();
    
        void afficher (ostream & sortie) const;
};