#include "../headers/plat_choisi.h"

PlatChoisi(){
	nb = 0 ;
}

PlatChoisi(PlatAuMenu plat, int nb){
	_plats = plat;
	_nb = nb;
}

~PlatChoisi(){
	
}

void PlatChoisi::setnb(int nb){
	_nb = nb;
}

int PlatChoisi::getnb(){
	return _nb;
}

void PlatChoisi::setplats(PlatAuMenu *plats){
	_plats = plats;
}

PlatAuMenu* PlatChoisi::getplats(){
	return _plats;
}