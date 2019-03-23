#ifndef PROJET_STRUCTURE_DE_DONNEES_DATE_H
#define PROJET_STRUCTURE_DE_DONNEES_DATE_H

class date {
public:
	date(int p_j, int p_m, int p_a);
    date(const date &d);
    bool operator>(const date &d) const;

    bool operator<(const date &d) const;

    bool operator==(const date &d) const;

    bool operator!=(const date &d) const;

	bool operator>=(const date &d) const;

	bool operator<=(const date &d) const;

    int j, m, a;
};

#endif //PROJET_STRUCTURE_DE_DONNEES_DATE_H
