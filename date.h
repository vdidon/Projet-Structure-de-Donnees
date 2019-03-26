#ifndef PROJET_STRUCTURE_DE_DONNEES_DATE_H
#define PROJET_STRUCTURE_DE_DONNEES_DATE_H

#include <ostream>


using namespace std;

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

std::ostream &operator<<(std::ostream &out, const date &d);
#endif //PROJET_STRUCTURE_DE_DONNEES_DATE_H
