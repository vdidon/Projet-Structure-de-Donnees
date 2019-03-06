#ifndef PROJET_STRUCTURE_DE_DONNEES_AGENDA_H
#define PROJET_STRUCTURE_DE_DONNEES_AGENDA_H

#include "listJour.h"
#include "listContact.h"

class agenda {
    agenda();

    ~agenda();

    bool ajouterContact(const string &nom, const string &prenom, const string &num = "", const string &adresseMail = "");

    bool supprimerContact(const string &nom, const string &prenom);

    bool modifNum(const string &nom, const string &prenom, const string &num);

    bool modifEmail(const string &nom, const string &prenom, const string &adresse);

    bool ajouterRdv(int d_j, int d_m, int d_a,
                    std::string d_nom, const temps &tDeb, unsigned int d_duree,
                    contact **d_tabContacts = nullptr);

    void modifHeureDeb(int d_j, int d_m, int d_a,
                       const std::string &nom, const temps &t);

    void modifHeureFin(int d_j, int d_m, int d_a,
                       const std::string &nom, const temps &t);

    void modifDuree(int d_j, int d_m, int d_a,
                    const std::string &nom, unsigned int duree);

    void modifHeureDeb(const std::string &nom, const temps &t);

    void modifHeureFin(const std::string &nom, const temps &t);

    void modifDuree(const std::string &nom, unsigned int duree);

    bool ajouterContactARdv(const string &nom, const string &prenom,
                            const string &nom_rdv);

    bool ajouterContactARdv(const string &nom, const string &prenom,
                            const string &nom_rdv, int d_j, int d_m, int d_a);

    bool supprimerContactARdv(const string &nom, const string &prenom,
                              const string &nom_rdv);

    bool supprimerContactARdv(const string &nom, const string &prenom,
                         const string &nom_rdv,
                         int d_j, int d_m, int d_a);

    bool afficherRdvDeContact(...);

    bool afficherContactDeRdv(...);

    bool afficherRdvDeJour(...);


private:
    listJour d_listJour;
    listContact d_listContact;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_AGENDA_H
