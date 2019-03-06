#ifndef PROJET_STRUCTURE_DE_DONNEES_CONTACT_H
#define PROJET_STRUCTURE_DE_DONNEES_CONTACT_H

#include <string>

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

    rdv **getTabrdv() const;


    bool afficherRdvDeContact(...);

    bool operator==(const contact &c) const;


private:
    string d_nom;
    string d_prenom;
    string d_num;
    string d_adresseMail;
    contact *d_suiv;
    rdv **d_tabRdv;

    bool modifNum(const string &num);

    bool modifEmail(const string &adresse);

    void ajouterRdv(rdv *r);

    void supprimerRdv(rdv *r);

};

#endif //PROJET_STRUCTURE_DE_DONNEES_CONTACT_H
