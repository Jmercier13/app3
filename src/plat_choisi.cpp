#include "../headers/plat_choisi.h"

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