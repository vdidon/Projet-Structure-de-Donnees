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
        cout << "Voulez vous revenir au menu principal ? (O/N) ";
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
    } while ("poules n'ont pas de" != "dents");
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

void entreTemps(int &h, int &m) {
    cout << "Entré l'heure : ";
    cin >> h;
    cout << "Entré la minute : ";
    cin >> m;
}

unsigned int calculDuree(int dj, int dm, int da, int dh, int dmin, int fj, int fm, int fa, int fh, int fmin) {
    return static_cast<unsigned int>(fmin) - static_cast<unsigned int>(dmin) +
           60 * (static_cast<unsigned int>(fh) - static_cast<unsigned int>(dh)) +
           60 * 24 * (static_cast<unsigned int>(fj) - static_cast<unsigned int>(dj)) +
           60 * 24;
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
    int i;
    bool ext = false;
    do {
        string nom, prenom;
        entrerPersonne(nom, prenom);
        cout << "Quel modification voulez vous faire : " << endl;
        cout << "1 - Heure de début" << endl;
        cout << "2 - Heure de fin" << endl;
        cout << "0 - Menu principal" << endl;
        cout << "0-2 : ";
        cin >> i;
        switch (i) {
            case 1:
                string num;
                cout << "Entrer le numéro : ";
                cin >> num;
                if (!ag.modifNum(nom, prenom, num)) {
                    cout << "La personne n'a pas était modifiée";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 2:
                string email;
                cout << "Entrer l'email : ";
                cin >> email;
                if (!ag.modifEmail(nom, prenom, email)) {
                    cout << "La personne n'a pas était modifiée";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 0:
                ext = true;
                break;
            default:
                cout << "Entré un nombre entre 0 et 2" << endl;
        }
    } while (!ext);
}

void modifRdv() {
    string nom;
    int j, m, a;
    int i;
    bool ext = false;
    do {
        entreRdv(nom, j, m, a);
        cout << "Quel modification voulez vous faire : " << endl;
        cout << "1 - Heure de début" << endl;
        cout << "2 - Email" << endl;
        cout << "0 - Menu principal" << endl;
        cout << "0-2 : ";
        cin >> i;
        switch (i) {
            case 1:
                int h, min;
                entreTemps(h, min);
                if (!ag.modifHeureDeb(j, m, a, nom, h, min)) {
                    cout << "Le rdv n'a pas était modifié";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 2:
                int fj, fm, fa, fh, fmin;
                entreJour(fj, fm, fa);
                entreTemps(fh, fmin);
                int duree;
                if (!ag.modifDuree(j, m, a, nom, duree)) {
                    cout << "Le rdv n'a pas était modifié";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 0:
                ext = true;
            default:
                cout << "Entré un nombre entre 0 et 2" << endl;
        }
    } while (!ext);


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
            cout << "Entré un nombre entre 0 et 10" << endl;
    }
    return true;
}

int main() {
    while (menuPrincipal());
}