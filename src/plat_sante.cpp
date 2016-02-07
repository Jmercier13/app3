#include "../headers/PlatSante.h"

//Constructeur de base
PlatSante::PlatSante(){
	cal=0;
	gras=0;
	chol=0;
}

//Constructeur avec des parametre
PlatSante::PlatSante(int ca, float g, float c){
	cal=ca;
	gras=g;
	chol=c;
}
	
//Destructeur
PlatSante::~PlatSante(){
}

//Affichage du plat santer dans le menu
void PlatSante::afficher (ostream & sortie) const{
		
	sortie << "code = " << code << ", ";
	sortie << "prix = " << prix << ", ";
	sortie << " (" << desc << " )";
	sortie << "Calories = " << cal <<"Kcal, ";
	sortie << "Gras = " << gras <<"g, ";
	sortie << "Cholesterol = " << chol <<"mg, " << endl;
	return;
}

//Set les cal
void PlatSante::setcal(int ca){
	cal=c;
	return;
}

//Set le gras
void PlatSante::setgras(float g){
	gras=g;
	return;
}

//Set le cholesterol
void PlatSante::setchol(float chol){
	chol=c;
	return;
}

//Return les cal
int PlatSante::getcal(){
	return cal;
}

//Return le gras
float PlatSante::getgras(){
	return gras;
}

//Return le cholesterol
float PlatSante::getchol(){
	return chol;
}
