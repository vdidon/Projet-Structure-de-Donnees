#ifndef PROJET_STRUCTURE_DE_DONNEES_AGENDA_H
#define PROJET_STRUCTURE_DE_DONNEES_AGENDA_H

#include "listJour.h"
#include "listContact.h"
#include "vectorLite.h"
#include <ostream>

class agenda {
public:
    agenda();
    //agenda(const listContact &c,const listJour &j);

    ~agenda();

    bool ajouterContact(const string &nom, const string &prenom, const string &num = "", const string &adresseMail = "");

    bool supprimerContact(const string &nom, const string &prenom);

    bool modifNum(const string &nom, const string &prenom, const string &num);

    bool modifEmail(const string &nom, const string &prenom, const string &adresse);

    bool
    ajouterRdv(int j, int m, int a, const std::string &nom, int h, int min, int fj, int fm, int fa, int fh, int fmin,
               const vectorLite<contact *> &tabContacts = vectorLite<contact *>{});

    bool modifHeureDeb(int j, int m, int a, const std::string &nom, int h, int min);

    bool modifHeureFin(int j, int m, int a, const std::string &nom, int h, int min);

	bool modifJourDeb(int j, int m, int a, const std::string &nom, int newj, int newm, int newa);

	bool modifJourFin(int j, int m, int a, const std::string &nom, int newj, int newm, int newa);

    /*bool modifDuree(int j, int m, int a,
                    const std::string &nom, unsigned int duree);*/

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

	bool
	contactEstDispo(string nom, string prenom, int dj, int dm, int da, int dh, int dmin, int fj, int fm, int fa, int fh,
	                int fmin) const;

private:
    listJour d_listJour;
    listContact d_listContact;

    bool chercherContactEtRdv(const string &nom, const string &prenom,
                              const string &nom_rdv, int j, int m, int a,
                              contact *&c, rdv *&r);

    bool testContact(const string &nom, const string &prenom);

    bool testJour(int j, int m, int a);

    bool testRdv(const string &nom);

};


#endif //PROJET_STRUCTURE_DE_DONNEES_AGENDA_H
