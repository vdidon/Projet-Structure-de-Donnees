//
// Created by vdido on 12/02/2019.
//

#ifndef PROJET_STRUCTURE_DE_DONNEES_JOUR_H
#define PROJET_STRUCTURE_DE_DONNEES_JOUR_H

#include <string>

class rdv;

class jour {
	jour(int j, int m, int a);

	~jour();

	int taille() const;

	bool ajouterRdv(...);

	bool supprimerRdv(const std::string &nom);

	int getJour() const;

	int getMois() const;

	int getAnnee() const;

	bool operator>(const jour &j);


private:
	int d_j, d_m, d_a;
	rdv *d_tete;
	rdv **d_rdvMultiJours;
};


#endif //PROJET_STRUCTURE_DE_DONNEES_JOUR_H
