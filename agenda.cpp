#include <sys/param.h>
#include "agenda.h"
#include "listContact.h"
#include "listJour.h"

agenda::agenda() : d_listJour{}, d_listContact{} {}

agenda::~agenda() = default;

bool agenda::ajouterContact(const string &nom, const string &prenom, const string &num, const string &adresseMail) {
    return d_listContact.ajouterContact(nom, prenom, num, adresseMail);
}

bool agenda::supprimerContact(const string &nom, const string &prenom) {
    return d_listContact.supprimerContact(nom, prenom);
}

bool agenda::modifNum(const string &nom, const string &prenom, const string &num) {
    return d_listContact.modifNum(nom, prenom, num);
}

bool agenda::modifEmail(const string &nom, const string &prenom, const string &adresse) {
    return d_listContact.modifEmail(nom, prenom, adresse);
}

bool agenda::ajouterRdv(int j, int m, int a, const std::string &nom, const temps &tDeb, unsigned int duree,
                        contact **tabContacts, int nbTab) {
    rdv *r = d_listJour.ajouterRdv(j, m, a, nom, tDeb, duree, tabContacts);
    if (r == nullptr)
        return false; // rdv pas créé
    if (!tabContacts)
        for (int i = 0; i < nbTab; ++i) {
            d_listContact.ajouterRdv(tabContacts[i], r);
        }
}

void agenda::modifHeureDeb(int j, int m, int a, const std::string &nom, const temps &t) {
    return d_listJour.modifHeureDeb(j, m, a, nom, t);
}

void agenda::modifHeureFin(int j, int m, int a, const std::string &nom, const temps &t) {
    return d_listJour.modifHeureFin(j, m, a, nom, t);
}

void agenda::modifDuree(int j, int m, int a, const std::string &nom, unsigned int duree) {
    return d_listJour.modifDuree(j, m, a, nom, duree);
}

void agenda::modifHeureDeb(const std::string &nom, const temps &t) {
    return d_listJour.modifHeureDeb(nom, t);
}

void agenda::modifHeureFin(const std::string &nom, const temps &t) {
    return d_listJour.modifHeureFin(nom, t);
}

void agenda::modifDuree(const std::string &nom, unsigned int duree) {
    return d_listJour.modifDuree(nom, duree);
}

bool agenda::ajouterContactARdv(const string &nom, const string &prenom, const string &nom_rdv) {
    contact *c;
    rdv *r;
    if (!chercherContactEtRdv(nom, prenom, nom_rdv, c, r))
        return false;
    d_listContact.ajouterRdv(c, r);
    d_listJour.ajouterContact(r, c);
    return true;
}

bool agenda::ajouterContactARdv(const string &nom, const string &prenom, const string &nom_rdv, int j, int m, int a) {
    contact *c;
    rdv *r;
    if (!chercherContactEtRdv(nom, prenom, nom_rdv, c, r, j, m, a))
        return false;
    d_listContact.ajouterRdv(c, r);
    d_listJour.ajouterContact(r, c);
    return true;
}

bool agenda::supprimerContactARdv(const string &nom, const string &prenom, const string &nom_rdv) {
    contact *c;
    rdv *r;
    if (!chercherContactEtRdv(nom, prenom, nom_rdv, c, r))
        return false;
    d_listContact.supprimerRdv(c, r);
    d_listJour.supprimerContact(r, c);
    return true;
}

bool agenda::supprimerContactARdv(const string &nom, const string &prenom, const string &nom_rdv, int j, int m, int a) {
    contact *c;
    rdv *r;
    if (!chercherContactEtRdv(nom, prenom, nom_rdv, c, r, j, m, a))
        return false;
    d_listContact.supprimerRdv(c, r);
    d_listJour.supprimerContact(r, c);
    return true;
}


bool agenda::chercherContactEtRdv(const string &nom, const string &prenom, const string &nom_rdv, contact *&c, rdv *&r,
                                  int j, int m, int a) {
    c = d_listContact.chercherContact(nom, prenom);
    if (c)
        return false; // le contact n'existe pas
    if (j == 0) // pas de date
        r = d_listJour.chercherRdv(nom);
    r = d_listJour.chercherRdv(j, m, a, nom);
    return r != nullptr; // le rdv n'existe pas
}

bool agenda::supprimerRdv(int j, int m, int a, const std::string &nom) {
    rdv *r = d_listJour.chercherRdv(j, m, a, nom);
    contact **cs = r->getContacts();
    for (int i = 0; i < MAX; ++i) {
        d_listContact.supprimerRdv(cs[i], r);
    }
    d_listJour.supprimerRdv(r);
}

bool agenda::supprimerRdv(const std::string &nom) {
    rdv *r = d_listJour.chercherRdv(nom);
    contact **cs = r->getContacts();
    for (int i = 0; i < MAX; ++i) {
        d_listContact.supprimerRdv(cs[i], r);
    }
    d_listJour.supprimerRdv(r);
}

bool agenda::afficherRdvDeContact(const string &nom, const string &prenom) {
    contact *c = d_listContact.chercherContact(nom, prenom);
    if (!c)
        return false;
    c->afficherRdvDeContact();
    return true;
}

bool agenda::afficherContactDeRdv(const string &nom_rdv, int j, int m, int a) {
    rdv *r = d_listJour.chercherRdv(j, m, a, nom_rdv);
    if (!r)
        return false;
    r->afficherContactDeRdv();
}

bool agenda::afficherRdvDeJour(int j, int m, int a) {
    jour *jo = d_listJour.chercherJour(j, m, a);
    if (!j)
        return false;
    jo->afficherRdvDeJour();
}


