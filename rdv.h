//
// Created by vdido on 16/02/2019.
//

#ifndef PROJET_STRUCTURE_DE_DONNEES_RDV_H
#define PROJET_STRUCTURE_DE_DONNEES_RDV_H

#include <cstddef> //size_t

class contact;

class rdv {
	friend class jour;

private:
	/*
	 * string d_heureDeb;
	 * ou
	 * int d_heureDeb;
	 */
	size_t duree;
	rdv *suiv;
	contact **tabPersonne;

};


#endif //PROJET_STRUCTURE_DE_DONNEES_RDV_H
