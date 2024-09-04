#include "funkcje.h"
#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio> 
#include <iostream>
#include <bitset>


using namespace std;

short* Alokacja(int rozmiar) {
    static int ktoraTablica = 1;
    if (rozmiar > 0) {
        short* tablica = new short[rozmiar + 1] {};
        tablica[0] = rozmiar;
        tablica[0] = tablica[0] << 8;
        tablica[0] = tablica[0] | ktoraTablica;
        ktoraTablica++;
        //cout<< bitset<16>(tablica[0]) << endl;
        return tablica + 1;
    }
    else throw invalid_argument("");


}
void Dealokacja(short* tab) {
    if (tab != nullptr) {
        delete[](tab - 1);
        tab = nullptr;
    }
}
void ZapisDoPliku(short* tablica, const char* Nazwapliku) {
    FILE* plik = fopen(Nazwapliku, "w+b");
    if (plik != nullptr) {
        short rozmiar = tablica[-1] >> 8;

        fwrite(&rozmiar, sizeof(short), 1, plik);
        fwrite(tablica, sizeof(short), rozmiar, plik);
        fclose(plik);

    }
    else {
        cerr << "Nie mozna otworzyc pliku do zapisu!" << endl;
    }
}
short* OdczytZpliku(const char* Nazwapliku) {
    FILE* plik = fopen(Nazwapliku, "r+b");
    if (plik != nullptr) {

        short rozmiar;
        fread(&rozmiar, sizeof(short), 1, plik);
        short* kopia = Alokacja(rozmiar);
        fread(kopia, sizeof(short), rozmiar, plik);
        fclose(plik);
        return kopia;
    }
    else {
        cerr << "Nie mozna otworzyc pliku";
    }

}