#include <iostream>
#include <ctime>
using namespace std;
//////////////////////////////////////////LISTA:
struct LISTA {
	int liczba;
	LISTA* nastepny;
};

LISTA* wezel(int w) {
	LISTA* nowywezel = new LISTA;
	nowywezel->liczba = w;
	nowywezel->nastepny = nullptr;
	return nowywezel;
}
void dodaj(LISTA*& glowa, int w) {
	LISTA* temp = wezel(w);
	temp->nastepny = glowa;
	glowa = temp;
}

void wyswietl(LISTA* glowa) {
	LISTA* temp = glowa;
	while (temp != nullptr) {
		cout << temp->liczba << "->";
		temp = temp->nastepny;
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////////////////////


/////////////////// SORTOWANIE PRZEZ WSTAWIANIE:

void wstawianie(LISTA*& glowa) {
	if (glowa == nullptr || glowa->nastepny == nullptr) {
		return;
	}

	LISTA* posortowana = nullptr;

	LISTA* biezacy = glowa;
	while (biezacy != nullptr) {
		LISTA* nastepny = biezacy->nastepny;


		if (posortowana == nullptr || biezacy->liczba <= posortowana->liczba) {
			biezacy->nastepny = posortowana;
			posortowana = biezacy;
		}
		else {
			LISTA* aktualnyPosortowany = posortowana;
			while (aktualnyPosortowany->nastepny != nullptr && aktualnyPosortowany->nastepny->liczba < biezacy->liczba) {
				aktualnyPosortowany = aktualnyPosortowany->nastepny;
			}
			biezacy->nastepny = aktualnyPosortowany->nastepny;
			aktualnyPosortowany->nastepny = biezacy;
		}
		biezacy = nastepny;
	}
	glowa = posortowana;
}

/// ///////////////////////////////////////////////////SORTOWANIE SHELLEM:

void Shella(int tab[], int n) {
	for (int odst = n / 2; odst > 0; odst/= 2) {
		for (int i = odst; i < n; i++) {
			int temp = tab[i];
			int j = i;
			while (j >= odst && tab[j - odst] > temp) {
				tab[j] = tab[j - odst];
				j -= odst;
			}
			tab[j] = temp;
		}
	}
}




////////////////////////////////////////////////////////////////////////////////////
void wf(int tab[],int n) {
	for (int i = 0; i < n; i++) {
		cout << tab[i] << "->";
	}
	cout << endl;
}

int main() {
	double czas1, czas2;

	srand(time(NULL));
	///////////////////////////////////////////////LISTA1:
	LISTA* lista1 = nullptr;
	dodaj(lista1, 5);
	dodaj(lista1, 7);
	dodaj(lista1, 15);
	dodaj(lista1, 55);
	dodaj(lista1, 67);
	dodaj(lista1, 18);
	dodaj(lista1, 1);
	dodaj(lista1, 20);
	wyswietl(lista1);
	clock_t start1 = clock();
	wstawianie(lista1);
	clock_t end1 = clock();
	czas1 = double(end1 - start1) / CLOCKS_PER_SEC;
	wyswietl(lista1);
	///////////////////////////////////////////////////////////LISTA2:
	cout << endl << endl;
	
	

	int TAB[150];
	for (int i = 0; i < 150; i++) {
		TAB[i] = rand() % 100;
	}
	wf(TAB, 150);
	clock_t start2 = clock();
	Shella(TAB, 150);
	clock_t end2 = clock();
	czas2 = double(end2 - start2) / CLOCKS_PER_SEC;
	wf(TAB, 150);
	cout << "\n\nCZAS PRZEZ WSTAWIANIE:  " << czas1;
	cout << "\nCZAS PRZEZ SHELLA:  " << czas2;
	return 0;
}