// T0As2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "funkcje.h"


using namespace std;




int main()
{
    cout << "Hello World!\n";
    Tablica t1,t2;
    
    t1=Alokacja(10);
    for (int i = 0; i < t1.rozmiar; i++) {
        t1.tab[i] = i;
    }
    ZapisDoPliku("t1.txt", t1);
    t2=OdczytzPliku("t1.txt", 10);
    for (int i = 0; i < t2.rozmiar; i++) {
        if (t1.tab[i] == t2.tab[i]) {
            cout << "Zapis: " << t1.tab[i] << " Odczyt: " << t2.tab[i] << endl;
            if (i == (t1.rozmiar-1))cout << "Sa takie same";
        }
        else cout << "Nie sa takie same";
        
        
    }
    Dealokacja(t1);
    Dealokacja(t2);
    
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
