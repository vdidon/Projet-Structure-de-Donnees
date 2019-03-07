
#include "date.h"

bool date::operator>(const date &d) const {
    return (a > d.a) || (a == d.a && (m > d.m || (m == d.m && j > d.j)));
}

bool date::operator<(const date &d) const {
    return (a < d.a) || (a == d.a && (m < d.m || (m == d.m && j < d.j)));
}

bool date::operator==(const date &d) const {
    return a == d.a && m == d.m && j == d.j;
}

bool date::operator!=(const date &d) const {
    return !(d == *this);
}
