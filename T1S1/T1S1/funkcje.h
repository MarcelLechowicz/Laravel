#pragma once

short* Alokacja(int rozmiar);
void Dealokacja(short* t);
void ZapisDoPliku(const char* nazwaPliku, short* t);
short* OdczytZpliku(const char* nazwaPliku);