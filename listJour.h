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
    explicit listJour(jour *tete = nullptr);

    ~listJour();

    rdv *chercherRdv(const date &d, const std::string &nom);

    jour *chercherJour(const date &d);

    int taille();

    rdv *ajouterRdv(const date &d,
                    std::string nom, const temps &tDeb, unsigned int duree, contact **tabContacts = nullptr);

    void ajouterContact(rdv *r, contact *c);

    void supprimerContact(rdv *r, contact *c);

    bool modifHeureDeb(const date &d,
                       const std::string &nom, const temps &t);

    bool modifHeureFin(const date &d,
                       const std::string &nom, const temps &t);

    bool modifDuree(const date &d,
                    const std::string &nom, unsigned int duree);

    bool afficherContactDeRdv(const date &d, const std::string &nom, std::ostream &out) const;

    bool afficherRdvDeJour(const date &d, std::ostream &out) const;

    void supprimerRdv(rdv* r);

private:
    jour *d_tete;

    jour *ajouterJour(const date &d, jour *pre, jour *suiv);

    void supprimerJour(jour *pre, jour *suiv);

    void supprimerJour(const date &d);

    bool estVide();

};


#endif //PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H
