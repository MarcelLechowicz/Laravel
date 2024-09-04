// T1S1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio> 
#include <iostream>
#include <bitset>
#include "funkcje.h"

using namespace std;




int main()
{
    short* t1 = Alokacja(4);
    short* t2 = Alokacja(6);
    short* t3 = Alokacja(8);
    

    for (int i = 0; i < 4; i++) {
        t1[i] = i;
    }
    for (int i = 0; i < 6; i++) {
        t2[i] = i*10;
    }
    for (int i = 0; i < 8; i++) {
        t3[i] = i * 100;
    }
    short rozmiar1, rozmiar2, rozmiar3;
    rozmiar1 = t1[-1] << 8;
    rozmiar1 = rozmiar1 >> 8;
    rozmiar2 = t2[-1] << 8;
    rozmiar2 = rozmiar2 >> 8;
    rozmiar3 = t3[-1] << 8;
    rozmiar3 = rozmiar3 >> 8;
    short* najwiekszaTablica = nullptr;
    short najwiekszyRozmiar = 0;

    if (rozmiar1 > rozmiar2 && rozmiar1 > rozmiar3) {
        najwiekszaTablica = t1;
        najwiekszyRozmiar = rozmiar1;
    }
    else if (rozmiar2 > rozmiar1 && rozmiar2 > rozmiar3) {
        najwiekszaTablica = t2;
        najwiekszyRozmiar = rozmiar2;
    }
    else {
        najwiekszaTablica = t3;
        najwiekszyRozmiar = rozmiar3;
    }
    ZapisDoPliku("Adi.txt", najwiekszaTablica);
    short* odczyt;
    odczyt = OdczytZpliku("Adi.txt");
    short rozmiarOdczyt = odczyt[-1] << 8;
    rozmiarOdczyt = rozmiarOdczyt >> 8;
    for (int i = 0; i < najwiekszyRozmiar; i++) {
        if ((rozmiarOdczyt == najwiekszyRozmiar) && (odczyt[i] == najwiekszaTablica[i])) {
            cout << "Odczyt: " << odczyt[i] << " Zapis: " << najwiekszaTablica[i] << endl;
            if (i==najwiekszyRozmiar - 1) {

                cout << "Sa takie same" << endl;
            }
        }
        else cout << "Sa rozne" << endl;
    }
    Dealokacja(t1);
    Dealokacja(t2);
    Dealokacja(t3);
    Dealokacja(odczyt);
    najwiekszaTablica = nullptr;
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
