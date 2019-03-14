#include <iostream>
#include "agenda.h"

using namespace std;

agenda a{};

void suppPersonne() {

}

void suppRdv() {

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

void quitter() {

}

bool menuPrincipal() {
    cout << "Menu principal : " << endl << endl;
    cout << "1 - Suppression d’une personne" << endl;
    cout << "2 - Suppression d’un rendez-vous" << endl;
    cout << "3 - Modification d’une personne" << endl;
    cout << "4 - Modification d’un rendez-vous" << endl;
    cout << "5 - Afficher des rdv" << endl;
    cout << "6 - Afficher une personne" << endl;
    cout << "7 - Une personne est-elle disponible ?" << endl;
    cout << "8 - Ajouter une personne" << endl;
    cout << "9 - Ajouter un rdv" << endl;
    cout << "0 - Quitter" << endl;
    int i;
    cout << "0-9 : ";
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