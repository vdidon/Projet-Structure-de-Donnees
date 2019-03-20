#ifndef PROJET_STRUCTURE_DE_DONNEES_CONTACT_H
#define PROJET_STRUCTURE_DE_DONNEES_CONTACT_H

#include <string>
#include <ostream>
#include "vectorLite.h"

using namespace std; // pour le string

class rdv;

class contact {
    friend class listContact;

public:
    contact(const string &nom, const string &prenom, const string &num = "", const string &adresseMail = "");

    ~contact();

    //getter
    string getNom() const;

    string getPrenom() const;

    string getNum() const;

    string getAdresse() const;

    vectorLite<rdv *> &getTabrdv();

// avec toute les infos sur le contact

    bool operator==(const contact &c) const;
    void afficherRdvDeContact(std::ostream & os);


private:
    string d_nom;
    string d_prenom;
    string d_num;
    string d_adresseMail;
    contact *d_suiv;
    vectorLite<rdv *> d_tabRdv;

    void modifNum(const string &num);

    void modifEmail(const string &adresse);

    bool ajouterRdv(rdv *r); // tester si la personne est dispo à l'heure du rdv

    bool supprimerRdv(rdv *r); //tester si le rdv est dans la liste


};

#endif //PROJET_STRUCTURE_DE_DONNEES_CONTACT_H
