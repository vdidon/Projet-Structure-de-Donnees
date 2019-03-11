#ifndef PROJET_STRUCTURE_DE_DONNEES_AGENDA_H
#define PROJET_STRUCTURE_DE_DONNEES_AGENDA_H

#include "listJour.h"
#include "listContact.h"
#include <ostream>

class agenda {
    agenda();

    //agenda(const listContact &c,const listJour &j);

    ~agenda();

    bool ajouterContact(const string &nom, const string &prenom, const string &num = "", const string &adresseMail = "");

    bool supprimerContact(const string &nom, const string &prenom);

    bool modifNum(const string &nom, const string &prenom, const string &num);

    bool modifEmail(const string &nom, const string &prenom, const string &adresse);

    bool ajouterRdv(int j, int m, int a, const std::string &nom, const temps &tDeb, unsigned int duree,
                    contact **tabContacts, int nb_c);

    bool modifHeureDeb(int j, int m, int a,
                       const std::string &nom, const temps &t);

    bool modifHeureFin(int j, int m, int a,
                       const std::string &nom, const temps &t);

    bool modifDuree(int j, int m, int a,
                    const std::string &nom, unsigned int duree);

    bool ajouterContactARdv(const string &nom, const string &prenom,
                            const string &nom_rdv,
                            int j, int m, int a);

    bool supprimerContactARdv(const string &nom, const string &prenom,
                              const string &nom_rdv,
                              int j, int m, int a);

    bool supprimerRdv(int j, int m, int a, const std::string &nom);

    bool afficherRdvDeContact(const string &nom, const string &prenom, std::ostream &out) const;

    bool afficherContactDeRdv(const string &nom_rdv, int j, int m, int a, std::ostream &out) const;

    bool afficherRdvDeJour(int j, int m, int a, std::ostream &out) const;


private:
    listJour d_listJour;
    listContact d_listContact;

    bool chercherContactEtRdv(const string &nom, const string &prenom, const string &nom_rdv, contact *&c, rdv *&r,
                              int j, int m, int a);

};


#endif //PROJET_STRUCTURE_DE_DONNEES_AGENDA_H
