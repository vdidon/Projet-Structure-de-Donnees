//
// Created by vdidon on 11/03/19.
//

#include "vectorLite.h"

template<typename T>
vectorLite<T>::vectorLite(int p_size, T *p_tab): d_size{p_size}, d_cap{p_size * 2} {
    d_tab = new T[d_cap];
    if (p_tab) {
        memcpy(d_tab, p_tab, d_size * sizeof(T));
    }
}

template<typename T>
vectorLite<T>::vectorLite(const vectorLite &v) : d_size{v.d_size}, d_cap{v.d_cap} {
    d_tab = new T[d_cap];
    memcpy(d_tab, v.d_tab, d_size * sizeof(T));
}

template<typename T>
vectorLite<T>::~vectorLite() {
    delete[] d_tab;
}

template<typename T>
void vectorLite<T>::push_back(T val) {
    if (++d_size == d_cap) {
        recap(d_size * 2);
    }
    d_tab[d_size - 1] = val;
}

template<typename T>
int vectorLite<T>::size() const {
    return d_size;
}

template<typename T>
T vectorLite<T>::operator[](int i) const {
    return d_tab[i];
}

template<typename T>
void vectorLite<T>::recap(int p_cap) {
    T *tmpTab = new T[p_cap];
    memcpy(tmpTab, d_tab, p_cap * sizeof(T));
    delete[] d_tab;
    d_cap = p_cap;
}

template<typename T>
bool vectorLite<T>::supprimer(int i) {
    --d_size;
    memcpy(&d_tab[i], &d_tab[i + 1], (d_size - i - 1) * sizeof(T));
}

template<typename T>
T &vectorLite<T>::operator[](int i) {
    return d_tab[i];
}



