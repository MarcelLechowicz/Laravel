
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "funkcje.h"
#include <cstdio> 

using namespace std;


Struktura* Alokacja(int rozmiar, Struktura s) {
    Struktura* wsk = new Struktura[rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        wsk[i].x = s.x;
        wsk[i].y = s.y;
    }
    return wsk;

}
void Dealokacja(Struktura* s) {
    if (s != nullptr) {
        delete[] s;
        s = nullptr;
    }
    else cerr << "Blad!!!";
}
void ZapisDoPliku(Struktura* s, const char* nazwaPliku, int rozmiar) {
    FILE* plik = fopen(nazwaPliku, "w");
    if (plik != nullptr)
    {
        if ((s != nullptr) && (rozmiar > 0)) {
            fprintf(plik, "%d;\n", rozmiar);
            for (int i = 0; i < rozmiar; i++) {
                fprintf(plik, "%d;%f; ", s[i].x, s[i].y);
            }
            fclose(plik);
        }
        else cerr << "Problem z rozmiarem lub wskaznikiem";
    }
    else cerr << "Nie mozna otworzyc pliku";
}
Struktura* OdczytZpliku(const char* nazwaPliku, Struktura s) {
    FILE* plik = fopen(nazwaPliku, "r");
    if (plik != nullptr)
    {
        int rozmiar = 0;
        fscanf(plik, "%d;\n", &rozmiar);
        Struktura* tab = Alokacja(rozmiar, s);
        for (int i = 0; i < rozmiar; i++) {
            fscanf(plik, "%d;%lf; ", &tab[i].x, &tab[i].y);
        }
        return tab;
        fclose(plik);
    }
    else cerr << "Nie mozna otworzyc pliku";
}