#include "temps.h"


temps::temps(short t_h, short t_m) :
    h{t_h}, m{t_m}
{}

unsigned int temps::duree() const{
    unsigned int temp;
    temp = h * 60 + m;
    return temp;
}


unsigned int temps::dureeComparee(const temps &t) const{
    unsigned int temp;
    temp = (t.h * 60 + t.m) - (h * 60 + m);     //Unsigned => retourne la valeur absolue si l'heure de this
    return temp;                                 // est plus grande que l'heure de t ?
}

bool temps::operator>(const temps &t) const {
    if (duree() > t.duree())
        return true;

    return false;
}

bool temps::operator<(const temps &t) const {
    if (duree() < t.duree())
        return true;

    return false;
}

bool temps::operator==(const temps &t) const {
    if (duree() == t.duree())
        return true;

    return false;
}

bool temps::operator!=(const temps &t) const {
    if (duree() != t.duree())
        return true;

    return false;
}


std::ostream &operator<<(std::ostream &out, const temps &t) {
    out << '(' << t.h << ',' << t.m << ')';
    return out;
}
