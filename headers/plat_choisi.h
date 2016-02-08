#ifndef PLATCHOISI_H
#define PLATCHOISI_H

#include <iostream>
#include <string>
#include <iomanip>
#include "plats.h"
using namespace std;

class PlatChoisi {
	private: 	
		PlatAuMenu *_plat;
		int _nb;
	
	public: 
		void setnb(int nb);
		int getnb();
		void setplats(PlatAuMenu *plats);
		PlatAuMenu* getplats();
}