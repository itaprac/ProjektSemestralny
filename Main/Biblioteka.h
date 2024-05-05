#pragma once
#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Czytelnik.h"
#include "Ksiazka.h"
class Biblioteka {
    static Biblioteka* biblioteka;
    Ksiazka** ksiazki;
    size_t liczba_ksiazek;
    std::vector<Czytelnik> czytelnicy;
    size_t last_id;

   public:
    static Biblioteka* get_biblioteka();

    // konstruktor domyślny
    Biblioteka();

    // lista inicjalizacyjna
    Biblioteka(Ksiazka** ksiazki, size_t liczba_ksiazek, std::vector<Czytelnik> czytelnicy, size_t last_id)
        : ksiazki(ksiazki), liczba_ksiazek(liczba_ksiazek), czytelnicy(czytelnicy), last_id(last_id){};

    // konstruktor kopiujący
    Biblioteka(const Biblioteka& right);

    // operator przypisania
    Biblioteka& operator=(const Biblioteka& right);

    // konstruktor przenoszący
    Biblioteka(Biblioteka&& other) noexcept;

    // operator przypisania przenoszącego
    Biblioteka& operator=(Biblioteka&& other) noexcept;

    // destruktor
    ~Biblioteka();

    // Metody

    void dodaj(Ksiazka* ksiazka);
    void dodaj(Czytelnik czytelnik);
    void stworzCzytelnikow(size_t ilosc);
    void stworzKsiazki(size_t ilosc);
    void utworzCzytelnika();
    void utworzKsiazke();
    void edytujKsiazke(size_t index);
    void edytujCzytelnika(size_t index);
    void usunKsiazke(size_t index);
    void usunCzytelnika(size_t index);
    void usun(Ksiazka* ksiazka);
    void usun(Czytelnik& czytelnik);
    void wyswietlCzytelnikow();
    void wyswietlKsiazki();
    Ksiazka& szukajKsiazki();
    Czytelnik& szukajCzytelnika();
    size_t szukajCzytelnikaPoID(size_t id);
    size_t szukajCzytelnikaPoImieniu(std::string imie);
    size_t szukajKsiazkiPoTytule(std::string tytul);
    size_t szukajKsiazkiPoISBN(long ISBN);
    void wypozycz();
    void zwroc(Czytelnik& czytelnik, Ksiazka* ksiazka);

    // Gettery
    Ksiazka** get_ksiazki() const;
    size_t get_liczba_ksiazek() const;
    std::vector<Czytelnik> get_czytelnicy() const;
    size_t get_last_id() const;

    // Settery
    void set_ksiazki(Ksiazka** ksiazki);
    void set_liczba_ksiazek(size_t liczba_ksiazek);
    void set_czytelnicy(std::vector<Czytelnik> czytelnicy);
    void set_last_id(size_t last_id);
};