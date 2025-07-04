#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
struct lista {

	int liczba;
	lista* nastepny;
};
lista* wezel(int w) {
	lista* nowywezel = new lista;
	nowywezel->liczba = w;
	nowywezel->nastepny = nullptr;
	return nowywezel;
}
void dodaj(lista*& glowa, int w) {
	lista* temp = wezel(w);
	temp->nastepny = glowa;
	glowa = temp;
}
void wyswietl(lista* glowa) {
	lista* temp = glowa;
	while (temp != nullptr) {
		cout << temp->liczba << "->";
		temp = temp->nastepny;
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////////////////////////


int dlugosc_listy(lista* glowa) {
	if (glowa == nullptr) {
		return 0;
	}
	else {
		int n = 1;
		lista* current = glowa; 
		while (current->nastepny != nullptr) {
			n++;
			current = current->nastepny;
		}
		return n;
	}
}
lista* scalanie(lista* lewa, lista* prawa) {
	
	if (lewa == nullptr) return prawa;
	if (prawa == nullptr) return lewa;

	lista* wynik = nullptr;

	
	if (lewa->liczba <= prawa->liczba) {
		wynik = lewa;
		wynik->nastepny = scalanie(lewa->nastepny, prawa);
	}
	else {
		wynik = prawa;
		wynik->nastepny = scalanie(lewa, prawa->nastepny);
	}

	return wynik;
}

void sortowanie_przez_scalanie_lista(lista*& glowa, int n) {
	
	if (n <= 1) return;

	
	int srodek = n / 2;

	
	lista* lewa = glowa;
	lista* prawa = nullptr;
	lista* temp = glowa;

	
	for (int i = 0; i < srodek - 1; i++) {
		temp = temp->nastepny;
	}

	
	prawa = temp->nastepny;

	
	temp->nastepny = nullptr;

	
	sortowanie_przez_scalanie_lista(lewa, srodek);
	sortowanie_przez_scalanie_lista(prawa, n - srodek);

	
	glowa = scalanie(lewa, prawa);
}

/// //////////////////////////////////////////////tablica:

void sortowanie_przez_scalanie_tablica(int tab[], int n) {
	if (n <= 1) return;
	int lewa = tab[0];
	int prawa = 0;
}

int main() {

	/////////////////////////////////////////////lista:
	lista* lista = nullptr;
	int dlugosc;
	dodaj(lista, 10);
	dodaj(lista, 4);
	dodaj(lista, 12);
	dodaj(lista, 7);
	dodaj(lista, 5);
	dodaj(lista, 16);
	dodaj(lista, 1);
	wyswietl(lista);

	dlugosc = dlugosc_listy(lista);
	cout << endl<<"dlugosc listy:  " << dlugosc;

	sortowanie_przez_scalanie_lista(lista, dlugosc);
	cout << endl;
	wyswietl(lista);

	////////////////////////////////////// tablica:
	srand(time(NULL));
	int tab[20];
	for (int i = 0; i < 20; i++) {
		tab[i] = rand() % 100 ;
	}
	cout << "\n\n TABLICA:\n";
	for (int i = 0; i < 20; i++) {
		cout << tab[i] << "->";
	}
	cout << endl;
	int n = 10;

	return 0;
}