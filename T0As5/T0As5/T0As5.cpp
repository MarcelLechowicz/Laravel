// T0As5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <cstdio>

using namespace std;

struct Tablica {
    short* tab;
    int rozmiar;
};

Tablica Alokacja(int rozmiar) {
    if (rozmiar > 1) {
        Tablica t1;
        t1.tab = new short[rozmiar] {};
        t1.rozmiar = rozmiar;
        return t1;
    }
    else cerr << "Bledny rozmiar" << endl;
}
void Dealokacja(Tablica &t) {
    if (t.tab != nullptr) {
        delete[](t.tab);
        t.tab = nullptr;
    }
    else cerr << "Blad z podanym wskaznikiem" << endl;
}
void ZapisDoPliku(Tablica &t,const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku,"w");
    if (plik != nullptr) {
        if (t.tab != nullptr) {
            for (int i = 0; i < t.rozmiar; i++) {
                fprintf(plik, "%d;", t.tab[i]);
            }
            fclose(plik);
        }
        else cerr << "Blad z podanym wskaznikiem" << endl;
    }
    else cerr << "Blad z otwarciem pliku" << endl;
}
Tablica OdczytZpliku(const char* nazwaPliku,int rozmiar) {
    FILE* plik = fopen(nazwaPliku, "r");
    if (plik != nullptr) {
        Tablica t = Alokacja(rozmiar);
       for (int i = 0; i < t.rozmiar; i++) {
           fscanf(plik, "%d;", &t.tab[i]);
       }
       fclose(plik);
       return t;
    }
    else cerr << "Blad z otwarciem pliku" << endl;
}

int main()
{
    Tablica t1, t2;
    t1 = Alokacja(10);
    for (int i = 0; i < 10; i++) {
        t1.tab[i] = i;
    }
    ZapisDoPliku(t1, "proba.txt");
    t2 = OdczytZpliku("proba.txt", 10);
    for (int i = 0; i < t1.rozmiar; i++) {
        if (t1.tab[i] == t2.tab[i]) {
            cout << "Zapis: " << t1.tab[i] << " Odczyt: " << t2.tab[i] << endl;
            if (i == t1.rozmiar - 1) {
                cout << "Tablice sa takie same" << endl;
            }
        }
        else {
            cout << "Tablice sie roznia" << endl;
            break;
        }
        

    }
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
