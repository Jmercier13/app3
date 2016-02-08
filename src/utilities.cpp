#include "../headers/utilities.h"

void exec(string title, void (*f)(void)){
	cout << header(title) << endl;
	(*f)();
	cout << endl << endl;
}


string sep(char c, int len){
	stringstream ss;
	for(int i=0; i<len; i++){
		ss << c;
	}
	
	return ss.str();
}

string header(string title){
	stringstream ss;
	
	ss << sep() << endl;
	ss << title << endl;
	ss << sep();
	
	return ss.str();
}