/**
	 \file test_menu_fact.cpp
	 \author Equipe professorale S2
	 \date 2012-01-12
	 \version 1.00a 
  
	 Classe Test_menu_fact <br>
 
	 Ce code est a completer pour la realisation de l'iteration menufact01.<br>

	 Historique de revision	(menufact01)<br>
	 V01.00	12 janv 2012  D. Dalle  Creation<br>

  -----------------------------------------------------------------------------<br>
  Copyright 2012<br>
  Departement de genie electrique et de genie informatique Universite de Sherbrooke<br>
*/

#include "../headers/test_menu_fact.h"

Test_menu_fact::Test_menu_fact(Menu *le_m, Facture *la_f, ostream stream) {
	 le_menu = le_m;
	 la_facture = la_f;
	 _stream = stream;
}

Test_menu_fact::~Test_menu_fact() {
};

void Test_menu_fact::executer_test_1() {		
	_stream << "\n==========================================================";
	_stream << "\nExecuter_test_1 Constitution initiale du menu..." << endl;
	//
	//  Tests des fonctions d'initialisations des attributs (un a la fois)
	le_menu->ajoute(10, "Soupe du jour", 2.99); 

	// La methode suivante serait plus concise avec le constructeur approprie
	le_menu->ajoute(20, "Salade du jardin", 4.95 );
	
	// La methode suivante est encore plus concise avec le constructeur approprie
	le_menu->ajoute(30, "Canard sauvage au poivre vert", 3.99);
	le_menu->ajoute(39, "Soupe repas aux fruits de mer", 10.99);
	le_menu->afficher(_stream);

	_stream << "\n=======ae de positionner a un code inexistant" << endl;

	int un_code = 999;
	 
	if (le_menu->positionne_code(un_code)){
		_stream << "Code "<< un_code << " localise" << endl;
	} else {
		_stream << "Code "<< un_code << " non existant" << endl;
	}
	 
	le_menu->afficher(_stream);

	_stream << "\n==========================================================";
	_stream << "\nOn change le prix du plat de code 20 (sera le plat courant)";
	 
	if (le_menu->positionne_code(20)){
		PlatAuMenu * un_plat = le_menu->get_courant();
		un_plat->set_prix (6.50); 
		le_menu->afficher(_stream);
	}
	else{
		_stream << "Plat non existant" << endl;
	}

	_stream << "\n==========================================================";
	_stream << "\nOn elimine le plat de code 30 (plat courant sera non defini)";
 
	 // on supprime un plat du menu
	le_menu->positionne_code(30);
	le_menu->efface_courant();
	le_menu->afficher(_stream);

	_stream << "\n==========================================================";
	_stream << "\nOn ajoute un nouveau plat (sera le plat courant)" << endl;

	// on ajoute un nouveau plat
	le_menu->ajoute(33, "Truite aux amandes", 13.99);
	le_menu->afficher(_stream);

	_stream << "\n==========================================================";
	_stream << "\nFin du test..." << endl;
}

void Test_menu_fact::executer_test_2(){
	exec("AFFICHER LA FACTURE OUVERTE", &test_showFac);
	exec("AJOUT PLAT CHOISI AVEC CODE ET QUANTITÉ", &test_addWCode);
	exec("FERMER LA FACTURE", &test_closeFact);
	exec("OUVRIR LA FACTURE APRÈS LA FERMETURE", &test_reopenFact);
	exec("PAYER LA FACTURE", &test_payFact);
	exec("SELECTIONNER UN PLAT À PARTIR D'UN CODE", &test_choseWCode);
	exec("SELECTIONNER LE PREMIER PLAT", &test_choseFirst);
	exec("SELECTIONNER LE DERNIER PLAT", &test_choseLast);
	exec("SELECTIONNER LE PLAT SUIVANT", &test_choseNext);
	exec("SELECTIONNER LE PLAT PRÉCÉDENT", &test_choseBefore);
	exec("EFFACER LE PLAT SELECTIONNER", &test_eraseCurrent);
	exec("REMMETTRE LA FACTURE À 0", &test_resetFact);
}
void Test_menu_fact::test_init(){
	//Initialisation des tests
	le_menu->ajoute(30, "Canard sauvage au poivre vert", 3.99);
	le_menu->ajoute(39, "Soupe repas aux fruits de mer", 10.99);
	le_menu->ajoute(45, "Soupe au tomate", 2.99);
	le_menu->ajoute(12, "Brownie", 1.99);
	la_facture->addWCode(le_menu->envoieMenu(30),2);
	la_facture->addWCode(le_menu->envoieMenu(39),5);
}
void Test_menu_fact::test_showFac(){
	//Ajoutons certain plats au menu
	test_init();
	_stream<<"\nAffichage de la facture\n";
	la_facture->showFact(_stream);
}

void Test_menu_fact::test_addWCode(){
	test_init();
	la_facture->addWCode(le_menu->envoieMenu(1),2);
	_stream<<"\nAjout de 5 elements, 4 du menu et 1 qui n'existe pas\n";
	la_facture->showFact(_stream);
}

void Test_menu_fact::test_closeFact(){
	test_init();
	_stream<<"\nFermer la facture\n";
	la_facture->closeFact(_stream);
}

void Test_menu_fact::test_reopenFact(){
	test_init();
	la_facture->closeFact(_stream);
	_stream<<"\nNous avons fermer la facture maintenant nous allons l'ouvrir a nouveau\n";
	la_facture->reopenFact(_stream);
}

void Test_menu_fact::test_payFact(){
	test_init();
	la_facture->closeFact(_stream);
	_stream<<"\nNous avons fermer la facture maintenant nous allons la payer\n";
	la_facture_payFact(_stream_);
}

void Test_menu_fact::test_payFactReopen(){
	test_init();
	la_facture->closeFact(_stream);
	_stream<<"\nNous avons fermer la facture maintenant nous allons la payer\n";
	la_facture_payFact(_stream_);
	_stream<<"\nEssayons d'ouvrir la facture payer\n";
	la_facture->reopenFact(_stream);
}
void Test_menu_fact::test_choseWCode(){
	test_init();
	la_facture->showFact(_stream);
	_stream<<"\n Selectionnons un plat a partir d'un code\n";
	la_facture->choseWCode(39);
	la_facture->showFact(_stream);
}

void Test_menu_fact::test_choseFirst(){
	test_init();
	la_facture->choseWCode(39);
	la_facture->showFact(_stream);
	_stream<<"\nSelectionnons le premier plat\n";
	la_facture->choseFirst();
	la_facture->showFact(_stream);
}

void Test_menu_fact::test_choseLast(){
	test_init();
	la_facture->choseWCode(39);
	la_facture->showFact(_stream);
	_stream<<"\nSelectionnons le dernier plat\n";
	la_facture->choseLast();
	la_facture->showFact(_stream);
}

void Test_menu_fact::test_choseNext(){
	test_init();
	la_facture->choseWCode(39);
	la_facture->showFact(_stream);
	_stream<<"\nSelectionnons le prochain plat\n";
	la_facture->choseNext();
	la_facture->showFact(_stream);
}

void Test_menu_fact::test_choseBefore(){
	test_init();
	la_facture->choseWCode(39);
	la_facture->showFact(_stream);
	_stream<<"\nSelectionnons le plat d'avant\n";
	la_facture->choseBefore();
	la_facture->showFact(_stream);
}

void Test_menu_fact::test_eraseCurrent(){
	test_init();
	la_facture->showFact(_stream);
	_stream<<"\nEffacons le plat selectionner\n";
	la_facture->eraseCurrent();
	la_facture->showFact(_stream);
}

void Test_menu_fact::test_resetFact(){
	test_init();
	la_facture->showFact(_stream);
	_stream<<"\nRenitialisons la facture\n";
	la_facture->resetFact();
	la_facture->showFact(_stream);
}