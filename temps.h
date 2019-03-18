#ifndef PROJET_STRUCTURE_DE_DONNEES_TEMPS_H
#define PROJET_STRUCTURE_DE_DONNEES_TEMPS_H


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

    short h, m;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_TEMPS_H
