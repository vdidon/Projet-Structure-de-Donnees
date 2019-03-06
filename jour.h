#ifndef PROJET_STRUCTURE_DE_DONNEES_JOUR_H
#define PROJET_STRUCTURE_DE_DONNEES_JOUR_H

#include <string>
#include "temps.h"

class rdv;

class contact;

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

    static void ajouterContact(rdv *r, contact *c);

    rdv *chercherRdv(const std::string &nom);

    void modifHeureDeb(const std::string &nom, const temps &t);

    void modifHeureFin(const std::string &nom, const temps &t);

    void modifDuree(const std::string &nom, unsigned int duree);

    bool afficherContactDeRdv(...);

    bool afficherRdvDeJour(...);


private:
    int d_j, d_m, d_a;
    rdv *d_tete;
    rdv **d_rdvMultiJours; // des jours d'avant

};


#endif //PROJET_STRUCTURE_DE_DONNEES_JOUR_H
