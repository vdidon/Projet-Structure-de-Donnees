#include "contact.h"
#include "rdv.h"
#include "temps.h" // pour ajouter un rdv à un contact (test si il est dispo)
#include "ostream"
contact::contact(const string &nom, const string &prenom, const string &num, const string &adresse) :
		d_nom{nom}, d_prenom{prenom}, d_num{num}, d_adresseMail{adresse}, d_suiv{nullptr}
{}

string contact::getNom() const {
    return d_nom;
}

string contact::getPrenom() const {
    return d_prenom;
}

string contact::getNum() const {
    return d_num;
}

string contact::getAdresse() const {
    return d_adresseMail;
}

vectorLite<rdv *> &contact::getTabrdv() {
    return d_tabRdv;
}

void contact::modifNum(const string &num)// pourquoi la m�thode retourne un bool alors que c'est le contact qui est retourn�
{
    d_num = num;
}

void contact::modifEmail(const string &adresse) {
    d_adresseMail = adresse;
}

bool contact::operator==(const contact &c) const
{
    return (d_nom == c.d_nom && d_prenom == c.d_prenom);
}

bool contact::ajouterRdv(rdv *r)
{
    for(int i=0; i<d_tabRdv.size(); i++)
    {
        if(!d_tabRdv[i]->pasEnMemeTemps(r))
        {
            return false;
        }
    }
    d_tabRdv.push_back(r);
    return true;
}

bool contact::supprimerRdv(rdv *r)
{
    if (r)
    {
        int i=0;
        while (i<d_tabRdv.size() && d_tabRdv[i] != r)
        {
            i++;
        }
	    d_tabRdv.supprimer(i);
        return true;
    }
    return false;
}


void contact ::afficherRdvDeContact(std::ostream & os)
{
	os << "Nom : " << d_nom << endl;
	os << "Prénom : " << d_prenom << endl;
	os << "Numero : " << d_num << endl;
	os << "Email : " << d_adresseMail << endl << endl;
	if (d_tabRdv.size() == 0) {
		os << "Pas de rdv" << endl;
	} else
    {
	    for (int i = 0; i < d_tabRdv.size(); i++) {
		    os << endl;
		    d_tabRdv[i]->afficherRdv(os);
		    os << endl;
	    }
    }
}


contact::~contact()
{

}
