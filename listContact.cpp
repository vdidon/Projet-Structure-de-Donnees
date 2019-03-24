#include "listContact.h"
#include "contact.h"

/** Constrcuteur */

listContact::listContact(contact *tete) : d_tete{tete} {}

/** Destrcuteur */

listContact::~listContact() {
    if (d_tete) {
        contact *c = d_tete;
        while (c->d_suiv != nullptr) {
            contact *n = c;
            c = c->d_suiv;
            delete n;
        }
        delete c;
    }
}

/** Ajout en tete d'un nouveau contact */

contact * listContact::ajouterContact(const string &nom, const string &prenom, const string &num, const string &adresseMail) {
    contact *n = new contact(nom, prenom, num, adresseMail);
    if (d_tete == nullptr) {
        d_tete = n;
    } else {
        n->d_suiv = d_tete;
        d_tete = n;
    }
    return n;
}

/** Nombre de contact */

int listContact::taille() {
    int nb = 0;
    contact *c = d_tete;
    while (c != nullptr) {
        nb++;
        c = c->d_suiv;
    }
    return nb;
}

/** Rechercher un contact */

contact *listContact::chercherContact(const string &nom, const string &prenom) const {
    contact *c = d_tete;
    while (c != nullptr && (c->d_nom != nom && c->d_prenom != prenom)) {
        c = c->d_suiv;
    }
    if (c == nullptr) {
        return nullptr;
    } else {
        return c;
    }
}

/** supprimer un contact */

bool listContact::supprimerContact(const string &nom, const string &prenom) {
    contact *as = chercherContact(nom, prenom);
    if (as != nullptr) {
        if (as->d_tabRdv.size() == 0) {
            if (d_tete == as) {
                contact *c = d_tete;
                d_tete = c->d_suiv;
                delete c;
            } else {
                contact *precC = nullptr, *c = d_tete;
                while (c != as) {
                    precC = c;
                    c = c->d_suiv;
                }
                precC->d_suiv = c->d_suiv;
                delete c;
            }
            return true;
        } else {
            return false;
        }
    }
    return false;
}

/** modifie le numero d'un contact */

bool listContact::modifieNum(const string &nom, const string &prenom, const string &num)
{
    contact *am = chercherContact(nom,prenom);
    if (am)
    {
        am->modifNum(num);
        return true;
    }
    else return false;
}

/** modifie l'adresse mail d'un contact */

bool listContact::modifieEmail(const string &nom, const string &prenom, const string &adresse)
{
    contact *am = chercherContact(nom,prenom);
    if (am)
    {
        am->modifEmail(adresse);
        return true;
    }
    else return false;
}

/** ajout un contact au rdv */

bool listContact::ajouteRdv(contact *c, rdv *r)
{
    return(c->ajouterRdv(r));
}

/** supprime un rdv donné */

bool listContact::supprimeRdv(contact *c, rdv *r)
{
    return(c->supprimerRdv(r));
}

/** affiche les rdv d'un contact */

bool listContact::afficherRdvDeContact(const string &nom, const string &prenom, ostream & os) const
{
    contact *af = chercherContact(nom,prenom);
    if (af)
    {
        af->afficherRdvDeContact(os);
        return true;
    }
    else return false;
}
