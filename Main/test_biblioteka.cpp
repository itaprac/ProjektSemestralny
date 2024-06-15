#include <gtest/gtest.h>

#include "Biblioteka.h"
#include "Czytelnik.h"
#include "Ksiazka.h"

TEST(BibliotekaTest, DodajCzytelnika) {
    Biblioteka* biblioteka = Biblioteka::get_biblioteka();
    size_t initial_size = biblioteka->get_czytelnicy().size();
    Czytelnik nowyCzytelnik("Jan", "jan@example.com", "123456789", 1, Czytelnik::Adres("Ulica", 1));
    biblioteka->dodaj(nowyCzytelnik);
    EXPECT_EQ(biblioteka->get_czytelnicy().size(), initial_size + 1);
}

TEST(BibliotekaTest, SzukajCzytelnikaPoID) {
    Biblioteka* biblioteka = Biblioteka::get_biblioteka();
    Czytelnik nowyCzytelnik("Jan", "jan@example.com", "123456789", 1, Czytelnik::Adres("Ulica", 1));
    biblioteka->dodaj(nowyCzytelnik);
    size_t index = biblioteka->szukajCzytelnikaPoID(1);
    EXPECT_NE(index, -1);
    EXPECT_EQ(biblioteka->get_czytelnicy().at(index).get_imie(), "Jan");
}

TEST(BibliotekaTest, DodajKsiazke) {
    Biblioteka* biblioteka = Biblioteka::get_biblioteka();
    size_t initial_size = biblioteka->get_ksiazki().size();
    Ksiazka* nowaKsiazka = new Ksiazka("Tytul", "Autor", "Wydawnictwo", "Gatunek", 2023, 1234567890123, false);
    biblioteka->dodaj(nowaKsiazka);
    EXPECT_EQ(biblioteka->get_ksiazki().size(), initial_size + 1);
}

TEST(BibliotekaTest, SzukajKsiazkiPoISBN) {
    Biblioteka* biblioteka = Biblioteka::get_biblioteka();
    Ksiazka* nowaKsiazka = new Ksiazka("Tytul", "Autor", "Wydawnictwo", "Gatunek", 2023, 1234567890123, false);
    biblioteka->dodaj(nowaKsiazka);
    size_t index = biblioteka->szukajKsiazkiPoISBN(1234567890123);
    EXPECT_NE(index, -1);
    EXPECT_EQ(biblioteka->get_ksiazki().at(index)->get_tytul(), "Tytul");
}
