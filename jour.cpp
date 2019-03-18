#include "jour.h"
#include "rdv.h"
#include "date.h"

jour::jour(const date &d):

    {
        d_date.a=d.a;
        d_date.m=d.m;
        d_date.j=d.j;
    }

jour::~jour():
    {
      rdv *r = d_tete;
      while(r!=nullptr)
      {
          rdv *rTemp=r;
          r=r->suiv;
          delete rTemp;
      }
    }

int jour::taille() const{
    rdv *r=d_tete;
    int i=0;
    while(r!=d_tete)
    {
        r=r->suiv;
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

date getDate() const{
    return d_date;
}
