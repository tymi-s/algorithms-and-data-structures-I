#include <iostream>
#include <stdlib.h>
using namespace std;


struct lista {
    int liczby;
    lista* wskaznik;
};
// WYPISYWANIE ELEMENTÓW////
void wypisz(lista* glowa) {
    lista* temp = glowa;
    while (temp != nullptr) {
        cout << temp->liczby << " -> ";
        temp = temp->wskaznik;
    }
    cout << "nullptr" << endl;
}

///////NA KONIEC///
void wstaw_na_koniec(lista*& gl, int wartosc) {
    lista* n = new lista;
    n->liczby = wartosc;
    n->wskaznik = nullptr;

    if (gl == nullptr) {

        gl = n;
    }
    else {

        lista* current = gl;
        while (current->wskaznik != nullptr) {
            current = current->wskaznik;
        }

        current->wskaznik = n;
    }
}
/// NA POZYCJÊ P////
void wstaw_na_p(lista*& glowa, int wartosc, int p) {
    lista* nowa = new lista;
    nowa->liczby = wartosc;

    if (p == 0) {

        nowa->wskaznik = glowa;
        glowa = nowa;
    }
    else {

        lista* c = glowa;
        for (int i = 0; i < p - 1 && c != nullptr; ++i) {
            c = c->wskaznik;
        }

        if (c != nullptr) {

            nowa->wskaznik = c->wskaznik;
            c->wskaznik = nowa;
        }
        else {

            wstaw_na_koniec(glowa, wartosc);
        }
    }
}

/// USUWANIE////
void usun(lista*& glowa) {
    while (glowa != nullptr) {
        lista* temp = glowa;
        glowa = glowa->wskaznik;
        delete temp;
    }
}

/// ZWRACANIE////
int zwracanie(const lista* glowa, int position) {
    const lista* curr = glowa;
    for (int i = 0; i < position && curr != nullptr; ++i) {
        curr = curr->wskaznik;
    }

    if (curr != nullptr) {
        return curr->liczby;
    }
    else {

        return -1;
    }
}
////////////////////////////////// ZADANIE 2/////////////////////////////////////

void usun_po_k(lista*& glowa, int k) {
    if (glowa == nullptr || glowa->wskaznik == nullptr) {
        
        return;
    }

    lista* temp = glowa;

    while (temp->wskaznik != nullptr && temp->wskaznik->liczby <= k) {
       
        temp = temp->wskaznik;
    }

    if (temp->wskaznik != nullptr) {
        
        lista* do_usuniecia = temp->wskaznik->wskaznik;
        temp->wskaznik = do_usuniecia->wskaznik;
        delete do_usuniecia;
    }
}


int main() {
    lista* mlista = nullptr;
    lista* mlista2 = nullptr;
    wstaw_na_koniec(mlista, 10);
    wstaw_na_koniec(mlista, 1);
    wstaw_na_koniec(mlista, 20);

    wstaw_na_koniec(mlista2, 50);
    wstaw_na_koniec(mlista2, 1);
    wstaw_na_koniec(mlista2, 10);
    wstaw_na_koniec(mlista2, 69);
    wstaw_na_koniec(mlista2,75);
    wstaw_na_koniec(mlista2, 80);
    wstaw_na_koniec(mlista2, 18);
    wypisz(mlista2);
    usun_po_k(mlista2,19);
    wypisz(mlista2);
	return 0;
}