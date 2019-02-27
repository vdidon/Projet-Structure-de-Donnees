//
// Created by vdido on 12/02/2019.
//

#ifndef PROJET_STRUCTURE_DE_DONNEES_CONTACT_H
#define PROJET_STRUCTURE_DE_DONNEES_CONTACT_H

#include <string>

using namespace std; // pour le string

class rdv;

class contact {
	friend class listContact;

public:
	contact(const string &nom, const string &prenom, const string &num, const string &adresse);

	//getter
	string getNom() const;

	string getPrenom() const;

	string getNum() const;

	string getAdresse() const;

	//setter
	void modifNum(string num);

	void modifEmail(string adresse);

private:
	string d_nom;
	string d_prenom;
	string d_num;
	string d_adresse;
	contact *suiv;
	rdv **tabRdv;
};

#endif //PROJET_STRUCTURE_DE_DONNEES_CONTACT_H
