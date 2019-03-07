#ifndef PROJET_STRUCTURE_DE_DONNEES_JOUR_H
#define PROJET_STRUCTURE_DE_DONNEES_JOUR_H

#include <string>
#include "temps.h"
#include "date.h"

class rdv;

class contact;


class jour {
    friend class listJour;

public:
    jour(const date &d); // d_date doit être construit par recopie

    ~jour(); // le tab de rdv étant vide

    int taille() const;

    rdv* ajouterRdv(...);

    int getJour() const;

    int getMois() const;

    int getAnnee() const;

    date getDate() const;


    static void ajouterContact(rdv *r, contact *c);

    static void supprimerContact(rdv *r, contact *c);

    static void supprimerRdv(rdv *r); // le tab de contact étant vide

    rdv *chercherRdv(const std::string &nom);

    void modifHeureDeb(const std::string &nom, const temps &t);

    void modifHeureFin(const std::string &nom, const temps &t);

    void modifDuree(const std::string &nom, unsigned int duree);

    bool afficherContactDeRdv(...);

    bool afficherRdvDeJour(...);


private:
    date d_date;
    rdv *d_tete;
    rdv **d_rdvMultiJours; // des jours d'avant
    jour *suiv;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_JOUR_H
