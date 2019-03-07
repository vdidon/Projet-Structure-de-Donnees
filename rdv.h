#ifndef PROJET_STRUCTURE_DE_DONNEES_RDV_H
#define PROJET_STRUCTURE_DE_DONNEES_RDV_H

#include <string>
#include "temps.h"

class jour;

class contact;


class rdv {
    friend class jour;

public:
    rdv(const std::string &nom, const temps &deb, const temps &fin, jour *j,
        contact **tabContacts = nullptr);

    rdv(const std::string &nom, const temps &deb, unsigned int duree, jour *j,
        contact **tabContacts = nullptr);

    ~rdv();

    //getter
    std::string getNom() const;

    temps &getDeb() const;

    temps &getFin() const;

    unsigned int getDuree() const;

    contact **getContacts() const;

    bool afficherContactDeRdv(...);


private:
    jour *d_j;
    std::string d_nom;
    temps tDeb;
    unsigned int d_duree;
    contact **d_tabContacts;
    rdv *d_suiv;

    void modifHeureDeb(const temps &t);

    void modifHeureFin(const temps &t);

    void modifDuree(unsigned int duree);

    bool ajouterContact(contact *c);

    bool supprimeContact(contact *c);

};


#endif //PROJET_STRUCTURE_DE_DONNEES_RDV_H
