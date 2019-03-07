#ifndef PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H
#define PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H

#include <string>
#include "temps.h"
#include "date.h"


class contact;

class jour;

class rdv;

class listJour {
public:
    listJour(jour *tete = nullptr);

    ~listJour();

    rdv *chercherRdv(const std::string &nom);

    rdv *chercherRdv(const date &d, const std::string &nom);

    jour *chercherJour(const date &d);

    int taille();

    rdv *ajouterRdv(const date &d,
                    std::string d_nom, const temps &tDeb, unsigned int d_duree, contact **d_tabContacts = nullptr);

    void ajouterContact(rdv *r, contact *c);

    void supprimerContact(rdv *r, contact *c);

    void modifHeureDeb(const date &d,
                       const std::string &nom, const temps &t);

    void modifHeureFin(const date &d,
                       const std::string &nom, const temps &t);

    void modifDuree(const date &d,
                    const std::string &nom, unsigned int duree);

    void modifHeureDeb(const std::string &nom, const temps &t);

    void modifHeureFin(const std::string &nom, const temps &t);

    void modifDuree(const std::string &nom, unsigned int duree);

    bool afficherContactDeRdv(...);

    bool afficherRdvDeJour(...);

    void supprimerRdv(rdv* r);

private:
    jour *tete;

    void ajouterJour(const date &d);

    void supprimerJour(const date &d);

};


#endif //PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H
