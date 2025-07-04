#include <iostream>
using namespace std;





// /////////////////////////////////////////// NA TABLICY //////////////////////////////////////////////////////////////////////////////////////////////////
void babelkowe_tablica(int t[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (t[j] > t[j + 1]){
				int temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
				}
		}
	}
}

void wypisz(int t[], int n) {
	for (int i = 0; i < n; i++) {
		cout << t[i] << "->";
	}
}



// //////////////////////////////////////////// NA LIŒCIE ////////////////////////////////////////////////////////////////////////////////////////////////

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
	glowa =temp;
}

void wyswietl(LISTA* glowa) {
	LISTA* temp = glowa;
	while (temp != nullptr) {
		cout << temp->liczba << "->";
		temp = temp->nastepny;
	}
	cout <<endl;
}

void babelkowe_lista(LISTA** glowa, int n) {
	LISTA* temp, * prev_temp, * next_temp;
	for (int i = 0; i < n - 1; i++) {
		temp = *glowa;
		prev_temp = NULL;
		for (int j = 0; j < n - 1 - i; j++) {
			next_temp = temp->nastepny;
			if (temp->liczba > next_temp->liczba) {
				if (prev_temp != NULL) {
					prev_temp->nastepny = next_temp;
				}
				else {
					*glowa = next_temp;
				}
				temp->nastepny = next_temp->nastepny;
				next_temp->nastepny = temp;
				prev_temp = next_temp;
			}
			else {
				prev_temp = temp;
				temp = temp->nastepny;
			}
		}
	}
}

int main() {

	// TABLICA//
	int tab[7] = { 6,2,4,7,1,9,0 };
	cout << "PRZED SORTOWANIEM:\n";
	wypisz(tab, 7);
	babelkowe_tablica(tab, 7);
	cout << "\nPO SORTOWANIU:\n";
	wypisz(tab, 7);


	// LISTA// 

		LISTA* lista1=nullptr;
		dodaj(lista1, 1);
		dodaj(lista1, 5);
		dodaj(lista1, 15);
		dodaj(lista1, 7);
		dodaj(lista1, 11);
		dodaj(lista1, 3);
		int n = 6;

	cout << "\n\nLISTA: \n";
	wyswietl(lista1);

	
	babelkowe_lista(&lista1, n);

	cout << "\nLISTA PO SORTOWANIU:\n";
	wyswietl(lista1);
	return 0;
}