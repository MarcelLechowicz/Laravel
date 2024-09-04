#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio> 
#include <iostream>
#include <bitset>
#include "funkcje.h"

using namespace std;


short* Alokacja(int rozmiar) {
    if (rozmiar > 1) {
        static int IleRazy = 1;
        short* tab = new short[rozmiar + 1] {};
        tab[0] = IleRazy;
        tab[0] = tab[0] << 8;
        tab[0] = tab[0] | rozmiar;

        IleRazy++;
        return tab + 1;
    }
    else cerr << "Niepoprawny rozmiar" << endl;
}
void Dealokacja(short* t) {
    if (t != nullptr) {
        delete[](t - 1);
    }
    else cerr << "Wskaznik jest uziemiony" << endl;
}
void ZapisDoPliku(const char* nazwaPliku, short* t) {
    FILE* plik = fopen(nazwaPliku, "w+b");
    if ((plik != nullptr) && (t != nullptr)) {
        // cout << " tab: " << bitset<16>(t[-1]) << endl;

        short rozmiar = t[-1] << 8;
        // cout << " Rozmiar juz przesuniety: " << bitset<16>(rozmiar) << endl;
        rozmiar = rozmiar >> 8;
        // cout << " Rozmiar ponownie przesuniety: " << bitset<16>(rozmiar) << endl;
        fwrite(&rozmiar, sizeof(short), 1, plik);
        fwrite(t, sizeof(short), rozmiar, plik);
        fclose(plik);
    }
    else cerr << "Blad podczas otwarcia pliku lub z podanym wskaznikiem" << endl;

}
short* OdczytZpliku(const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "r+b");
    if (plik != nullptr) {
        short rozmiar;
        fread(&rozmiar, sizeof(short), 1, plik);
        //cout << rozmiar;
        short* tab = Alokacja(rozmiar);
        fread(tab, sizeof(short), rozmiar, plik);
        fclose(plik);
        return tab;
    }
    else cerr << "Blad podczas otwarcia pliku" << endl;

}