#include "contact.h"
#include "rdv.h"

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

contact &
contact::modifNum(const string &num)// pourquoi la m�thode retourne un bool alors que c'est le contact qui est retourn�
{
    d_num = num;
    return *this;
}

contact &contact::modifEmail(const string &adresse) {
    d_adresseMail = adresse;
    return *this;
}

void contact::ajouterRdv(rdv *r) {
    d_tabRdv.push_back(r);
}

