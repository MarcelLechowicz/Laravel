// T0As6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "funkcje.h"
#include <cstdio> 

using namespace std;

int main()
{
    cout << "Hello World!\n";
    Struktura wzorzec,wzorzec2;
    wzorzec.x = 12;
    wzorzec.y = 23;
    wzorzec2.x = 1;
    wzorzec2.y = 2;
    int rozmiar = 83;
    Struktura* s1 = Alokacja(rozmiar, wzorzec);
    ZapisDoPliku(s1, "trzecikolos.txt", rozmiar);
    Struktura* s2 = OdczytZpliku("trzecikolos.txt",wzorzec2);
   /* for (int i = 0; i < rozmiar; i++) {
        cout << "X: " << s2[i].x << " Y: " << s2[i].y << endl;
    }*/
    for (int i = 0; i < rozmiar; i++) {
        if (((s2[i].x ^ s1[i].x)==0) && (((int)s2[i].y ^ (int)s1[i].y)==0)) {
            if (i == rozmiar - 1) {
                cout << "Sa takie same";
            }
        }
        else {
            cout << "Są rozne" << endl;
        }
    }

    Dealokacja(s1);
    Dealokacja(s2);
    
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
