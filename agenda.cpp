#include <sys/param.h>
#include "agenda.h"
#include "listContact.h"
#include "listJour.h"
#include "date.h"
#include "contact.h"
#include "rdv.h"
#include "jour.h"

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
                        contact **tabContacts, int nb_c) {
    rdv *r = d_listJour.ajouterRdv(date{j, m, a}, nom, tDeb, duree, tabContacts);
    if (r == nullptr)
        return false; // rdv pas créé
    if (nb_c)
        for (int i = 0; i < nb_c; ++i) {
            d_listContact.ajouterRdv(tabContacts[i], r);
        }
    return true;
}

bool agenda::modifHeureDeb(int j, int m, int a, const std::string &nom, const temps &t) {
    return d_listJour.modifHeureDeb(date{j, m, a}, nom, t);
}

bool agenda::modifHeureFin(int j, int m, int a, const std::string &nom, const temps &t) {
    return d_listJour.modifHeureFin(date{j, m, a}, nom, t);
}

bool agenda::modifDuree(int j, int m, int a, const std::string &nom, unsigned int duree) {
    return d_listJour.modifDuree(date{j, m, a}, nom, duree);
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
    r = d_listJour.chercherRdv(date{j, m, a}, nom);
    return r != nullptr; // le rdv n'existe pas
}

bool agenda::supprimerRdv(int j, int m, int a, const std::string &nom) {
    rdv *r = d_listJour.chercherRdv(date{j, m, a}, nom);
    if (r == nullptr)
        return false; // rdv pas trouvé
    vectorLite<contact *> cs = r->getContacts();
    for (int i = 0; i < cs.size(); ++i) {
        d_listContact.supprimerRdv(cs[i], r);
    }
    d_listJour.supprimerRdv(r);
    return true;
}

bool agenda::afficherRdvDeContact(const string &nom, const string &prenom, std::ostream &out) const {
    contact *c = d_listContact.chercherContact(nom, prenom);
    if (!c)
        return false; // contact pas trouvé
    c->afficherRdvDeContact(out);
    return true;
}

bool agenda::afficherContactDeRdv(const string &nom_rdv, int j, int m, int a, std::ostream &out) const {
    rdv *r = d_listJour.chercherRdv(date{j, m, a}, nom_rdv);
    if (!r)
        return false; // rdv pas trouvé
    r->afficherContactDeRdv(out);
    return true;
}

bool agenda::afficherRdvDeJour(int j, int m, int a, std::ostream &out) const {
    jour *jo = d_listJour.chercherJour(date{j, m, a});
    if (!j)
        return false; // jour pas trouvé
    jo->afficherRdvDeJour(out);
    return true;
}


