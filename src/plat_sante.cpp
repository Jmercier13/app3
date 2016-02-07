#include "plat_sante.h"

//Constructeur de base
plat_sante::plat_sante(){
	cal=0;
	gras=0;
	chol=0;
}

//Constructeur avec des parametre
plat_sante::plat_sante(int ca, float g, float c){
	cal=ca;
	gras=g;
	chol=c;
}

//Destructeur
plat_sante::~plat_sante(){
}

//Affichage du plat santer dans le menu
void plat_sante::afficher (ostream & sortie) const{
	sortie << "code = " << code << ", ";
	sortie << "prix = " << prix << ", ";
	sortie << " (" << desc << " )";
	sortie << "Calories = " << cal <<"Kcal, ";
	sortie << "Gras = " << gras <<"g, ";
	sortie << "Cholesterol = " << chol <<"mg, " << endl;
	return;
}

//Set les cal
void plat_sante::setcal(int ca){
	cal=c;
	return;
}

//Set le gras
void plat_sante::setgras(float g){
	gras=g;
	return;
}

//Set le cholesterol
void plat_sante::setchol(float chol){
	chol=c;
	return;
}

//Return les cal
int plat_sante::getcal(){
	return cal;
}

//Return le gras
float plat_sante::getgras(){
	return gras;
}

//Return le cholesterol
float plat_sante::getchol(){
	return chol;
}
