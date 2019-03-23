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
    } while ("quand les poules auront des" != "dents");
	return true;
}

void entrerPersonne(string &nom, string &prenom) {
    cout << "Entré le nom : ";
    cin >> nom;
    cout << "Entré le prenom : ";
    cin >> prenom;
}

void entrerJour(int &j, int &m, int &a) {
    cout << "Entré le jour : ";
    cin >> j;
    cout << "Entré le mois : ";
    cin >> m;
    cout << "Entré l'année : ";
    cin >> a;
}

void entrerRdv(string &nom, int &j, int &m, int &a) {
    cout << "Entré le nom : ";
    cin >> nom;
	entrerJour(j, m, a);
}

void entrerTemps(int &h, int &m) {
    cout << "Entré l'heure : ";
    cin >> h;
    cout << "Entré la minute : ";
    cin >> m;
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
	    entrerRdv(nom, j, m, a);
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
	    string nom, prenom, num, email;
        entrerPersonne(nom, prenom);
        cout << "Quel modification voulez vous faire : " << endl;
        cout << "1 - Heure de début" << endl;
        cout << "2 - Heure de fin" << endl;
        cout << "0 - Menu principal" << endl;
        cout << "0-2 : ";
        cin >> i;
        switch (i) {
            case 1:
                cout << "Entrer le numéro : ";
                cin >> num;
                if (!ag.modifNum(nom, prenom, num)) {
                    cout << "La personne n'a pas était modifiée";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 2:
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
	    entrerRdv(nom, j, m, a);
        cout << "Quel modification voulez vous faire : " << endl;
        cout << "1 - Heure de début" << endl;
	    cout << "2 - Heure de fin" << endl;
	    cout << "3 - Jour de début" << endl;
	    cout << "4 - Jour de fin" << endl;
        cout << "0 - Menu principal" << endl;
	    cout << "0-4 : ";
        cin >> i;
        switch (i) {
            case 1:
                int h, min;
		        entrerTemps(h, min);
                if (!ag.modifHeureDeb(j, m, a, nom, h, min)) {
                    cout << "Le rdv n'a pas était modifié";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 2:
	            int fh, fmin;
		        entrerTemps(fh, fmin);
		        if (!ag.modifHeureFin(j, m, a, nom, fh, fmin)) {
                    cout << "Le rdv n'a pas était modifié";
                    ext = sortir();
                } else
                    ext = true;
                break;
	        case 3:
		        int new_j, new_m, new_a;
		        entrerJour(new_j, new_m, new_a);
		        if (!ag.modifJourDeb(j, m, a, nom, new_j, new_m, new_a)) {
			        cout << "Le rdv n'a pas était modifié";
			        ext = sortir();
		        } else
			        ext = true;
		        break;
	        case 4:
		        int fnew_j, fnew_m, fnew_a;
		        entrerJour(fnew_j, fnew_m, fnew_a);
		        if (!ag.modifJourFin(j, m, a, nom, fnew_j, fnew_m, fnew_a)) {
			        cout << "Le rdv n'a pas était modifié";
			        ext = sortir();
		        } else
			        ext = true;
		        break;
            case 0:
                ext = true;
            default:
	            cout << "Entré un nombre entre 0 et 4" << endl;
        }
    } while (!ext);


}

void affRdvDeJour() {
	int j, m, a;
	entrerJour(j, m, a);
	ag.afficherRdvDeJour(j, m, a, cout);
}

void affPersonne() {
    string nom, prenom;
    bool ext = false;
    do {
        entrerPersonne(nom, prenom);
        if (ag.afficherRdvDeContact(nom, prenom, cout))
            ext = true;
        else {
            cout << "La personne n'a pas était trouvé" << endl;
            if (sortir())
                ext = true;
        }
    } while (!ext);
}

void personneDispo() {
	string nom, prenom;
	int j, m, a, h, min, fj, fm, fa, fh, fmin;
	entrerPersonne(nom, prenom);
	cout << "Heure de début : " << endl;
	entrerJour(j, m, a);
	entrerTemps(h, min);
	cout << "Heure de fin : " << endl;
	entrerJour(fj, fm, fa);
	entrerTemps(fh, fmin);
	if (ag.contactEstDispo(nom, prenom, j, m, a, h, min, fj, fm, fa, fh, fmin)) {
		cout << "La personne est dispo" << endl;
	} else {
		cout << "La personne n'est pas dispo" << endl;
	}
}

void ajouPersonne() {
    string nom, prenom;
    bool ext = false;
    do {
        entrerPersonne(nom, prenom);
        string num, email;
        cout << "Entrer le numéro de téléphone : ";
        cin >> num;
        cout << "Entrer l'email : ";
        cin >> email;
        if (ag.ajouterContact(nom, prenom, num, email))
            ext = true;
        else {
            cout << "La personne n'a pas pu être ajouter" << endl;
            if (sortir())
                ext = true;
        }
    } while (!ext);
}

void ajouRdv() {
	string nom;
	int j, m, a, h, min, fj, fm, fa, fh, fmin;
	//cout<<"Heure de début : "<<endl;
	entrerRdv(nom, j, m, a);
	entrerTemps(h, min);
	cout << "Heure de fin : " << endl;
	entrerJour(fj, fm, fa);
	entrerTemps(fh, fmin);
	if (ag.ajouterRdv(j, m, a, nom, h, min, fj, fm, fa, fh, fmin)) {
		cout << "Rdv ajouté" << endl;
	} else {
		cout << "Rdv pas ajouté" << endl;
	}
}

void ajouPersonneARdv() {
    string nom, prenom, nomrdv;
    int j, m, a;
    bool ext = false;
    do {
        entrerPersonne(nom, prenom);
	    entrerRdv(nomrdv, j, m, a);
        if (ag.ajouterContactARdv(nom, prenom, nomrdv, j, m, a))
            ext = true;
        else {
            cout << "La personne n'a pas pu être ajouter au rdv" << endl;
            if (sortir())
                ext = true;
        }
    } while (!ext);
}

void quitter() {

}

bool menuPrincipal() {
    cout << endl << "Menu principal : " << endl << endl;
    cout << "1 - Suppression d’une personne" << endl;
    cout << "2 - Suppression d’un rendez-vous" << endl;
    cout << "3 - Modification d’une personne" << endl;
    cout << "4 - Modification d’un rendez-vous" << endl;
	cout << "5 - Afficher les rdv d'un jour" << endl;
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
	        affRdvDeJour();
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