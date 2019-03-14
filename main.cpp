#include <iostream>
#include "agenda.h"

using namespace std;

agenda ag{};

void majuscule(char &c) {
    if (c >= 'a' && c <= 'z')
        c -= 'a' - 'A';
}

bool sortir() {
    do {
        cout << "Voulez vous revenir au menu ? (O/N) ";
        char c;
        cin >> c;
        majuscule(c);
        switch (c) {
            case 'O':
                return true;
            case 'N':
                return false;
            default:
                cout << "Entré O ou N" << endl;
        }
    } while ("poules" != "dents");
}

void entrerPersonne(string &nom, string &prenom) {
    cout << "Entré le nom : ";
    cin >> nom;
    cout << "Entré le prenom : ";
    cin >> prenom;
}

void entreJour(int &j, int &m, int &a) {
    cout << "Entré le jour : ";
    cin >> j;
    cout << "Entré le mois : ";
    cin >> m;
    cout << "Entré l'année : ";
    cin >> a;
}

void entreRdv(string &nom, int &j, int &m, int &a) {
    cout << "Entré le nom : ";
    cin >> nom;
    entreJour(j, m, a);
}

void suppPersonne() {
    string nom, prenom;
    bool ext = false;
    do {
        entrerPersonne(nom, prenom);
        if (ag.supprimerContact(nom, prenom))
            ext = true;
        else {
            cout << "La personne ne peut pas être supprimé" << endl;
            if (sortir())
                ext = true;
        }
    } while (!ext);
}

void suppRdv() {
    string nom;
    int j, m, a;
    bool ext = false;
    do {
        entreRdv(nom, j, m, a);
        if (ag.supprimerRdv(j, m, a, nom))
            ext = true;
        else {
            cout << "Le rdv ne peut pas être supprimé" << endl;
            if (sortir())
                ext = true;
        }
    } while (!ext);
}

void modifPersonne() {

}

void modifRdv() {

}

void affRdv() {

}

void affPersonne() {

}

void personneDispo() {

}

void ajouPersonne() {

}

void ajouRdv() {

}

void ajouPersonneARdv() {

}

void quitter() {

}

bool menuPrincipal() {
    cout << endl << "Menu principal : " << endl << endl;
    cout << "1 - Suppression d’une personne" << endl;
    cout << "2 - Suppression d’un rendez-vous" << endl;
    cout << "3 - Modification d’une personne" << endl;
    cout << "4 - Modification d’un rendez-vous" << endl;
    cout << "5 - Afficher des rdv" << endl;
    cout << "6 - Afficher une personne" << endl;
    cout << "7 - Une personne est-elle disponible ?" << endl;
    cout << "8 - Ajouter une personne" << endl;
    cout << "9 - Ajouter un rdv" << endl;
    cout << "10 - Ajouter une personne à un rdv" << endl;
    cout << "0 - Quitter" << endl;
    int i;
    cout << "0-10 : ";
    cin >> i;
    switch (i) {
        case 1:
            suppPersonne();
            break;
        case 2:
            suppRdv();
            break;
        case 3:
            modifPersonne();
            break;
        case 4:
            modifRdv();
            break;
        case 5:
            affRdv();
            break;
        case 6:
            affPersonne();
            break;
        case 7:
            personneDispo();
            break;
        case 8:
            ajouPersonne();
            break;
        case 9:
            ajouRdv();
            break;
        case 10:
            ajouPersonneARdv();
            break;
        case 0:
            quitter();
            return false;
        default:
            cout << "Entré un nombre entre 0 et 9" << endl;
            break;
    }
    return true;
}

int main() {
    while (menuPrincipal());
}