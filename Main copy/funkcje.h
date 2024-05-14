#ifndef FUNKCJE_H
#define FUNKCJE_H
#pragma once

#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <vector>

size_t generujLiczbeLosowa(size_t begin, size_t end);
void menuCzytelnikow();
void menuKsiazek();
void stworz(size_t& last_id, size_t ilosc);

void menuGlowne();

extern const size_t nImiona;
extern const size_t nNazwiska;
extern const size_t nUlice;
extern const size_t nEmaile;
extern const size_t nWydawnictwa;
extern const size_t nTytuly;
extern const size_t nDzialy;
extern std::string_view Imiona[];
extern std::string_view Nazwiska[];
extern std::string_view Ulice[];
extern std::string_view Emaile[];
extern std::string_view Wydawnictwa[];
extern std::string_view Dzialy[];
extern std::string_view Tytuly1[];
extern std::string_view Tytuly2[];

#endif
