#ifndef PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H
#define PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H

#include <string>
#include <ostream>

using namespace std; // pour le string

class contact;

class rdv;

class listContact {
public:
    listContact(contact *tete = nullptr);

    ~listContact();

    contact *ajouterContact(const string &nom, const string &prenom, const string &num = "", const string &adresseMail = "");

    bool supprimerContact(const string &nom, const string &prenom);

    int taille();

    contact *chercherContact(const string &nom, const string &prenom) const;

    bool modifNum(const string &nom, const string &prenom, const string &num);

    bool modifEmail(const string &nom, const string &prenom, const string &adresse);

    void ajouterRdv(contact *c, rdv *r);

    void supprimerRdv(contact *c, rdv *r);

    bool afficherRdvDeContact(const string &nom, const string &prenom, ostream &out) const;

private:

    contact *d_tete;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_LISTCONTACT_H
