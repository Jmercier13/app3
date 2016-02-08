//!  Definition de classes
/**
    \file  test_menu_fact.h
    \author Equipe professorale S2
    \date 2012-01-12
    \version 1.00 
  
    Classe Test_menu_fact et classes associees<br>

    Test de l'application menufact01<br>

    Ce code est a completer pour la realisation de l'iteration menufact02.<br>

    Historique de revision   (menufact01)<br>
    V01.00d  14 janv 2012  Equipe professorale S2  Creation version 2011<br>
  -----------------------------------------------------------------------------<br>
  Copyright 2012<br>
  Departement de genie electrique et de genie informatique Universite de Sherbrooke<br>
*/

#ifndef TEST_MENU_FACT_H
#define TEST_MENU_FACT_H

#include "facture.h"
#include "menu.h"

//const bool TRACE_test_menu_fact = true;             ///< Activer une trace sur cout (deboguage systematique)

/// Classe d'implementation d'un test
/** \class Test_menu_fact
  Tests de l'application: execute des transactions sur Menu et Facture <br>
*/

class Test_menu_fact
{
	public:
		Test_menu_fact  (Menu *le_menu, Facture *la_facture); ///< Constructeur de la classe
		~Test_menu_fact();                                    ///< Destructeur
		
		Menu * le_menu;
		Facture *la_facture;
		ostream _stream;
		
		void executer_test_1();       ///< Executer le test 
		void executer_test_2();
		
		
        void test_showFac();             
		void test_closeFact();
        void test_reopenFact();
        void test_payFact();
		void test_payFactReopen();
        void test_choseWCode();
        void test_choseFirst();
        void test_choseLast();
		void test_choseNext();
		void test_choseBefore();
		void test_addWCode();
        void test_eraseCurrent();
        void test_resetFact();
		void test_init();

}; 

#endif //TEST_MENU_FACT_H
