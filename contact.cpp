#include "contact.h"
#include "rdv.h"
#include "temps.h" // pour ajouter un rdv à un contact (test si il est dispo)

contact::contact(const string &nom, const string &prenom, const string &num, const string &adresse) :
        d_nom{nom}, d_prenom{prenom}, d_num{num}, d_adresseMail{adresse} {

}

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

void
contact::modifNum(const string &num)// pourquoi la m�thode retourne un bool alors que c'est le contact qui est retourn�
{
    d_num = num;
}

void contact::modifEmail(const string &adresse) {
    d_adresseMail = adresse;
}

bool contact::ajouterRdv(rdv *r) {
    d_tabRdv.push_back(r);
}

