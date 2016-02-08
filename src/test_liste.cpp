#include <iostream>
#include <iomanip>
#include <sstream>

#include "../headers/liste.h"
#include "../headers/plat_choisi.h"
#include "../headers/utilities.h"

using namespace std;

void addRangeToListe(Liste &liste, int len);

//test prototype
void test_add_first();
void test_add_last();
void test_add_btw();

void test_rem_first();
void test_rem_last();
void test_rem_btw();
void test_rem_empty();

int main(){
	
	//ADD
	exec("TEST LISTE ADD FIRST (push elem to front)", &test_add_first);
	exec("TEST LISTE ADD LAST (push elem to end)", &test_add_last);
	exec("TEST LISTE ADD BTW (insert elem)", &test_add_btw);

	//REMOVE
	exec("TEST LISTE REM FIRST (rem elem to front)", &test_rem_first);
	exec("TEST LISTE REM LAST (rem elem to end)", &test_rem_last);
	exec("TEST LISTE REM BTW (rem elem btw)", &test_rem_btw);
	exec("TEST LISTE EMPTY (empty liste)", &test_rem_empty);
	
	return 0;
}

void test_add_first(){
	int NB_ELEM = 5;
	int TAB_LEN = 3;
	
	Liste liste;
	for(int i=0; i<NB_ELEM; i++){
		PlatChoisi *p = new PlatChoisi(i);
		liste.add(p, 0);	
	}
	
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
}

void test_add_last(){
	int NB_ELEM = 5;
	int TAB_LEN = 3;
	
	Liste liste;
	addRangeToListe(liste, NB_ELEM);
	
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
}

void test_add_btw(){
	int NB_ELEM = 5;
	int TAB_LEN = 3;
	
	Liste liste;
	addRangeToListe(liste, NB_ELEM);
	
	for(int i=1; i<NB_ELEM+1; i++){
		PlatChoisi *p = new PlatChoisi(-i);
		liste.add(p, i*2);	
	}
	
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
}

void test_rem_first(){
	int NB_ELEM = 5;
	int TAB_LEN = 3;
	
	Liste liste;
	addRangeToListe(liste, NB_ELEM);
	cout << "ORGINAL" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl << endl;
	
	liste.remove(0);
	
	cout << "REM [0]" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
	
	while(liste.length() ){
		liste.remove(0);
	}
	
	cout << "REM ALL" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
}

void test_rem_last(){
	int NB_ELEM = 5;
	int TAB_LEN = 3;
	
	Liste liste;
	addRangeToListe(liste, NB_ELEM);
	cout << "ORGINAL" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl << endl;
	
	liste.remove(-1);
	
	cout << "REM [last]" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
	
	while(liste.length() ){
		liste.remove(-1);
	}
	
	cout << "REM ALL" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
}

void test_rem_btw(){
	int NB_ELEM = 5;
	int TAB_LEN = 3;
	
	Liste liste;
	addRangeToListe(liste, NB_ELEM);
	cout << "ORGINAL" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl << endl;
	
	liste.remove(1);
	liste.remove(2);
	
	cout << "REM [1] & [2]" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
}

void test_rem_empty(){
	int NB_ELEM = 5;
	int TAB_LEN = 3;
	
	Liste liste;
	addRangeToListe(liste, NB_ELEM);
	cout << "ORGINAL" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl << endl;
	
	liste.empty();
	
	cout << "REM EMPTY" << endl;
	cout << "len : " << liste.length() << endl;
	cout << liste.toString() << endl;
}

void addRangeToListe(Liste &liste, int len){
	for(int i=0; i<len; i++){
		PlatChoisi *p = new PlatChoisi(i);
		liste.add(p);	
	}
}