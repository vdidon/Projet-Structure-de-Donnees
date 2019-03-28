#ifndef PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H
#define PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H

#include <string>
#include <ostream>
#include "contact.h"

using namespace std; // pour le string

class contact;

class rdv;

class listContact {
public:
    listContact(contact *tete = nullptr); /** fait */

	~listContact(); /** fait */

    contact * ajouterContact(const string &nom, const string &prenom, const string &num = "", const string &adresseMail = ""); /** fait */


    bool supprimerContact(const string &nom, const string &prenom); /** fait */

    int taille(); /** fait */

    contact *chercherContact(const string &nom, const string &prenom) const; /** fait */

    bool modifieNum(const string &nom, const string &prenom, const string &num); /** fait */

    bool modifieEmail(const string &nom, const string &prenom, const string &adresse); /** fait */

    bool ajouteRdv(contact *c, rdv *r);  /** fait */ // la classe contact teste si la personne est dispo à l'heure du rdv

    bool supprimeRdv(contact *c, rdv *r); /** fait */ // la classe contact teste si le rdv est dans la liste

    bool afficherRdvDeContact(const string &nom, const string &prenom, ostream &out) const; /** fait */

private:

    contact *d_tete;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H
