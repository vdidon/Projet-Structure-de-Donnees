#include "temps.h"

#include <iomanip>

temps::temps(short t_h, short t_m) :
    h{t_h}, m{t_m}
{}

unsigned int temps::duree() const{
    unsigned int temp;
	temp = static_cast<unsigned int>(h * 60 + m);
    return temp;
}


unsigned int temps::dureeComparee(const temps &t) const{
    unsigned int temp;
	temp = static_cast<unsigned int>((t.h * 60 + t.m) -
	                                 (h * 60 + m));     //Unsigned => retourne la valeur absolue si l'heure de this
    return temp;                                 // est plus grande que l'heure de t ?
}

bool temps::operator>(const temps &t) const {
	return duree() > t.duree();

}

bool temps::operator<(const temps &t) const {
	return duree() < t.duree();

}

bool temps::operator==(const temps &t) const {
	return duree() == t.duree();

}

bool temps::operator!=(const temps &t) const {
	return duree() != t.duree();

}

bool temps::operator<=(const temps &t) const {
	return !(*this > t);
}

bool temps::operator>=(const temps &t) const {
	return !(*this < t);
}

temps::~temps() = default;


std::ostream &operator<<(std::ostream &out, const temps &t) {
	out << setfill('0') << setw(2) << t.h << ':' << setfill('0') << setw(2) << t.m;
    return out;
}
