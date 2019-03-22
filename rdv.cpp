#include "rdv.h"
#include "contact.h"
#include "temps.h"

rdv::rdv(const std::string &nom, const temps &deb, const temps &fin,jour *jFin,const vectorLite<contact *> &tabContacts):
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

jour *rdv::getJourDeb() const{
        return d_j;
}

jour *rdv::getJourFin() const{
        return d_jFin;
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
    if ((this->d_tDeb <= r->d_tDeb) && (this->d_tFin >= r->d_tDeb))
    {
        return false;
    }

    if ((this->d_tDeb >= r->d_tDeb) && (this->d_tDeb <= r->d_tFin))
    {
        return false;
    }

    return true;

}


bool rdv::modifHeureDeb(const temps &t){
        vectorLite<rdv *> T;
        bool modifPossible=true;
        if (t<d_tDeb)                                       //si le rdv est avancé, on cheque les conflits
        {
            for(int i=0; i<d_tabContacts.size(); i++)       //On parcour les contacts du rdv
            {
                T = d_tabContacts[i].getTabrdv();
                for(int j=0; j<T.size();j++)                // On parcour les rdv de chaque contact
                {
                    if(!(this.pasEnMemeTemps(T[j])))
                    {
                       return false;                        //On return faux si un des contact ne peux pas
                    }
                }
            }
        }
        else
        {
            d_tDeb=t;
        return true;
        }


}

                                                                // A voir avec Valere
bool rdv::modifJourDeb(const jour* j)
{
    if (j<d_j)
        {
            for(int i=0; i<d_tabContacts.size(); i++)
            {

            }
        }
        else
        {
            d_j=j;
        return true;
        }
}

                                                                // A voir avec Valere
bool rdv::modifHeureFin(const temps &t)
{
    if (t>d_tFin)
        {
            for(int i=0; i<d_tabContacts.size(); i++)
            {

            }
        }
        else
        {
            d_tFin=t;
        return true;
        }
}
                                                                // A voir avec Valere
bool rdv::modifJourFin(const jour* j)
{
    if (j>d_jfin)
        {
            for(int i=0; i<d_tabContacts.size(); i++)
            {

            }
        }
        else
        {
            d_jFin=j;
        return true;
        }
}

bool rdv::ajouterContact(contact *c){
    vectorLite<rdv *> T() = contact::getTabrdv();
    for(int i = 0; i<T.size();i++)
    {
        if (pasEnMemeTemps(T[i]))
        {
            i++
        }
        else
        {
            return false;
        }
    }
    d_tabContacts.push_back(c);
    return true;
}

bool rdv::supprimeContact(contact *c)
{
    int i = 0;
    while(i<d_tabContacts.size()&&!(c==d_tabContacts[i]))
    {
        i++;
    }
    if(i<d_tabContacts.size())
    {
        d_tabContacts.supprimer(i)
        return true;
    }
    return false;
}
