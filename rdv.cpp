#include "rdv.h"
#include "contact.h"
#include "temps.h"
#include "jour.h"
#include <iomanip>

rdv::rdv(const std::string &nom, const temps &deb, const temps &fin, jour *j, jour *jfin,
         const vectorLite<contact *> &tabContacts) :
		d_nom{nom}, d_tDeb{deb}, d_tFin{fin}, d_j{jfin}, d_jfin{jfin}, d_tabContacts{tabContacts}, d_suiv{nullptr}
    {}

rdv::~rdv() = default;

//getters

std::string rdv::getNom() const{
    return d_nom;
}

temps rdv::getDeb() const {
	return d_tDeb;
}

temps rdv::getFin() const {
	return d_tFin;
}

vectorLite<contact *> rdv::getContacts() const {
	return d_tabContacts;
}

jour *rdv::getJourDeb() const{
        return d_j;
}

jour *rdv::getJourFin() const{
	return d_jfin;
}

//Autres

bool rdv::afficherContactDeRdv(std::ostream &out) const{
    if (d_tabContacts.size()==0)
        return false;

    out<<endl;
    for(int i=0; i<d_tabContacts.size(); i++)
    {
	    out << "Nom : " << d_tabContacts[i]->getNom() << endl;
	    out << "P�enom : " << d_tabContacts[i]->getPrenom() << endl;
	    out << "Num : " << d_tabContacts[i]->getNum() << endl;
	    out << "Email : " << d_tabContacts[i]->getAdresse() << endl << endl;
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
        if (t<d_tDeb)                                       //si le rdv est avanc�, on check les conflits
        {
            for(int i=0; i<d_tabContacts.size(); i++)       //On parcour les contacts du rdv
            {
	            T = d_tabContacts[i]->getTabrdv();
                for(int j=0; j<T.size();j++)                // On parcour les rdv de chaque contact
                {
	                if (!(this->pasEnMemeTemps(T[j])))
                    {
                       return false;                        //On return faux si un des contact ne peux pas
                    }
                }
            }
        }
        else
        {
            d_tDeb=t;

        }
	return true;
}

bool rdv::modifJourDeb(jour *j) {
	if (j->getDate() > d_jfin->getDate()) // apr�s la date de fin
		return false;
	else if (j->getDate() >= d_j->getDate()) // dans les date du rdv
	{
		d_j = j;
        return true;
	} else // avant la date de d�but
	{
		jour *oldJ = d_j;
		d_j = j;
		for (int i = 0; i < d_tabContacts.size(); ++i) // pour tous les contacts du rdv
		{
			for (int k = 0; k < d_tabContacts[i]->getTabrdv().size(); ++k) // pour tous les rdv de ce contact
			{
				if (d_tabContacts[i]->getTabrdv()[k] != this) // pour pas tester sur le rdv lui m�me
				{
					if (!pasEnMemeTemps(d_tabContacts[i]->getTabrdv()[k])) {
						d_j = oldJ;
						return false;
					}
				}
			}
		}
		return true;
	}
}


bool rdv::modifHeureFin(const temps &t)                     //voir modifierHeureDebut
{
    vectorLite<rdv *> T;
    bool modifPossible=true;
    if (t>d_tFin)
        {
            for(int i=0; i<d_tabContacts.size(); i++)
            {
	            T = d_tabContacts[i]->getTabrdv();
                for(int j=0; j<T.size();j++)
                {
	                if (!(this->pasEnMemeTemps(T[j])))
                    {
                       return false;
                    }
                }
            }
        } else {
	    d_tFin = t;
    }
	return true;
}

bool rdv::modifJourFin(jour *j) {
	if (j->getDate() < d_j->getDate()) // avant la date de d�but
		return false;
	else if (j->getDate() <= d_jfin->getDate()) // dans les date du rdv
	{
		d_j = j;
		return true;
	} else // apr�s la date de fin
	{
		jour *oldJ = d_jfin;
		d_jfin = j;
		for (int i = 0; i < d_tabContacts.size(); ++i) // pour tous les contacts du rdv
		{
			for (int k = 0; k < d_tabContacts[i]->getTabrdv().size(); ++k) // pour tous les rdv de ce contact
			{
				if (d_tabContacts[i]->getTabrdv()[k] != this) // pour pas tester sur le rdv lui m�me
				{
					if (!pasEnMemeTemps(d_tabContacts[i]->getTabrdv()[k])) {
						d_jfin = oldJ;
						return false;
					}
				}
			}
		}
        return true;
	}
}

bool rdv::ajouterContact(contact *c){
	vectorLite<rdv *> *T = &c->getTabrdv();
	for (int i = 0; i < T->size(); i++)
    {
	    if (pasEnMemeTemps((*T)[i]))
        {
	        i++;
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
	while (i < d_tabContacts.size() && c != d_tabContacts[i])
    {
        i++;
    }
    if(i<d_tabContacts.size())
    {
        d_tabContacts.supprimer(i);
        return true;
    }
    return false;
}

bool rdv::afficherRdv(std::ostream &out) const {
	out << "nom : " << d_nom << endl;
	out << "date de debut : " << setfill('0') << setw(2) << d_j->getJour() << '/' << setfill('0') << setw(2)
	    << d_j->getMois() << '/' << setfill('0') << setw(4) << d_j->getAnnee() << endl;
	out << "l'heure de debut : " << setfill('0') << setw(2) << d_tDeb.h << ':' << setfill('0') << setw(2) << d_tDeb.m
	    << endl;
	out << "date de fin : " << setfill('0') << setw(2) << d_jfin->getJour() << '/' << setfill('0') << setw(2)
	    << d_jfin->getMois() << '/' << setfill('0') << setw(4) << d_jfin->getAnnee() << endl;
	out << "l'heure de fin : " << setfill('0') << setw(2) << d_tFin.h << ':' << setfill('0') << setw(2) << d_tFin.m
	    << endl << endl;
	return true;
}
