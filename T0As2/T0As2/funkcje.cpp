#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "funkcje.h"

using namespace std;



Tablica Alokacja(int roz) {
    if (roz > 0) {
        Tablica tablica;
        tablica.rozmiar = roz;
        tablica.tab = new int[roz] {};
        return tablica;
    }

}
void Dealokacja(Tablica& t) {
    if (t.tab != nullptr) {
        delete[](t.tab);
        t.tab = nullptr;
    }
    else cerr << "Nie mo¿na zdealokowaæ tablicy" << endl;

}
void ZapisDoPliku(const char* nazwa, Tablica& t) {
    FILE* plik = fopen(nazwa, "w");
    if (plik != nullptr) {
        if (t.tab != nullptr) {
            for (int i = 0; i < t.rozmiar; i++) {
                fprintf(plik, "%d;", t.tab[i]);
            }
            fclose(plik);
        }
        else cerr << "Wskaznik rowna sie nullptr";

    }
    else cerr << "Nie mo¿na otworzyæ pliku" << endl;

}
Tablica OdczytzPliku(const char* nazwa, int rozmiar) {
    FILE* plik = fopen(nazwa, "r");
    if (plik != nullptr) {
        int i = 0;
        Tablica t;
        t = Alokacja(rozmiar);
        for (int i = 0; i < rozmiar; i++) {

            fscanf(plik, "%d;", &t.tab[i]);

        }

        fclose(plik);
        return  t;
    }
    else cerr << "Nie mo¿na otworzyæ pliku" << endl;

}