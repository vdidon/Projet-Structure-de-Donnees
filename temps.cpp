#include "temps.h"


temps::temps(short t_h, short t_m) :
    h{t_h}, m{t_m}
{}

unsigned int temps::duree() const{
    unsigned int temp;
    temp = this.h*60 + this.m;
    return temp;
}


unsigned int temps::dureeComparee(const temps &t) const{
    unsigned int temp;
    temp = (t.h * 60 + t.m) - (this->h * 60 + this->m); //Unsigned => retourne la valeur absolue si l'heure de this
    return temp;                                 // est plus grande que l'heure de t
}

bool temps::operator>(const temps &t) const {
    if (this->duree > t->duree)
        return true;

    return false;
}

bool temps::operator<(const temps &t) const {
    if (this.duree < t.duree)
        return true;

    return false;
}

bool temps::operator==(const temps &t) const {
    if (this.duree == t.duree)
        return true;

    return false;
}

bool temps::operator!=(const temps &t) const {
    if (this.duree != t.duree)
        return true;

    return false;
}
