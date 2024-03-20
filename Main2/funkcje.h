#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>
#include <vector>

#include "struktury.h"

void menuGlowne();

void menuCzytelnikow(std::vector<Czytelnik>& czytelnicy, size_t& last_id);

void menuKsiazek(Ksiazka**& ksiazki, size_t& liczba_ksiazek);

void dodaj(std::vector<Czytelnik>& czytelnicy, size_t& last_id);

void wyswietl(std::vector<Czytelnik>& czytelnicy);

void edytuj(std::vector<Czytelnik>& czytelnicy, size_t index);

void usun(std::vector<Czytelnik>& czytelnicy, size_t index);

void dodaj(Ksiazka**& ksiazki, size_t& liczba_ksiazek);

void wyswietl(Ksiazka**& ksiazki, size_t& liczba_ksiazek);

void edytuj(Ksiazka**& ksiazki, size_t index);

void usun(Ksiazka**& ksiazki, size_t& liczba_ksiazek, size_t index);

void gen_data(Czytelnik& czytelnik);

void stworz(std::vector<Czytelnik>& czytelnicy, size_t& last_id, size_t rozmiar);

void stworz(Ksiazka*& ksiazka);

void stworz(Ksiazka**& ksiazki, size_t rozmiar, size_t& liczba_ksiazek);

void usun(Ksiazka**& ksiazki, size_t& liczba_ksiazek);

size_t generujLiczbeLosowa(size_t begin, size_t end);

#endif