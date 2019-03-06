#ifndef PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H
#define PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H

#include <string>
#include "temps.h"


class contact;

class jour;

class rdv;

class listJour {
public:
    listJour(jour *tete = nullptr);

    ~listJour();

    rdv *chercherRdv(const std::string &nom);

    rdv *chercherRdv(int d_j, int d_m, int d_a, const std::string &nom);

    int taille();

    bool ajouterRdv(int d_j, int d_m, int d_a,
                    std::string d_nom, const temps &tDeb, unsigned int d_duree, contact **d_tabContacts = nullptr);

    void ajouterContact(rdv *r, contact *c);

    void supprimerContact(rdv *r, contact *c);

    void modifHeureDeb(int d_j, int d_m, int d_a,
                       const std::string &nom, const temps &t);

    void modifHeureFin(int d_j, int d_m, int d_a,
                       const std::string &nom, const temps &t);

    void modifDuree(int d_j, int d_m, int d_a,
                    const std::string &nom, unsigned int duree);

    void modifHeureDeb(const std::string &nom, const temps &t);

    void modifHeureFin(const std::string &nom, const temps &t);

    void modifDuree(const std::string &nom, unsigned int duree);

    bool afficherContactDeRdv(...);

    bool afficherRdvDeJour(...);

private:
    jour *tete;

    void ajouterJour(int d_j, int d_m, int d_a);

    void supprimerJour(int d_j, int d_m, int d_a);

};


#endif //PROJET_STRUCTURE_DE_DONNEES_LISTRDV_H
