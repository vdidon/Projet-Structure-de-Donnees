
#include "listContact.h"
#include "contact.h"

/** Constrcuteur */

listContact::listContact(contact *tete) : d_tete{tete} {}

/** Destrcuteur */

listContact::~listContact() {
    contact *c = d_tete;
    while (c != nullptr) {
        contact *n = c;
        c = c->d_suiv;
        delete n;
    }
}

/** Ajout en tete d'un nouveau contact */

contact *
listContact::ajouterContact(const string &nom, const string &prenom, const string &num, const string &adresseMail) {
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
    while (c != nullptr && (c.d_nom != nom && d.d_prenom != prenom)) {
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
        if (as.getTabrdv().size() == 0) {
            if (d_tete.d_nom == as.d_nom && d_tete.d_prenom == as.d_prenom) {
                contact *c = d_tete;
                d_tete = c->d_suiv;
                delete c;
            } else {
                contact *precC = nullptr, *c = d_tete;
                while (c != nullptr && (c.d_nom != nom && d.d_prenom != prenom)) {
                    precC = c;
                    c = c->d_suiv;
                }
                precC->d_suiv = c->d_suiv;
                delete c;
            }
            return true;
        } else {
            //cout<<"La personne ne peut pas etre suprim��, car elle a un rdv\n";
            return false;
        }
    }
    return false;
}
