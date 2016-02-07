#include "../headers/facture.h"
#include "../headers/plats.h"

facture::facture(){
    pos = 0;
    date = currentDateTime();
}
facture::~facture(){
}

string facture::currentDateTime(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
void facture::addwcode(int code , int qt){
	plats *p;
	p.getObj();
    liste.add()
}
void facture::showFac(); {
    
}        
void facture::chosewcode(int code){
    
}
void facture::chosefirst(){
    
}
void facture::choselast(){
    
}
void facture::eraseCurrent(){
    
}
void facture::resetFact(){
    
}
void facture::closeFact(){
    
}
void facture::reopenFact(){
    
}
void facture::payFact(){
    
}

void facture::setpos(int x){
    pos = x;
}
int facture::getpos(){
    return pos;
}
void facture::setdate(string d){
    date = d;
}
string facture::getdate(){
    return date;
}
