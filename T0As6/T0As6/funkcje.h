#pragma once

struct Struktura {
    int x;
    double y;

};
Struktura* Alokacja(int rozmiar, Struktura s);
void Dealokacja(Struktura* s);
void ZapisDoPliku(Struktura* s, const char* nazwaPliku, int rozmiar);
Struktura* OdczytZpliku(const char* nazwaPliku, Struktura s);

