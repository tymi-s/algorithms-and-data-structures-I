#include <iostream>

using namespace std;

struct drzewo {
    int liczba;
    drzewo* prawo;
    drzewo* lewo;
};

//---------------USUWANIE/////////////////
void usun_element(drzewo*& korzen, int wartosc) {
    if (korzen == nullptr) {
        return;
    }

    if (korzen->liczba > wartosc) {
        usun_element(korzen->lewo, wartosc);
    }
    else if (korzen->liczba < wartosc) {
        usun_element(korzen->prawo, wartosc);
    }
    // znaleziono element - sprawzenie czy s¹ dzieci:
    else {
        // NIE MA DZIECI:
        if (korzen->lewo == nullptr && korzen->prawo == nullptr) {
            delete korzen;
            korzen = nullptr;
        }
        // DZIECKO Z PRAWEJ:
        
        else if (korzen->lewo == nullptr) {
            drzewo* temp = korzen;
            korzen = korzen->prawo;
            delete temp;
        }
       // DZIECKO Z LEWEJ
        else if (korzen->prawo == nullptr) {
            drzewo* temp = korzen;
            korzen = korzen->lewo;
            delete temp;
        }
        //  WIÊCEJ DZIECI
        else {
            drzewo* najmniejszy = korzen->prawo;
            while (najmniejszy->lewo != nullptr) {
                najmniejszy = najmniejszy->lewo;
            }
            korzen->liczba = najmniejszy->liczba;
            usun_element(korzen->prawo, najmniejszy->liczba);
        }
    }
}

// NAJMNIEJSZY ELEMENT
void najmniejszy(drzewo* korzen) {
    drzewo* temp = korzen;
    while (temp->lewo != nullptr) {
        temp = temp->lewo;
    }
    cout << "\nNAJMNIEJSZY ELEMENT DRZEWA: " <<temp->liczba;
    return;
}

// NAJWIEKSZY ELEMENT
void najwiekszy(drzewo* korzen) {
    drzewo* temp = korzen;
    while (temp->prawo != nullptr) {
        temp = temp->prawo;
    }
    cout << "\nNAJWIEKSZY ELEMENT DRZEWA: " << temp->liczba;
    return;
}

//\\\\\\\\\\\\\\\\\\\\\\\\\\\\DODANIE WÊZ£A//////////
drzewo* stworzWêze³(int wartoœæ) {
    drzewo* nowyWêze³ = new drzewo;
    nowyWêze³->liczba = wartoœæ;
    nowyWêze³->prawo = nullptr;
    nowyWêze³->lewo = nullptr;
    return nowyWêze³;
}

//\\\\\\\\\\\\\\\\\\\\\\\ DODANIE ELEMENTU DO DRZEWA//////////////

drzewo* dodaj(drzewo* korzen, int wartosc) {
    if (korzen == nullptr) {
        return stworzWêze³(wartosc);
    }
    if (wartosc < korzen->liczba) {
        korzen->lewo = dodaj(korzen->lewo, wartosc);
    }
    else if (wartosc > korzen->liczba) {
        korzen->prawo = dodaj(korzen->prawo, wartosc);
    }
    return korzen;
}

/// \\\\\\\\\\\\\\\\\\\\\\\\\\\\ WYPISANIE ELEMENTUW DRZEWA///////


void wypisz_wymaluj(drzewo* korzen) {
    if (korzen != nullptr) {
        wypisz_wymaluj(korzen->lewo);
        cout << korzen->liczba << "->";
        wypisz_wymaluj(korzen->prawo);
    }
}

//\\\\\\\\\\\\\\\\ PRZESZUKIWANIE//////////////

//------------ PREORDER //
void preorder(drzewo* korzen) {

    if (korzen == nullptr) {
        return;
    }
    cout << korzen->liczba << "->";
   
    preorder(korzen->lewo);

    preorder(korzen->prawo);
    

}

//----------- INORDER/////////
void inorder(drzewo* korzen) {
    if (korzen == nullptr) {
        return;
    }

  
    inorder(korzen->lewo);

    
    cout << korzen->liczba << "->";

    
    inorder(korzen->prawo);
}
//\\\\\\\ POSTORDER/////
void postorder(drzewo* korzen) {
    if (korzen == nullptr) {
        return;
    }
    postorder(korzen->lewo);
    postorder(korzen->prawo);
    cout << korzen->liczba << "->";
}


void   Height(drzewo* korzen) {
    int x = 1;
    int y = 1;
    drzewo* temp = korzen;
    while (temp->lewo != nullptr) {
        x++;
        temp = temp->lewo;
    }
    while (temp->lewo != nullptr) {
        y++;
        temp = temp->lewo;
    }
    if (y >= x) {
        cout << "\nDLUGOSC DRZEWA: " << y;
    }
    else if (x >= y) {
        cout << "\nDLUGOSC DRZEWA: " << x;
    }
    return;
    
}
drzewo* najwiekszyyy(drzewo* korzen) {
    drzewo* temp = korzen;
    while (temp->prawo != nullptr) {
        temp = temp->prawo;
    }

    return temp;
}
drzewo* najwiekszyy(drzewo* korzen) {
    drzewo* temp = korzen;
    while (temp->lewo != nullptr) {
        temp = temp->lewo;
    }
    
    return temp;
}
void Update(drzewo* korzen){
    drzewo* temp;
    if (korzen->liczba > 10) {
        temp=najwiekszyy(korzen);
        usun_element(korzen,temp->liczba);
    }
    else if (korzen->liczba < 10)
    {
        temp = najwiekszyyy(korzen);
        usun_element(korzen, temp->liczba);
    }
}
int main() {
    drzewo* poczatek = nullptr;
    poczatek = dodaj(poczatek, 5);
    poczatek = dodaj(poczatek, 10);
    poczatek = dodaj(poczatek, 15);
 
    poczatek = dodaj(poczatek, 16);
    poczatek = dodaj(poczatek, 88);
    poczatek = dodaj(poczatek, 1);
    poczatek = dodaj(poczatek, 60);
    poczatek = dodaj(poczatek, 0);
    wypisz_wymaluj(poczatek);
    usun_element(poczatek, 10);
    cout << endl;
    cout << "PO USUNIECIU:\n";
    wypisz_wymaluj(poczatek);
    cout << endl;
    najmniejszy(poczatek);
    najwiekszy(poczatek);
    cout << "\n\n";
    cout << "\nPREORDER:\n";
    preorder(poczatek);
    cout << "\n";
    cout << "\nINORDER:\n";
    inorder(poczatek);
    cout << "\n";
    cout << "\nPOSTORDER:\n";
    postorder(poczatek);

    cout << "\n\n WYPISANIE \n\n";

    wypisz_wymaluj(poczatek);
    cout << "\n\n";

    // ZADANIE:
    drzewo* zadanie = nullptr;
    zadanie = dodaj(zadanie, 9);
    zadanie = dodaj(zadanie, 5);
    zadanie = dodaj(zadanie, 4);
    zadanie = dodaj(zadanie, 1);
    zadanie = dodaj(zadanie, 8);
    zadanie = dodaj(zadanie, 9);
    zadanie = dodaj(zadanie, 15);
    zadanie = dodaj(zadanie, 10);
    zadanie = dodaj(zadanie, 12);
    zadanie = dodaj(zadanie, 11);
    zadanie = dodaj(zadanie, 18);
    zadanie = dodaj(zadanie, 19);
    cout << "\n\n DRZEWO DO ZADANIA:   ";
    wypisz_wymaluj(zadanie);
  
    Update(zadanie->prawo);
    cout << "\nPO USUNIECIU:         ";
    wypisz_wymaluj(zadanie);
    Update(zadanie);
    return 0;
}
