#include "contact.h"
#include "rdv.h"

contact::contact(const string &nom, const string &prenom, const string &num, const string &adresse) :
        d_nom{nom}, d_prenom{prenom}, d_num{num}, d_adresseMail{adresse} {

}