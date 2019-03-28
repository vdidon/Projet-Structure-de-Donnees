#ifndef PROJET_STRUCTURE_DE_DONNEES_JOUR_H
#define PROJET_STRUCTURE_DE_DONNEES_JOUR_H

#include <string>
#include "date.h"
#include <ostream>
#include "vectorLite.h"
#include "rdv.h"

class rdv;

class contact;


class jour {
	friend class listJour;

public:
	jour(const date &d, rdv *tete = nullptr); //ska : fait        d_date doit être construit par recopie

	~jour(); //ska : fait                    le tab de rdv étant déjà vide

	int taille() const; //ska : fait

	rdv *ajouterRdv(const std::string &nom, const temps &tDeb, const temps &tFin, jour *j, jour *jfin, //ska : fait
	                const vectorLite<contact *> &tabContacts); // que le jour même

	rdv *chercherRdv(const std::string &nom) const; //ska : fait

	static bool supprimerRdv(rdv *r); //ska : fait

	bool supprimerRdvSansDelete(rdv *r); //ska : fait

	bool ajouterRdvSansNew(rdv *r); //ska : fait

	bool ajouterRdvMultiJour(rdv *r); //fait

	bool supprimerRdvMultiJour(rdv *r);

	int getJour() const;    //ska : fait

	int getMois() const;    //ska : fait

	int getAnnee() const;   //ska : fait

	date getDate() const;   //ska : fait


	static bool ajouterContact(rdv *r, contact *c); //ska : fait

	static void supprimerContact(rdv *r, contact *c); //ska : fait



	bool modifHeureDeb(const std::string &nom, const temps &t); //ska : fait

	bool modifJourDeb(const std::string &nom, jour *j);   //ska : fait

	bool modifHeureFin(const std::string &nom, const temps &t); //ska : fait

	bool modifJourFin(const std::string &nom, jour *j);   //ska : fait

	bool afficherRdvDeJour(std::ostream &out) const;    //ska : fait

	bool afficherContactDeRdv(const std::string &nom, std::ostream &out) const; //ska : fait


private:
	date d_date;
	rdv *d_tete;
	vectorLite<rdv *> d_rdvMultiJours; // des jours d'avant
	jour *suiv;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_JOUR_H
