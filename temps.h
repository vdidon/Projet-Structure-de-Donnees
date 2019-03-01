//
// Created by vdido on 01/03/2019.
//

#ifndef PROJET_STRUCTURE_DE_DONNEES_TEMPS_H
#define PROJET_STRUCTURE_DE_DONNEES_TEMPS_H


class temps {
public:
	temps(short h, short m);

	~temps();

	short h, m;

	unsigned int duree(const temps &t) const;


};


#endif //PROJET_STRUCTURE_DE_DONNEES_TEMPS_H
