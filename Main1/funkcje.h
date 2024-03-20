#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>
#include <vector>

#include "struktury.h"

void menuGlowne();

void menuCzytelnikow(std::vector<Czytelnik>& czytelnicy, size_t& last_id);

void menuKsiazek(std::vector<Ksiazka>& ksiazki);

void dodaj(std::vector<Czytelnik>& czytelnicy, size_t& last_id);

void wyswietl(std::vector<Czytelnik>& czytelnicy);

void edytuj(std::vector<Czytelnik>& czytelnicy, size_t index);

void usun(std::vector<Czytelnik>& czytelnicy, size_t index);

void dodaj(std::vector<Ksiazka>& ksiazki);

void wyswietl(std::vector<Ksiazka>& ksiazki);

void edytuj(std::vector<Ksiazka>& ksiazki, size_t index);

void usun(std::vector<Ksiazka>& ksiazki, size_t index);

#endif