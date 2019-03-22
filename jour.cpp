#include "jour.h"
#include "rdv.h"
#include "date.h"

jour::jour(const date &d) : d_date{d}
    {}

jour::~jour()
    {
      rdv *r = d_tete;
      while(r!=nullptr)
      {
          rdv *rTemp=r;
          r = r->d_suiv;
          delete rTemp;
      }
    }

/*Getters*/
int jour::getJour() const{
    return d_date.j;
}

int jour::getMois() const{
    return d_date.m;
}

int jour::getAnnee() const{
    return d_date.a;
}

date jour::getDate() const {
    return d_date;
}

int jour::taille() const{
    rdv *r=d_tete;
    int i=0;
    while(r!=d_tete)
    {
        r = r->d_suiv;
        i++;
    }
    return i;
}

rdv *jour::ajouterRdv(const std::string &nom, const temps &tDeb, const temps &tFin, jour *jFin, const vectorLite<contact *> &tabContacts)
{
    rdv*n= new rdv(nom,tDeb,jFin, tabContacts);
    if(d_tete==nullptr)                         //cas liste nulle
    {
        d_tete=n;
    }
    else if(tDeb<d_tete->d_tDeb)                //Insertion en tete
    {
        n->d_suiv=d_tete;
        d_tete=n;
    }
    else
    {
        rdv*cl=d_tete, *prec=nullptr;
        while(cl!=nullptr && cl->d_tDeb<tDeb)
        {
            prec=cl;
            cl=cl->d_suiv;
        }
        if(cl!=nullptr)
        {
            n->d_suiv=cl;
            prec->d_suiv=n;
        }
        else
        {
            prec->d_suiv=n;
            n->d_suiv=nullptr;
        }
    }
    return *this;
}

rdv *jour::chercherRdv(const std::string &nom)
{
    rdv* cl=d_tete;
    while(cl!=nullptr)
    {
        cl=cl->d_suiv;
    }
    return cl;
}


static void jour::supprimerRdv(rdv *r)
{
    if(d_tete!=nullptr)
    {
        if(r==d_tete)
        {
            rdv *cl=d_tete->d_suiv;
            delete d_tete;
            d_tete=cl;
        }
        else
        {
            rdv *cl=d_tete, *prec=nullptr;
            while(cl!=nullptr && cl!=r)
            {
                prec=cl;
                cl=cl->d_suiv;
            }
            if(cl!=nullptr && cl==r)
            {
                prec->d_suiv=cl->d_suiv;
                delete cl;
            }
        }
    }
}



static void jour::ajouterContact(rdv *r, contact *c)
{
    rdv *cl=chercherRdv(r);
    cl.ajouterContact(c);
}

static void jour::supprimerContact(rdv *r, contact *c)
{
    rdv *cl=chercherRdv(r);
    cl.supprimeContact(c);
}

bool jour::modifHeureDeb(const std::string &nom, const temps &t)
{
    chercherRdv(nom);
    rdv::modifHeureDeb(t);
}

bool jour::modifJourDeb(const std::string &nom, const jour *j)
{
    chercherRdv(nom);
    rdv::modifJourDeb(j);
}

bool jour::modifHeureFin(const std::string &nom, const temps &t)
{
    chercherRdv(nom);
    rdv::modifHeureFin(t);
}

bool jour::modifJourFin(const std::string &nom, const jour *j)
{
    chercherRdv(nom);
    rdv::modifJourFin(j);
}
