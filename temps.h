#ifndef PROJET_STRUCTURE_DE_DONNEES_TEMPS_H
#define PROJET_STRUCTURE_DE_DONNEES_TEMPS_H


class temps {
public:
    temps(short h, short m);

    ~temps();

    unsigned int duree(const temps &t) const;

    short h, m;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_TEMPS_H
