#pragma once
#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Czytelnik.h"
#include "Ksiazka.h"
#include "Obiekt.h"
class Biblioteka {
    static Biblioteka* biblioteka;
    Ksiazka** ksiazki;
    size_t liczba_ksiazek;
    std::vector<Czytelnik> czytelnicy;
    size_t last_id;
    Obiekt** usuniete_elementy;
    size_t liczba_usunietych;

   public:
    static Biblioteka* get_biblioteka();

    // konstruktor domyślny
    Biblioteka();

    // lista inicjalizacyjna
    Biblioteka(Ksiazka**, size_t, std::vector<Czytelnik>, size_t, Obiekt**, size_t);

    // konstruktor kopiujący
    Biblioteka(const Biblioteka&);

    // operator przypisania
    Biblioteka& operator=(const Biblioteka&);

    // konstruktor przenoszący
    Biblioteka(Biblioteka&&) noexcept;

    // operator przypisania przenoszącego
    Biblioteka& operator=(Biblioteka&&) noexcept;

    // destruktor
    ~Biblioteka();

    // Metody

    void dodaj(Ksiazka*);
    void dodaj(Czytelnik);
    void stworzCzytelnikow(size_t);
    void stworzKsiazki(size_t);
    void utworzCzytelnika();
    void utworzKsiazke();
    void edytujKsiazke(size_t);
    void edytujCzytelnika(size_t);
    void usunKsiazke(size_t);
    void usunCzytelnika(size_t);
    void usun(Ksiazka*);
    void usun(Czytelnik&);
    void wyswietlCzytelnikow();
    void wyswietlKsiazki();
    Ksiazka* szukajKsiazki();
    Czytelnik& szukajCzytelnika();
    size_t szukajCzytelnikaPoID(size_t);
    size_t szukajCzytelnikaPoImieniu(std::string);
    size_t szukajKsiazkiPoTytule(std::string);
    size_t szukajKsiazkiPoISBN(long);
    void wypozycz();
    void zwroc();
    void wyswietlUsuniete();
    void powiekszTabliceElementow();

    // Gettery
    Ksiazka** get_ksiazki() const;
    size_t get_liczba_ksiazek() const;
    std::vector<Czytelnik> get_czytelnicy() const;
    size_t get_last_id() const;
    Obiekt** get_usuniete_elementy() const;
    size_t get_liczba_usunietych() const;

    // Settery
    void set_ksiazki(Ksiazka**);
    void set_liczba_ksiazek(size_t);
    void set_czytelnicy(std::vector<Czytelnik>);
    void set_last_id(size_t);
    void set_usuniete_elementy(Obiekt**);
    void set_liczba_usunietych(size_t);
};