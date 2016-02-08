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
		p->setplats = _menu.envoieMenu(code) //CHANGER SELON FONCTION MENU
		p->setnb(qt);
		liste.pushLast(p);
	}
}
void Facture::showFac(); {
	if(_state==open){
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
			cout << " "<< p->_nb << " "<< ss << endl;
		}
		cout << "Facture ouverte";
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
void Facture::closeFact(){
	if(_state==open){
		showClosePaidFact()
		cout << endl << "Facture fermer";
		_state = close;
	}
}
void Facture::reopenFact(){
	if(_state==close){
		showFac();
		_state = open;
	}
}
void Facture::payFact(){
    if(_state==close){
		showClosePaidFact()
		cout << endl << "Facture Payer";
		_state = paid;
	}
}

void Facture::showClosePaidFact(){
	cout << "Facture ------------------------------" << endl;
	cout << date;
	double st,tps,tvq = 0;
	for (int i=0;i<liste.length();i++){
		ostringstream ss;
		PlatChoisi *p;
		p = liste.getObj(i);
		st += p->getplats()->get_prix();	//Sous totale
		p->getplats()->affichersomaire(&ss);
		if(pos == i){
			cout <<"->" p->_nb << " "<< ss << endl;
		}
		cout << " "<< p->_nb << " "<< ss << endl;
	}
	tps = calculTps(st);
	tvq = calculTvq(st);
	cout << endl << "Sous-total";
	cout << setw(12) << setprecision (2) << fixed << st;
	cout << endl << setw(8)<< "tps"; 
	cout << setw(12) << setprecision (2) << fixed << tps;
	cout << endl << setw(8)<< "tps";   
	cout << setw(12) << setprecision (2) << fixed << tvq;
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
