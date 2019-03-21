#include "listJour.h"
#include "jour.h"
#include "rdv.h"

listJour::listJour(jour *tete) : d_tete{tete} {

}

listJour::~listJour() {
    jour *suiv = d_tete->suiv;
    while (suiv != nullptr) {
        delete d_tete;
        d_tete = suiv;
        suiv = d_tete->suiv;
    }
    delete d_tete;
}

rdv *listJour::chercherRdv(const date &d, const std::string &nom) const {
    jour *j = chercherJour(d);
    if (!j)
        return nullptr;
    return j->chercherRdv(nom);
}

jour *listJour::chercherJour(const date &d) const {
    jour *j = d_tete;
    while (j != nullptr && d < j->d_date) {
        j = j->suiv;
    }
    return (j == nullptr || d > j->d_date) ? nullptr : j;
}

int listJour::taille() {
    int res;
    jour *j = d_tete;
    for (res = 0; d_tete; ++res, d_tete = d_tete->suiv);
    return res;
}

rdv *listJour::ajouterRdv(const date &d, std::string nom, const temps &tDeb, const temps &tFin, const date &dFin, const
vectorLite<contact *> &tabContacts) {
    jour *j = d_tete;
    jour *pre = nullptr;
    jour *jFin;
    while (j != nullptr && d < j->d_date) {
        pre = j;
        j = j->suiv;
    }
    if (j == nullptr || j->d_date > d) {
        j = ajouterJour(d, pre, j);
    }
    if (dFin != d) {
        jFin = j;
        //jour *pre = nullptr;
        while (jFin != nullptr && dFin < jFin->d_date) {
            pre = jFin;
            jFin = jFin->suiv;
        }
        if (jFin == nullptr || j->d_date > d) {
            jFin = ajouterJour(dFin, pre, jFin);
        }
    } else {
        jFin = j;
    }
    rdv *r = j->ajouterRdv(nom, tDeb, tFin, jFin, tabContacts);
    if (dFin != d) {
        j = j->suiv;
        while (j != jFin) {
            j->ajouterRdvMultiJour(r);
        }
        jFin->ajouterRdvMultiJour(r);
    }
}

void listJour::ajouterContact(rdv *r, contact *c) {
    jour::ajouterContact(r, c);
}

void listJour::supprimerContact(rdv *r, contact *c) {
    jour::supprimerContact(r, c);
}

bool listJour::modifHeureDeb(const date &d, const std::string &nom, const temps &t) {
    jour *j = chercherJour(d);
    if (!j)
        return false;
    j->modifHeureDeb(nom, t);
}

/*bool listJour::modifDuree(const date &d, const std::string &nom, unsigned int duree) {
    jour *j = chercherJour(d);
    if (!j)
        return false;
    j->modifDuree(nom, duree);
}*/


void listJour::supprimerRdv(rdv *r) {
    jour *j = r->getJourDeb();
    jour::supprimerRdv(r);
    if (j->d_tete)
        supprimerJour(j->d_date); // gros gros problème : pas opti x)
}

jour *listJour::ajouterJour(const date &d, jour *pre, jour *suiv) {
    if (pre) {
        pre->suiv = new jour{d};
        pre->suiv->suiv = suiv;
        return pre->suiv;
    } else {
        d_tete = new jour{d};
        d_tete->suiv = suiv;
        return d_tete;
    }
}

void listJour::supprimerJour(jour *pre, jour *suiv) {
    if (pre) {
        delete pre->suiv;
        pre->suiv = suiv;
    } else {
        delete d_tete;
        d_tete = suiv;
    }
}

bool listJour::estVide() {
    return d_tete == nullptr;
}

void listJour::supprimerJour(const date &d) {
    jour *prej = d_tete;
    while (prej->suiv->d_date < d)
        prej = prej->suiv;
    jour *j = prej->suiv;
    prej->suiv = j->suiv;
    delete j;
}

bool listJour::modifHeureFin(const date &d, const std::string &nom, const temps &t) {
    rdv *r = chercherRdv(d, nom);
    if (!r)
        return false;
    jour *j = r->getJourDeb();
    jour *jFin = r->getJourFin();
    if (!j->modifHeureFin(nom, t, jFin))
        return false;
}

bool listJour::modifJourDeb(const date &d, const date &newd, const std::string &nom) {
	jour *j = chercherJour(d);
	if (!j)
		return false;
	j->modifJourDeb();
}

bool listJour::modifJourFin(const date &d, const date &newd, const std::string &nom) {
	return false;
}
