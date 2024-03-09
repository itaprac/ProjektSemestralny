#include <iostream>
#include <string>
#include <vector>

struct Adres {
    std::string ulica;
    size_t numerDomu;
};

struct Lokalizacja {
    std::string dzial;
    size_t numerRegalu;
};

struct Ksiazka {
    std::string tytul;
    std::string autor;
    std::string wydawnictwo;
    size_t rokWydania;
    Lokalizacja lokalizacja;
    bool dostepna = true;
};

struct Czytelnik {
    std::string imie;
    std::string email;
    size_t numerTelefonu;
    size_t numerID;
    Adres adres;
    std::vector<Ksiazka> wypozyczoneKsiazki;
};
