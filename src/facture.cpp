#include "../headers/Facture.h"

Facture::Facture(){
    pos = 0;
    date = currentDateTime();
}
Facture::~Facture(){
}

string Facture::currentDateTime(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
void Facture::addwcode(int code , int qt){
	PlatChoisi *p;
	
}
void Facture::showFac(); {
    cout << "Facture ------------------------------" << endl;
	cout << date;
	for (int i=0;i<liste.length();i++){
		ostringstream ss;
		PlatChoisi *p;
		p = liste.getObj(i);
		p->getplats()->affichersomaire(&ss);
		if(pos == i){
			cout <<"->" p->_nb << " "<< ss << endl;
		}
		cout << p->_nb << " "<< ss << endl;
	}
	cout << "Facture ouverte";
}        
void Facture::chosewcode(int code){
    for (int i=0;i<liste.length();i++){
		PlatChoisi *p;
		p = liste.getObj(i);
		if (code == p->getnb()->get_code()){
			pos = i;
		}
	}
}
void Facture::chosefirst(){
    pos = 0;
}
void Facture::choselast(){
    pos = liste.length()-1;
}
void Facture::chosenext(){
	if (pos != liste.length()-1){
		pos++;
	}
}
void Facture::chosebefore(){
	if(pos != 0){
		pos--;
	}
}

void Facture::eraseCurrent(){
    liste.remove(pos);
}
void Facture::resetFact(){
    
}
void Facture::closeFact(){
    
}
void Facture::reopenFact(){
    
}
void Facture::payFact(){
    
}

void Facture::setpos(int x){
    pos = x;
}
int Facture::getpos(){
    return pos;
}
void Facture::setdate(string d){
    date = d;
}
string Facture::getdate(){
    return date;
}
