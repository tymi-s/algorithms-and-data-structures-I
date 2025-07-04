 #include <iostream>
using namespace std;

struct osoba {
    string imie;
    string nazwisko;
    int wiek;
    osoba* nastepna;

};


struct lista {
    osoba* pierwsza;

    void INSERT(string imie, string nazwisko, int wiek) {
        osoba* nowa = new osoba;
        nowa->imie = imie;
        nowa->nazwisko = nazwisko;
        nowa->wiek = wiek;
        if (pierwsza == 0) {
            pierwsza = nowa;
        }
        else {
            osoba* temp = pierwsza;
            while (temp->nastepna) {
                temp = temp->nastepna;  //przeskakiwanie miedzy elementmi listy a¿ siê nie skoñcz¹
            }
            temp->nastepna = nowa;     // WSKAZNIK JEST USTAWIONY NA OSTATNI ELEMENT LISTY WIEC TAM WSTAWIANY JEST NOWY ELEMENT
            nowa->nastepna = 0;
        }
    }


    void DELETE(int numer) {
        if (numer == 1) {
            osoba* temp = pierwsza;
            pierwsza = temp->nastepna;
            delete temp;
        }
        else if (numer >= 2) {
            int j = 1;
            osoba* temp = pierwsza;
            while (temp) {
                if ((j + 1) == numer) break;
                temp = temp->nastepna;
                j++;
            }
            if (temp->nastepna->nastepna == 0) {
                delete temp->nastepna;
                temp->nastepna = 0;
            }
            else {
                osoba* usuwana = temp->nastepna;
                temp->nastepna = temp->nastepna->nastepna;
                delete usuwana;
            }
        }
    }
    void PRINTLIST() {
        osoba* temp = pierwsza;  // Pocz¹tkowy wskaŸnik na pierwszy element listy

        while (temp ) {
            // Drukowanie informacji o osobie
            cout << "Imie: " << temp->imie << ", Nazwisko: " << temp->nazwisko << ", Wiek: " << temp->wiek << endl;

            temp = temp->nastepna;  // Przechodzenie do nastêpnego elementu listy
        }
    }
};
int main() {
    lista  mojalista;
    mojalista.pierwsza = NULL;
    mojalista.INSERT("Jan", "Kowalski", 25);
    mojalista.INSERT("Szymon", "Szyler", 30);
    mojalista.PRINTLIST();
    return 0;
}