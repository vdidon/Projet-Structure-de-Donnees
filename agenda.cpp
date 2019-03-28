//#include <sys/param.h>
#include "agenda.h"

agenda::agenda() : d_listJour{}, d_listContact{} {}

agenda::~agenda() = default;

bool agenda::ajouterContact(const string &nom, const string &prenom, const string &num, const string &adresseMail) {
	return static_cast<bool> (d_listContact.ajouterContact(nom, prenom, num, adresseMail));
}

bool agenda::supprimerContact(const string &nom, const string &prenom) {
	if (!testContact(nom, prenom))
        return false;
    return d_listContact.supprimerContact(nom, prenom);
}

bool agenda::modifNum(const string &nom, const string &prenom, const string &num) {
	return d_listContact.modifieNum(nom, prenom, num);

}

bool agenda::modifEmail(const string &nom, const string &prenom, const string &adresse) {
	return d_listContact.modifieEmail(nom, prenom, adresse);
}

bool agenda::ajouterRdv(int j, int m, int a, const std::string &nom, int h, int min, int fj, int fm, int fa, int fh,
                        int fmin,
                        const vectorLite<contact *> &tabContacts) {
    rdv *r = d_listJour.ajouterRdv(date{j, m, a}, nom, temps{static_cast<short>(h), static_cast<short>(min)},
                                   temps{static_cast<short>(fh), static_cast<short>(fmin)}, date{fj, fm, fa},
                                   tabContacts);
    if (r == nullptr)
        return false; // rdv pas créé
	if (tabContacts.size())
        for (int i = 0; i < tabContacts.size(); ++i) {
	        d_listContact.ajouteRdv(tabContacts[i], r);
        }
    return true;
}

bool agenda::modifHeureDeb(int j, int m, int a, const std::string &nom, int h, int min) {
    return d_listJour.modifHeureDeb(date{j, m, a}, nom, temps{static_cast<short>(h), static_cast<short>(min)});
}

/*bool agenda::modifDuree(int j, int m, int a, const std::string &nom, unsigned int duree) {
    return d_listJour.modifDuree(date{j, m, a}, nom, duree);
}*/

bool agenda::ajouterContactARdv(const string &nom, const string &prenom, const string &nom_rdv, int j, int m, int a) {
	if (!testJour(j, m, a))
		return false;
	contact *c;
    rdv *r;
    if (!chercherContactEtRdv(nom, prenom, nom_rdv, j, m, a, c, r))
        return false;
	if (!d_listJour.ajouterContact(r, c))
        return false; // contact pas dispo
	d_listContact.ajouteRdv(c, r);
    return true;
}

bool agenda::supprimerContactARdv(const string &nom, const string &prenom, const string &nom_rdv, int j, int m, int a) {
    contact *c;
    rdv *r;
    if (!chercherContactEtRdv(nom, prenom, nom_rdv, j, m, a, c, r))
        return false;
	if (!d_listContact.supprimeRdv(c, r))
        return false; // le contact n'a pas ce rdv
    d_listJour.supprimerContact(r, c);
    return true;
}


bool agenda::chercherContactEtRdv(const string &nom, const string &prenom, const string &nom_rdv, int j, int m, int a,
                                  contact *&c,
                                  rdv *&r) {
    c = d_listContact.chercherContact(nom, prenom);
	if (!c)
        return false; // le contact n'existe pas
	r = d_listJour.chercherRdv(date{j, m, a}, nom_rdv);
    return r != nullptr; // le rdv n'existe pas
}

bool agenda::supprimerRdv(int j, int m, int a, const std::string &nom) {
	if (!testJour(j, m, a) || !testRdv(nom))
        return false; // date ou rdv pas bon
    rdv *r = d_listJour.chercherRdv(date{j, m, a}, nom);
    if (r == nullptr)
        return false; // rdv pas trouvé
    vectorLite<contact *> cs = r->getContacts();
    for (int i = 0; i < cs.size(); ++i) {
	    d_listContact.supprimeRdv(cs[i], r);
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
	if (!jo)
        return false; // jour pas trouvé
    jo->afficherRdvDeJour(out);
    return true;
}

bool agenda::testContact(const string &nom, const string &prenom) {
    return !nom.empty() && !prenom.empty();
}

bool agenda::testJour(int j, int m, int a) {
    return !(j < 1 || m < 1 || j > 31 || m > 12);
}

bool agenda::testRdv(const string &nom) {
    return !nom.empty();
}

bool agenda::modifHeureFin(int j, int m, int a, const std::string &nom, int h, int min) {
    return d_listJour.modifHeureFin(date{j, m, a}, nom, temps{static_cast<short>(h), static_cast<short>(min)});
}

bool agenda::modifJourDeb(int j, int m, int a, const std::string &nom, int newj, int newm, int newa) {
	return d_listJour.modifJourDeb(date{j, m, a}, date{newj, newm, newa}, nom);
}

bool agenda::modifJourFin(int j, int m, int a, const std::string &nom, int newj, int newm, int newa) {
	return d_listJour.modifJourFin(date{j, m, a}, date{newj, newm, newa}, nom);
}

bool
agenda::contactEstDispo(string nom, string prenom, int dj, int dm, int da, int dh, int dmin, int fj, int fm, int fa,
                        int fh, int fmin) const {
	contact *c = d_listContact.chercherContact(nom, prenom);

	jour tmp_j = jour{date{dj, dm, da}};
	jour tmp_jfin = jour{date{fj, fm, fa}};
	rdv tmp_r{std::string("tmp"), temps{static_cast<short>(dh), static_cast<short>(dmin)},
	          temps{static_cast<short>(fh),
	                static_cast<short>(fmin)},
	          &tmp_j, &tmp_jfin};

	if (!c)
		return false;
	auto rs = c->getTabrdv();
	for (int i = 0; i < rs.size(); ++i) {
		if (!rs[i]->pasEnMemeTemps(&tmp_r))
			return false;
	}
	return true;
}


