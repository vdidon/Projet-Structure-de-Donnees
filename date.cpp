
#include "date.h"
#include <iomanip>

date::date(int p_j, int p_m, int p_a) : j{p_j}, m{p_m}, a{p_a} {

}

date::date(const date &d) : j{d.j}, m{d.m}, a{d.a} {

}


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

bool date::operator>=(const date &d) const {
	return !(*this < d);
}

bool date::operator<=(const date &d) const {
	return !(*this > d);
}

ostream &operator<<(ostream &out, const date &d) {
	out << setfill('0') << setw(2) << d.j << '/' << setfill('0') << setw(2)
	    << d.m << '/' << setfill('0') << setw(4) << d.a;
	return out;
}

