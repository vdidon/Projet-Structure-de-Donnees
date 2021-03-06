#ifndef PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H
#define PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H

#include <string>
#include "jour.h"


class contact;

class jour;

class rdv;

class listJour {
public:
    listJour(jour *tete = nullptr);

	~listJour();

    rdv *chercherRdv(const date &d, const std::string &nom) const;

    jour *chercherJour(const date &d) const;

    int taille();

    rdv *ajouterRdv(const date &d, std::string nom, const temps &tDeb, const temps &tFin, const date &dFin, const
    vectorLite<contact *> &tabContacts);

	bool ajouterContact(rdv *r, contact *c);

    void supprimerContact(rdv *r, contact *c);

    bool modifHeureDeb(const date &d,
                       const std::string &nom, const temps &t);

    bool modifJourDeb(const date &d, const date &newd,
                      const std::string &nom);

    bool modifHeureFin(const date &d,
                       const std::string &nom, const temps &t);

    bool modifJourFin(const date &d, const date &newd,
                      const std::string &nom);

//    bool modifDuree(const date &d,const std::string &nom, unsigned int duree);

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
