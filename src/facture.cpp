#include "../headers/Facture.h"

Facture::Facture(Menu menu){
    pos = 0;
    date = currentDateTime();
	_state = open;
	_menu = menu
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
void Facture::addWCode(int code , int qt){
	if(_state==open){
		PlatChoisi *p;
		if(_menu->envoieMenu(code)!=NULL){
			p->setplats = _menu->envoieMenu(code) 
			p->setnb(qt);
			liste.pushLast(p);
		}	
	}
}
void Facture::showFac(ostream stream); {
	if(_state==open){
		stream << "Facture ------------------------------" << endl;
		stream << date;
		for (int i=0;i<liste.length();i++){
			ostringstream ss;
			PlatChoisi *p;
			p = liste.getObj(i);
			p->getplats()->affichersomaire(&ss);
			if(pos == i){
				stream <<"->" p->_nb << " "<< ss.str() << endl;
			}
			stream << " "<< p->_nb << " "<< ss.str() << endl;
		}
		stream << "Facture ouverte";
	}
}        
void Facture::choseWCode(int code){
	if(_state==open){
		for (int i=0;i<liste.length();i++){
		PlatChoisi *p;
		p = liste.getObj(i);
		if (code == p->getnb()->get_code()){
			pos = i;
		}
	}
	}
}
void Facture::choseFirst(){
	if(_state==open){
		pos = 0;
	}

}
void Facture::choseLast(){
	if(_state==open){
		pos = liste.length()-1;
	}
}
void Facture::choseNext(){
	if(_state==open){
		if (pos != liste.length()-1){
		pos++;
		}
	}
}
void Facture::choseBefore(){
	if(_state==open){
		if(pos != 0){
			pos--;
		}
	}
}

void Facture::eraseCurrent(){
	if(_state==open){
		liste.remove(pos);
	}
}
void Facture::resetFact(){
    if(_state==open){
		liste.empty();
	}
}
void Facture::closeFact(ostream &stream){
	if(_state==open){
		showClosePaidFact(stream)
		stream << endl << "Facture fermer";
		_state = close;
	}
}
void Facture::reopenFact(ostream &stream){
	if(_state==close){
		showFac(stream);
		_state = open;
	}
}
void Facture::payFact(ostream &stream){
    if(_state==close){
		showClosePaidFact(stream)
		stream << endl << "Facture Payer";
		_state = paid;
	}
}

void Facture::showClosePaidFact(ostream &stream){
	stream << "Facture ------------------------------" << endl;
	stream << date;
	double st,tps,tvq = 0;
	for (int i=0;i<liste.length();i++){
		ostringstream ss;
		PlatChoisi *p;
		p = liste.getObj(i);
		st += p->getplats()->get_prix();	//Sous totale
		p->getplats()->affichersomaire(&ss);
		if(pos == i){
			stream <<"->" p->_nb << " "<< ss.str() << endl;
		}
		stream << " "<< p->_nb << " "<< ss.str() << endl;
	}
	tps = calculTps(st);
	tvq = calculTvq(st);
	stream << endl << "Sous-total";
	stream << setw(12) << setprecision (2) << fixed << st;
	stream << endl << setw(8)<< "tps"; 
	stream << setw(12) << setprecision (2) << fixed << tps;
	stream << endl << setw(8)<< "tps";   
	stream << setw(12) << setprecision (2) << fixed << tvq;
	stream << setw(12) << "----------" << endl;
	stream << "total      =";
	stream << setw(12) << setprecision (2)<< fixed << tps+tvq+st;
	
}

double Facture::calculTps(double tot){
	//Taux de TPS est de 5%
	return (tot * (5/100));
}

double Facture::calculTvq(double tot){
	//Taux de TVQ est de 9.975%
	return (tot *(9.975/100));
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
