//
// Created by vdido on 25/03/2019.
//

#ifndef PROJET_STRUCTURE_DE_DONNEES_TEST_H
#define PROJET_STRUCTURE_DE_DONNEES_TEST_H

#include "agenda.h"
#include <iostream>

using namespace std;
agenda ag{};
void test() {

	cout << "ag.ajouterContact(\"didon\", \"valère\", \"1234567890\", \"vdidon@live.fr\") : "
	     << ag.ajouterContact("didon", "valère", "1234567890", "vdidon@live.fr") << endl;
	cout << "ag.ajouterRdv(9, 5, 1997, \"coucou\", 20, 0, 10, 5, 1997, 20, 3) : "
	     << ag.ajouterRdv(9, 5, 1997, "coucou", 20, 0, 10, 5, 1997, 20, 3) << endl;
	cout << "ag.ajouterContactARdv(\"didon\", \"valère\", \"coucou\", 9, 5, 1997) : "
	     << ag.ajouterContactARdv("didon", "valère", "coucou", 9, 5, 1997) << endl;
	cout << "ag.modifNum(\"didon\",\"valère\",\"0987654321\")" << ag.modifNum("didon", "valère", "0987654321") << endl;
	cout << "ag.modifEmail(\"didon\",\"valère\",\"coucou@gmail.com\")"
	     << ag.modifEmail("didon", "valère", "coucou@gmail.com") << endl;
	cout << "ag.modifHeureDeb(9,5,1997,\"coucou\",10,10)<<endl;" << ag.modifHeureDeb(9, 5, 1997, "coucou", 10, 10)
	     << endl;
	cout << "ag.modifHeureFin(9,5,1997,\"coucou\",10,10)<<endl;" << ag.modifHeureFin(9, 5, 1997, "coucou", 10, 10)
	     << endl;
	cout << "ag.modifJourDeb(9,5,1997,\"coucou\",8,5,1997)" << ag.modifJourDeb(9, 5, 1997, "coucou", 8, 5, 1997)
	     << endl;
	cout << "ag.modifJourFin(8,5,1997,\"coucou\",11,5,1997)" << ag.modifJourFin(8, 5, 1997, "coucou", 11, 5, 1997)
	     << endl;
	cout << "ag.contactEstDispo(\"didon\",\"valère\",9,4,1997,4,4,10,4,1997,9,9)"
	     << ag.contactEstDispo("didon", "valère", 9, 5, 1997, 4, 4, 10, 5, 1997, 9, 9) << endl;
	cout << "!ag.contactEstDispo(\"didon\", \"valère\", 8, 5, 1997, 20, 0, 9, 5, 1997, 20, 0)"
	     << !ag.contactEstDispo("didon", "valère", 8, 5, 1997, 20, 0, 9, 5, 1997, 20, 0) << endl;
	cout << endl;
	ag.afficherRdvDeContact("didon", "valère", cout);
}

void test2() {
	agenda ag{};
	cout << "ag.ajouterRdv(9, 5, 1997, \"coucou\", 20, 0, 10, 5, 1997, 20, 3) : "
	     << ag.ajouterRdv(9, 5, 1997, "coucou", 20, 0, 10, 5, 1997, 20, 3) << endl;
	cout << endl << ag.supprimerRdv(9, 5, 1997, "coucou");
}


#endif //PROJET_STRUCTURE_DE_DONNEES_TEST_H
