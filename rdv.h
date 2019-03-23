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

    rdv(const std::string &nom, const temps &deb, const temps &fin, jour *j, jour *jfin,
        const vectorLite<contact *> &tabContacts); //ska : fait
    ~rdv();

    //getter
    std::string getNom() const; //ska : fait

    temps &getDeb() const;  //ska : fait

    temps &getFin() const;  //ska : fait


    vectorLite<contact *> &getContacts();   //ska : fait

    jour *getJourDeb() const; //ska : fait

    jour *getJourFin() const; //ska : fait

    bool afficherContactDeRdv(std::ostream &out) const; //ska : fait

    bool pasEnMemeTemps(rdv *r);    //ska : fait


private:
    jour *d_j;
    jour *d_jfin;
    std::string d_nom;
    temps d_tDeb;
    temps d_tFin;
    vectorLite<contact *> d_tabContacts;
    rdv *d_suiv;

    bool modifHeureDeb(const temps &t); //ska : fait

    bool modifJourDeb(const jour* j); // si c'est plus tôt checker pour toute les personnes du rdv

    bool modifHeureFin(const temps &t); //ska : fait

    bool modifJourFin(const jour* j); // si c'est plus tard checker pour toute les personnes du rdv

    bool ajouterContact(contact *c); //ska : fait

    bool supprimeContact(contact *c); //ska : fait

};


#endif //PROJET_STRUCTURE_DE_DONNEES_RDV_H
