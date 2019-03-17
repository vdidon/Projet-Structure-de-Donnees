#ifndef PROJET_STRUCTURE_DE_DONNEES_RDV_H
#define PROJET_STRUCTURE_DE_DONNEES_RDV_H

#include <string>
#include "temps.h"
#include <ostream>
#include "vectorLite.h"

class jour;

class contact;


class rdv {
    friend class jour;

public:

    rdv(const std::string &nom, const temps &deb, unsigned int duree, jour *j,
        const vectorLite<contact *> &tabContacts);

    ~rdv();

    //getter
    std::string getNom() const;

    temps &getDeb() const;

    temps &getFin() const;

//    unsigned int getDuree() const;

    vectorLite<contact *> &getContacts();

    jour *getJourDeb() const;

    jour *getJourFin() const;

    bool afficherContactDeRdv(std::ostream &out) const;

    bool pasEnMemeTemps(rdv *r);


private:
    jour *d_j;
    jour *d_jfin;
    std::string d_nom;
    temps d_tDeb;
    temps d_tFin;
//    unsigned int d_duree;
    vectorLite<contact *> d_tabContacts;
    rdv *d_suiv;

    bool modifHeureDeb(const temps &t); // si c'est plus tôt checker pour toute les personnes du rdv

    bool modifHeureFin(const temps &t, jour *jfin); // si c'est plus tard checker pour toute les personnes du rdv

//    void modifDuree(unsigned int duree);

    bool ajouterContact(contact *c);

    bool supprimeContact(contact *c);

};


#endif //PROJET_STRUCTURE_DE_DONNEES_RDV_H
