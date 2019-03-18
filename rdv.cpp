#include "rdv.h"
#include "contact.h"
#include "temps.h"

rdv::rdv(const std::string &nom, const temps &deb, const temps &fin,/* unsigned int duree,*/ jour *j,
        const vectorLite<contact *> &tabContacts):
    d_nom{nom}, d_tDeb{deb}, d_tFin{fin}, d_j{j},d_tabContacts{tabContacts}
    {}

rdv::~rdv(){        // A FAIRE

}

//getters

std::string rdv::getNom() const{
    return d_nom;
}

temps &rdv::getDeb() const{
    return &d_tDeb;
}

temps &rdv::getFin() const{
    return &d_tFin;
}

vectorLite<contact *> &rdv::getContacts(){
    return &d_tabContacts;
}



//Autres

bool rdv::afficherContactDeRdv(std::ostream &out) const{
    if (d_tabContacts.size()==0)
        return false;

    out<<endl;
    for(int i=0; i<d_tabContacts.size(); i++)
    {
        out<<d_tabContacts[i]<<endl;
    }

    return true;
}

bool rdv::pasEnMemeTemps(rdv *r){
    if((this.d_tDeb <= r.d_tDeb)&&(this.d_tFin >= r.d_tDeb))
    {
        return false;
    }

    if((this.d_tDeb >= r.d_tDeb)&&(this.d_tDeb <= r.d_tFin))
    {
        return false;
    }

    return true;

}
