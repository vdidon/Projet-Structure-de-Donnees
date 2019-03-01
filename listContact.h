//
// Created by vdido on 12/02/2019.
//

#ifndef PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H
#define PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H

#include <string>

using namespace std; // pour le string

class contact;

class listContact {
public:
	listContact();

	~listContact();

	bool ajouterContact(const string &nom, const string &prenom, const string &num, const string &adresseMail);

	bool supprimerContact(const string &nom, const string &prenom);

	int taille();

	contact *chercherContact(const string &nom, const string &prenom);


private:

	contact *d_tete;
};


#endif //PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H
