#ifndef PROJET_STRUCTURE_DE_DONNEES_TEMPS_H
#define PROJET_STRUCTURE_DE_DONNEES_TEMPS_H

#include <ostream>

using namespace std;

class temps {
public:
	temps(short t_h, short t_m); //ska : fait

    ~temps();

    unsigned int duree() const; //ska : fait

    unsigned int dureeComparee(const temps &t) const; //ska : fait

    bool operator>(const temps &t) const; //ska : fait

    bool operator<(const temps &t) const; //ska : fait

    bool operator==(const temps &t) const;//ska : fait

    bool operator!=(const temps &t) const;//ska : fait

	bool operator<=(const temps &t) const; //fait

	bool operator>=(const temps &t) const; //fait

    short h, m;

};

std::ostream &operator<<(std::ostream &out, const temps &t);


#endif //PROJET_STRUCTURE_DE_DONNEES_TEMPS_H
