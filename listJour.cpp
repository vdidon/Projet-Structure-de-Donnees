#include "listJour.h"

listJour::listJour(jour *tete) : d_tete{tete} {

}

listJour::~listJour() {
	if (d_tete) {
		jour *suiv = d_tete->suiv;
		while (suiv != nullptr) {
			delete d_tete;
			d_tete = suiv;
			suiv = d_tete->suiv;
		}
		delete d_tete;
	}
}

rdv *listJour::chercherRdv(const date &d, const std::string &nom) const {
    jour *j = chercherJour(d);
    if (!j)
        return nullptr;
    return j->chercherRdv(nom);
}

jour *listJour::chercherJour(const date &d) const {
    jour *j = d_tete;
	while (j != nullptr && d > j->d_date) {
        j = j->suiv;
    }
	return (j == nullptr || d < j->d_date) ? nullptr : j;
}

int listJour::taille() {
    int res;
    jour *j = d_tete;
    for (res = 0; j; ++res, j = j->suiv);
    return res;
}

rdv *listJour::ajouterRdv(const date &d, std::string nom, const temps &tDeb, const temps &tFin, const date &dFin, const
vectorLite<contact *> &tabContacts) {
    jour *j = d_tete;
    jour *pre = nullptr;
    jour *jFin;
	while (j != nullptr && d > j->d_date) {
        pre = j;
        j = j->suiv;
    }
    if (j == nullptr || j->d_date > d) {
        j = ajouterJour(d, pre, j);
    }
    if (dFin != d) {
        jFin = j;
        //jour *pre = nullptr;
	    while (jFin != nullptr && jFin->d_date < dFin) {
            pre = jFin;
            jFin = jFin->suiv;
        }
	    if (jFin == nullptr || jFin->d_date > d) {
            jFin = ajouterJour(dFin, pre, jFin);
        }
    } else {
        jFin = j;
    }
	rdv *r = j->ajouterRdv(nom, tDeb, tFin, j, jFin, tabContacts);
    if (dFin != d) {
        j = j->suiv;
        while (j != jFin) {
            j->ajouterRdvMultiJour(r);
        }
        jFin->ajouterRdvMultiJour(r);
    }
	return r;
}

bool listJour::ajouterContact(rdv *r, contact *c) {
	return jour::ajouterContact(r, c);
}

void listJour::supprimerContact(rdv *r, contact *c) {
    jour::supprimerContact(r, c);
}

bool listJour::modifHeureDeb(const date &d, const std::string &nom, const temps &t) {
    jour *j = chercherJour(d);
    if (!j)
        return false;
	return j->modifHeureDeb(nom, t);
}

/*bool listJour::modifDuree(const date &d, const std::string &nom, unsigned int duree) {
    jour *j = chercherJour(d);
    if (!j)
        return false;
    j->modifDuree(nom, duree);
}*/


void listJour::supprimerRdv(rdv *r) {
    jour *j = r->getJourDeb();
	jour *jFin = r->getJourFin();
	if (j != jFin) {
		//jour *jDeb = j;
		jour *pre = j;
		j = j->suiv;
		do {
			int i;
			for (i = 0; j->d_rdvMultiJours[i] != r; ++i);
			j->d_rdvMultiJours.supprimer(i);
			if (!j->d_tete && j->d_rdvMultiJours.size())
				supprimerJour(pre, j->suiv);
			pre = pre->suiv;
			j = pre->suiv;

		} while (j && j != jFin);
	}
	j = r->getJourDeb();
	jour::supprimerRdv(r);
	if (!j->d_tete)
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
    jour* j = chercherJour(d);
    if (!j)
        return false;
	return j->modifHeureFin(nom, t);
}

bool listJour::modifJourDeb(const date &d, const date &newd, const std::string &nom) {
	if (d == newd)
		return true;
	jour *j = chercherJour(d);
	if (!j)
		return false;

	jour *new_j = d_tete;
	jour *pre = nullptr;
	jour *suiv = nullptr;
	while (new_j != nullptr && newd > new_j->d_date) {
		pre = new_j;
		new_j = new_j->suiv;
	}
	if (new_j == nullptr || new_j->d_date != newd)
		new_j = ajouterJour(newd, pre, new_j);

	if (j->modifJourDeb(nom, new_j)) {
		rdv *r = chercherRdv(d, nom);
		j->supprimerRdvSansDelete(r);
		if (!j->d_tete) {
			pre = d_tete;
			while (pre->suiv && pre->suiv->d_date < d)
				pre = pre->suiv;
			pre->suiv = j->suiv;
			delete j;
			j = pre; //jour précédent
		}
		new_j->ajouterRdvSansNew(r);
		if (newd < d) {
			do {
				new_j = new_j->suiv;
				new_j->ajouterRdvMultiJour(r);
			} while (new_j->d_date < j->d_date);
		} else //newd>d
		{
			do {
				pre = j;
				j = j->suiv;
				j->supprimerRdvMultiJour(r);
				if (!j->d_tete && !j->d_rdvMultiJours.size()) {
					suiv = j->suiv;
					supprimerJour(pre, j->suiv);
					j = suiv;
				}
			} while (new_j->d_date > j->d_date);
		}
		return true;
	}
	return false;
}

bool listJour::modifJourFin(const date &dDeb, const date &newd, const std::string &nom) {
	rdv *r = chercherRdv(dDeb, nom);
	if (!r)
		return false;
	jour *j = r->getJourDeb();
	if (!j)
		return false;
	date d = r->getJourFin()->getDate();
	if (d == newd)
		return true;
	jour *new_j = d_tete;
	jour *pre = nullptr;
	jour *suiv = nullptr;
	while (new_j != nullptr && newd > new_j->d_date) {
		pre = new_j;
		new_j = new_j->suiv;
	}
	if (new_j == nullptr || new_j->d_date != newd)
		new_j = ajouterJour(newd, pre, new_j);

	if (j->modifJourFin(nom, new_j)) {
		//rdv *r = chercherRdv(d, nom);
		/*j->supprimerRdvSansDelete(r);
		if (!j->d_tete) {
			jour *suiv = j->suiv;
			pre = d_tete;
			while (pre->suiv && pre->suiv->d_date < d)
				pre = pre->suiv;
			if (j == d_tete)
				d_tete = j->suiv;
			else
				pre->suiv = j->suiv;
			delete j;
			j = suiv;
		}
		new_j->ajouterRdvSansNew(r);*/
		if (newd < d) {
			do {
				pre = new_j;
				new_j = new_j->suiv;
				new_j->supprimerRdvMultiJour(r);
				if (!new_j->d_tete && !new_j->d_rdvMultiJours.size()) {
					suiv = new_j->suiv;
					supprimerJour(pre, new_j->suiv);
					new_j = suiv;
				}
			} while (new_j->d_date < j->d_date);
		} else //newd>d
		{
			do {
				j = j->suiv;
				j->ajouterRdvMultiJour(r);
			} while (new_j->d_date > j->d_date);
		}
		return true;
	}
	return false;
}

bool listJour::afficherContactDeRdv(const date &d, const std::string &nom, std::ostream &out) const {
	jour *j = chercherJour(d);
	if (!j)
		return false;
	return j->afficherContactDeRdv(nom, out);
}

bool listJour::afficherRdvDeJour(const date &d, std::ostream &out) const {
	jour *j = chercherJour(d);
	if (!j)
		return false;
	return j->afficherRdvDeJour(out);
}
