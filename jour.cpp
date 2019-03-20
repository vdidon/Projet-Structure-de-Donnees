#include "jour.h"
#include "rdv.h"
#include "date.h"

jour::jour(const date &d) : d_date{d}

    {
        
    }

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
