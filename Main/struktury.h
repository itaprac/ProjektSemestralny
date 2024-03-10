#include <iostream>
#include <string>
#include <vector>

struct Adres {
    std::string ulica;
    unsigned int numerDomu;
};

struct Lokalizacja {
    std::string dzial;
    unsigned int numerRegalu;
};

struct Ksiazka {
    std::string tytul;
    std::string autor;
    std::string wydawnictwo;
    unsigned int rokWydania;
    Lokalizacja lokalizacja;
    bool dostepna = true;
};

struct Czytelnik {
    std::string imie;
    std::string email;
    std::string numerTelefonu;
    unsigned int numerID;
    Adres adres;
    std::vector<Ksiazka> wypozyczoneKsiazki;
};
