#include <iostream>
#include "agenda.h"

using namespace std;

agenda ag{};

void majuscule(char &c) {
    if (c >= 'a' && c <= 'z')
        c -= 'a' - 'A';
}

bool sanschiffre(const string &s) {
	for (auto c : s) {
		if (c >= '0' && c <= '9') {
			return false;
		}
	}
	return true;
}

void entrerPersonne(string &nom, string &prenom) {
	bool ext = false;
	do {
		cout << "Entrez le nom : ";
		cin >> nom;
		cout << "Entrez le prenom : ";
		cin >> prenom;
		if (sanschiffre(nom) && sanschiffre(prenom))
			ext = true;
		else
			cout << "Pas de chiffre SVP" << endl;
	} while (!ext);

}

void entrerJour(int &j, int &m, int &a) {
	char c;
	cout << "Entrez la date (jj/mm/aaaa) : ";
	cin >> j >> c >> m >> c >> a;
	/*cout<<endl<<"SAISIE DE LA DATE"<<endl;
	cout << "Entrer l'année : ";
	cin >> a;
	cout << "Entrer le mois 1-12 : ";
	cin >> m;
    cout << "Entrer le jour 1-31 : ";
    cin >> j;*/
}

void entrerRdv(string &nom, int &j, int &m, int &a) {
	cout << "Entrez le nom : ";
    cin >> nom;
	entrerJour(j, m, a);
}

void entrerTemps(int &h, int &m) {
	char c;
	//cout<<endl<<"SAISIE DE L'HEURE"<<endl;
	cout << "Entrez l heure (hh:mm) : ";
    cin >> h;
	cin >> c;
	cin >> m;
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
				cout << "Entrez O ou N" << endl;
		}
	} while ("quand les poules auront des" != "dents");
	return true;
}

void suppPersonne() {
    string nom, prenom;
    bool ext = false;
    do {
        entrerPersonne(nom, prenom);
        if (ag.supprimerContact(nom, prenom))
            ext = true;
        else {
            cout << "La personne ne peut pas etre supprimee" << endl;
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
            cout << "Le rdv ne peut pas etre supprime" << endl;
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
        cout << "Quelle modification voulez-vous faire ? " << endl;
	    cout << "1 - Le numero" << endl;
	    cout << "2 - l email" << endl;
        cout << "0 - Menu principal" << endl;
        cout << "0-2 : ";
        cin >> i;
        switch (i) {
            case 1:
                cout << "Entrez le numero : ";
                cin >> num;
                if (!ag.modifNum(nom, prenom, num)) {
                    cout << "La personne n a pas ete modifiee";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 2:
                cout << "Entrez l email : ";
                cin >> email;
                if (!ag.modifEmail(nom, prenom, email)) {
                    cout << "La personne n a pas ete modifiee";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 0:
                ext = true;
                break;
            default:
                cout << "Entrez un nombre entre 0 et 2" << endl;
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
        cout << "Quelle modification voulez-vous faire ? " << endl;
        cout << "1 - Heure de debut" << endl;
	    cout << "2 - Heure de fin" << endl;
	    cout << "3 - Jour de debut" << endl;
	    cout << "4 - Jour de fin" << endl;
        cout << "0 - Menu principal" << endl;
	    cout << "0-4 : ";
        cin >> i;
        switch (i) {
            case 1:
                int h, min;
		        entrerTemps(h, min);
                if (!ag.modifHeureDeb(j, m, a, nom, h, min)) {
                    cout << "Le rdv n a pas ete modifie";
                    ext = sortir();
                } else
                    ext = true;
                break;
            case 2:
	            int fh, fmin;
		        entrerTemps(fh, fmin);
		        if (!ag.modifHeureFin(j, m, a, nom, fh, fmin)) {
                    cout << "Le rdv n a pas ete modifie";
                    ext = sortir();
                } else
                    ext = true;
                break;
	        case 3:
		        int new_j, new_m, new_a;
		        entrerJour(new_j, new_m, new_a);
		        if (!ag.modifJourDeb(j, m, a, nom, new_j, new_m, new_a)) {
			        cout << "Le rdv n a pas ete modifie";
			        ext = sortir();
		        } else
			        ext = true;
		        break;
	        case 4:
		        int fnew_j, fnew_m, fnew_a;
		        entrerJour(fnew_j, fnew_m, fnew_a);
		        if (!ag.modifJourFin(j, m, a, nom, fnew_j, fnew_m, fnew_a)) {
			        cout << "Le rdv n a pas ete modifie";
			        ext = sortir();
		        } else
			        ext = true;
		        break;
            case 0:
                ext = true;
            default:
	            cout << "Entrez un nombre entre 0 et 4" << endl;
        }
    } while (!ext);


}

void affRdvDeJour() {
	int j, m, a;
	bool ext = false;
	do {
		entrerJour(j, m, a);
		cout << endl;
		if (ag.afficherRdvDeJour(j, m, a, cout))
			ext = true;
		else {
			cout << "Le jour n a pas ete trouve" << endl;
			if (sortir())
				ext = true;
		}
	} while (!ext);


}

void affPersonne() {
    string nom, prenom;
    bool ext = false;
    do {
        entrerPersonne(nom, prenom);
	    cout << endl;
        if (ag.afficherRdvDeContact(nom, prenom, cout))
            ext = true;
        else {
	        cout << "Le rdv n a pas ete trouve" << endl;
            if (sortir())
                ext = true;
        }
    } while (!ext);
}

void affPersonneDeRdv() {
	string nom;
	int j, m, a;
	bool ext = false;
	do {
		entrerRdv(nom, j, m, a);
		cout << endl;
		if (ag.afficherContactDeRdv(nom, j, m, a, cout))
			ext = true;
		else {
			cout << "La personne n a pas ete trouvee" << endl;
			if (sortir())
				ext = true;
		}
	} while (!ext);
}

void personneDispo() {
	string nom, prenom;
	int j, m, a, h, min, fj, fm, fa, fh, fmin;
	entrerPersonne(nom, prenom);
	cout << endl << "HEURE DE DEBUT : " << endl;
	entrerJour(j, m, a);
	entrerTemps(h, min);
	cout << endl << "HEURE DE FIN : " << endl;
	entrerJour(fj, fm, fa);
	entrerTemps(fh, fmin);
	if (ag.contactEstDispo(nom, prenom, j, m, a, h, min, fj, fm, fa, fh, fmin)) {
		cout << "La personne est disponible" << endl;
	} else {
		cout << "La personne n est pas disponible" << endl;
	}
}

void ajouPersonne() {
    string nom, prenom;
    bool ext = false;
    do {
        entrerPersonne(nom, prenom);
        string num, email;
        cout << "Entrez le numero de telephone : ";
        cin >> num;
        cout << "Entrez l email : ";
        cin >> email;
        if (ag.ajouterContact(nom, prenom, num, email))
            ext = true;
        else {
            cout << "La personne n a pas pu etre ajoutee" << endl;
            if (sortir())
                ext = true;
        }
    } while (!ext);
}

void ajouRdv() {
	string nom;
	int j, m, a, h, min, fj, fm, fa, fh, fmin;
	entrerRdv(nom, j, m, a);
	cout << endl << "HEURE DE DEBUT : " << endl;
	entrerTemps(h, min);
	cout << endl << "DATE DE FIN : " << endl;
	entrerJour(fj, fm, fa);
	cout << endl << "HEURE DE FIN : " << endl;
	entrerTemps(fh, fmin);
	if (ag.ajouterRdv(j, m, a, nom, h, min, fj, fm, fa, fh, fmin)) {
		cout << "Rdv ajoute" << endl;
	} else {
		cout << "Rdv pas ajoute" << endl;
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
            cout << "La personne n a pas pu etre ajoutee au rdv" << endl;
            if (sortir())
                ext = true;
        }
    } while (!ext);
}

void quitter() {

}

bool menuPrincipal() {
    cout << endl << "Menu principal : " << endl << endl;
	cout << "1\t - Suppression d une personne" << endl;
	cout << "2\t - Suppression d un rendez-vous" << endl;
	cout << "3\t - Modification d une personne" << endl;
	cout << "4\t - Modification d un rendez-vous" << endl;
	cout << "5\t - Afficher les rdv d un jour" << endl;
	cout << "6\t - Afficher une personne" << endl;
	cout << "7\t - Une personne est-elle disponible ?" << endl;
	cout << "8\t - Ajouter une personne" << endl;
	cout << "9\t - Ajouter un rdv" << endl;
	cout << "10\t - Ajouter une personne a un rdv" << endl;
	cout << "11\t - Afficher les personnes d un rendez-vous" << endl;
	cout << "0\t - Quitter" << endl;
    int i;
	cout << "0-11 : ";
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
	    case 11:
		    affPersonneDeRdv();
		    break;
        case 0:
            quitter();
            return false;
        default:
	        cout << "Entrez un nombre entre 0 et 11" << endl;
    }
    return true;
}

int main() {
	while (menuPrincipal());
	return 0;
}
