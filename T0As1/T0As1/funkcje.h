#pragma once

using namespace std;

short* Alokacja(int rozmiar); 
void Dealokacja(short* tab);
void ZapisDoPliku(short* tablica, const char* Nazwapliku);
short* OdczytZpliku(const char* Nazwapliku);
