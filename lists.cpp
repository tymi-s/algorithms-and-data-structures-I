#include <iostream>
#include <string>
using namespace std;

struct osoba {
	osoba* nastepna;
	string imie;
	string nazwisko;
	int wiek;

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
				temp = temp->nastepna; //przeskakiwanie miedzy elementmi listy a¿ siê nie skoñcz¹
			}
			temp->nastepna = nowa;
			nowa->nastepna = 0;
		}
	}
	void DELETE(int numer) {
		if (numer == 1) {
			osoba* temp = pierwsza;
			pierwsza = temp->nastepna;
			delete temp;
		}
		else if (numer>=2) {	
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
	void PRINTLIST(struct lista) {
		/// dodawanie obiektu na dowolny leement listy , usuwanie z dowolnego elementu listy , 

	}


	
};
	
	/*
	void dodawanie_do_listy(osoba* nowa) {
	if (pierwsza == nullptr) {
			pierwsza == nowa;
		}
		else {
			nowa->nastepna = pierwsza;
			pierwsza = nowa;
		}
		
	}
	*/

int main() 
{
	
	
	lista  mojalista;
	mojalista.pierwsza
	mojalista.INSERT("Jan", "Kowalski", 25);
	mo
	
	/*
	mojal.dodawanie_do_listy(&czlowiek);
	mojal.dodawanie_do_listy(&czlowiek2);
	cout << "imie pierweszej osoby: " << mojal.pierwsza->nastepna->nazwisko <<  endl;
	*/
	//lista mojal;
	//mojal.pierwsza = &czlowiek;
	
	return 0;
}