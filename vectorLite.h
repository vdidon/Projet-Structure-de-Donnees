#ifndef PROJET_STRUCTURE_DE_DONNEES_VECTORLITE_H
#define PROJET_STRUCTURE_DE_DONNEES_VECTORLITE_H

template<typename T> // T étant un pointeur
class vectorLite {
public:
    explicit vectorLite(int p_size, T *p_tab = nullptr);

    vectorLite(const vectorLite &v);

    ~vectorLite();

    void push_back(T val);

    int size() const;

    T operator[](int i) const;

    T &operator[](int i);

    bool supprimer(int i);

private:
    void recap(int p_cap);

    T *d_tab;
    int d_size;
    int d_cap;
};


#endif //PROJET_STRUCTURE_DE_DONNEES_VECTORLITE_H
