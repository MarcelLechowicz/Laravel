#pragma once

struct Tablica {
    int* tab;
    int rozmiar;
};
Tablica Alokacja(int roz);
void Dealokacja(Tablica& t);
void ZapisDoPliku(const char* nazwa, Tablica& t);
Tablica OdczytzPliku(const char* nazwa, int rozmiar);
