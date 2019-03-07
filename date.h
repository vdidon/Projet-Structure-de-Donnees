#ifndef PROJET_STRUCTURE_DE_DONNEES_DATE_H
#define PROJET_STRUCTURE_DE_DONNEES_DATE_H

class date {
public:
    bool operator>(const date &d) const {
        return (a > d.a) || (a == d.a && (m > d.m || (m == d.m && j > d.j)));
    }

    bool operator<(const date &d) const {
        return (a < d.a) || (a == d.a && (m < d.m || (m == d.m && j < d.j)));
    }

    bool operator==(const date &d) const {
        return a == d.a && m == d.m && j == d.j;
    }
    int j, m, a;
};

#endif //PROJET_STRUCTURE_DE_DONNEES_DATE_H
