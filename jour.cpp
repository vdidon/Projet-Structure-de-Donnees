#include "jour.h"
#include "rdv.h"
#include "date.h"

jour::jour(const date &d, rdv *tete) : d_date{d}, d_tete{tete}, d_rdvMultiJours{}
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

rdv *jour::ajouterRdv(const std::string &nom, const temps &tDeb, const temps &tFin, jour *j, jour *jFin, const vectorLite<contact *> &tabContacts)
{
	rdv *n = new rdv(nom, tDeb, tFin, j, jFin, tabContacts);
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
	    do
        {
            prec=cl;
            cl=cl->d_suiv;
        } while (cl != nullptr && cl->d_tDeb < tDeb);
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
    return n;
}

rdv *jour::chercherRdv(const std::string &nom) const
{
    rdv* cl=d_tete;
	while (cl != nullptr && cl->d_nom != nom)
    {
        cl=cl->d_suiv;
    }
    return cl;
}


bool jour::supprimerRdv(rdv *r) //static
{
	jour *j = r->d_j;
	if (j->d_tete != nullptr)
    {
	    if (r == j->d_tete) {
		    rdv *cl = j->d_tete->d_suiv;
		    delete j->d_tete;
		    j->d_tete = cl;
	    } else {
		    rdv *cl = j->d_tete, *prec = nullptr;
		    do {
			    prec = cl;
			    cl = cl->d_suiv;
		    } while (cl != nullptr && cl != r);
		    if (cl != nullptr && cl == r) {
			    prec->d_suiv = cl->d_suiv;
			    delete cl;
		    }
	    }
	    return true;
    }
	return false;
}


bool jour::ajouterContact(rdv *r, contact *c) //static
{
	return r->ajouterContact(c);
}

void jour::supprimerContact(rdv *r, contact *c) //static
{
	r->supprimeContact(c);
}

bool jour::modifHeureDeb(const std::string &nom, const temps &t)
{
	rdv *r = chercherRdv(nom);
	if (r) {
		return r->modifHeureDeb(t);
	}
	return false;

}

bool jour::modifJourDeb(const std::string &nom, jour *j)
{
	rdv *r = chercherRdv(nom);
	if (r) {
		return r->modifJourDeb(j);
	}
	return false;
}

bool jour::modifHeureFin(const std::string &nom, const temps &t)
{
	rdv *r = chercherRdv(nom);
	if (r) {
		return r->modifHeureFin(t);
	}
	return false;
}

bool jour::modifJourFin(const std::string &nom, jour *j)
{
	rdv *r = chercherRdv(nom);
	if (r) {
		return r->modifJourFin(j);
	}
	return false;
}


bool jour::afficherRdvDeJour(std::ostream &out) const
{
    if (d_tete==nullptr)
    {
        return false;
    }
    rdv*cl=d_tete;
	while (cl->d_suiv != nullptr)
    {
//	    out << cl << std::endl;
		cl->afficherRdv(out);
        cl=cl->d_suiv;
    }
	cl->afficherRdv(out);

    return true;
}

bool jour::afficherContactDeRdv(const std::string &nom, std::ostream &out) const
{
    if (d_tete==nullptr)
    {
        return false;
    }
	rdv *cl = chercherRdv(nom);
	cl->afficherContactDeRdv(out);
    return true;
}

bool jour::ajouterRdvMultiJour(rdv *r) {
	d_rdvMultiJours.push_back(r);
	return true;
}