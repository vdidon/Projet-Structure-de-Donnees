#ifndef PROJET_STRUCTURE_DE_DONNEES_JOUR_H
#define PROJET_STRUCTURE_DE_DONNEES_JOUR_H

#include <string>
#include "temps.h"
#include "date.h"
#include <ostream>
#include "vectorLite.h"

class rdv;

class contact;


class jour {
    friend class listJour;

public:
    jour(const date &d); // d_date doit être construit par recopie

    ~jour(); // le tab de rdv étant déjà vide

    int taille() const;

    rdv *ajouterRdv(const std::string &nom, const temps &tDeb, const temps &tFin, jour *jfin,
                    const vectorLite<contact *> &tabContacts); // que le jour même

    bool ajouterRdvMultiJour(rdv *r);

    int getJour() const;

    int getMois() const;

    int getAnnee() const;

    date getDate() const;


    static void ajouterContact(rdv *r, contact *c);

    static void supprimerContact(rdv *r, contact *c);

    static void supprimerRdv(rdv *r);

    rdv *chercherRdv(const std::string &nom);

    bool modifHeureDeb(const std::string &nom, const temps &t);

    bool modifHeureFin(const std::string &nom, const temps &t, jour *jfin);

//    void modifDuree(const std::string &nom, unsigned int duree);

    bool afficherContactDeRdv(const std::string &nom, std::ostream &out) const;

    bool afficherRdvDeJour(std::ostream &out) const;


private:
    date d_date;
    rdv *d_tete;
    vectorLite<rdv *> d_rdvMultiJours; // des jours d'avant
    jour *suiv;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_JOUR_H
