// T0As1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio> 
#include <iostream>
#include <bitset>
#include "funkcje.h"

using namespace std;



int main()
{
    cout << "Hello World!\n";
    short* tab = Alokacja(10);
    short* kopia;
    ZapisDoPliku(tab,"siema.txt");
    kopia =  OdczytZpliku( "siema.txt");
    for (int i = 0; i < 10; i++) {
        cout << kopia[i];
    }
    cout << "\nKopia: " << kopia[-1];
    cout << "\nOrginał: " << tab[-1];

    short* tab1 = Alokacja(4);
    short* tab2 = Alokacja(6);
    short* tab3 = Alokacja(8);
    short* tab4 = Alokacja(10);

    ZapisDoPliku(tab1, "tablica1.txt");
    ZapisDoPliku(tab2, "tablica2.txt");
    ZapisDoPliku(tab3, "tablica3.txt");
    ZapisDoPliku(tab4, "tablica4.txt");

    int wybor;
    short* odczyt;
    cout << "Podaj tablice do zapisu(1-4)" << endl;
    cin >> wybor;
    switch (wybor) {
    case 1:
        odczyt = OdczytZpliku("tablica1.txt");
        break;
    case 2:
        odczyt = OdczytZpliku("tablica2.txt");
        break;
    case 3:
        odczyt = OdczytZpliku("tablica3.txt");
        break;
    case 4:
        odczyt = OdczytZpliku("tablica4.txt");
        break;

    default:
        cout << "Z racji podania zlego numeru tablicy odczytujemy tablice o numerze 1";
        odczyt = OdczytZpliku("tablica1.txt");
        break;
    }
    int rozmiar = odczyt[-1] >> 8;
    short ktoraTablica= odczyt[-1] << 8;
    ktoraTablica = ktoraTablica >> 8;
    cout << "\n";
    cout << "rozmiar wybranej tablicy: " << (odczyt[-1] >> 8) << endl;
   // cout << "numer tablicy zapisanej od poczatku programu: " << ktoraTablica << endl;
    for (int i = 0; i < rozmiar; i++) {
        cout  << odczyt[i] << endl;
    }


    Dealokacja(tab1);
    Dealokacja(tab2);
    Dealokacja(tab3);
    Dealokacja(tab4);
    Dealokacja(tab);
    Dealokacja(kopia);
    Dealokacja(odczyt);
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
