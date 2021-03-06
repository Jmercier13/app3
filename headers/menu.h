//!  Definition de classes
/**
    \file  menu.h
    \author Equipe professorale S2
    \date 2012-01-20
    \version 1.00 

    Classe Menu<br>
  
    Historique de revision<br>
    V01.00d  14 janv 2012  Equipe professorale S2  Creation version 2012<br>

  -----------------------------------------------------------------------------<br>
  Copyright 2012<br>
  Departement de genie electrique et de genie informatique Universite de Sherbrooke<br>
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "plats.h"

using namespace std;

const bool TRACE_Menu = false;          ///< Activer une trace sur cout (deboguage systematique)
const int NBRE_PLATS_MAX = 20;          // Nombre de plats maximum dans un menu 

/// Determine un Menu de plats...
/** \class Menu
  Determine un Menu de plats...<br>
  Permet de construire un menu et de l'exploiter<br>
  Note: plusieurs methodes ont ete developpees pour un comportement de liste.<br>
  L'implementation en tableau est cachee.<br>
  Cependant les methodes <br>
  demandees pour realisation dans l'APP sont limitees pour eviter<br>
  d'implementer une liste complete dans un tableau.<br>
*/

class Menu {
	private:
		string description;                       ///< Description specifique
		PlatAuMenu *plat[NBRE_PLATS_MAX];
		int courant;
	
	public:
		Menu();
		virtual ~Menu();
		
		PlatAuMenu *get_courant();                       ///< Obtenir un pointeur vers le plat courant
		
		void afficher (ostream & sortie) const;          ///< Afficher le contenu du menu
		void afficher_courant (ostream & sortie) const;  ///< Afficher le Plat courant
		
		void ajoute(int code, string desc, double prix); ///< Ajouter un plat au menu
		bool positionne_code(int code);                  ///< Rechercher un code et en faire le plat courant
		
		PlatAuMenu* envoieMenu(int code);
		
		void efface_courant();                           ///< Effacer  le Plat courant

};

/**
   \fn string ladate()
   \brief Fonction utilitaire pour produire une chaine de caractere contenant la date systeme
*/
string ladate();

#endif //MENU_H

