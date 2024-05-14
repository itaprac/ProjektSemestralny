#pragma once
#include <iostream>
#include <string>

#include "Ksiazka.h"
#include "funkcje.h"

class Czytelnik final : public Ksiazka {
    class Adres {
        std::string ulica;
        unsigned int numer_domu;
        friend class Czytelnik;

       public:
        // konstruktor domyślny
        Adres() {
            ulica = "ulica";
            numer_domu = generujLiczbeLosowa(1, 100);
        };

        // lista inicjalizacyjna
        Adres(std::string ulica, unsigned int numer_domu) : ulica(ulica), numer_domu(numer_domu){};

        // konstruktor kopiujący
        Adres(const Adres& right) {
            ulica = right.ulica;
            numer_domu = right.numer_domu;
        }

        // destruktor
        ~Adres();

        // przeciążony operator przypisania
        Adres& operator=(const Adres& right) {
            if (this == &right) {
                return *this;
            }

            ulica = right.ulica;
            numer_domu = right.numer_domu;

            return *this;
        }

        // konstruktor przenoszący
        Adres(Adres&& other) noexcept {
            ulica = std::move(other.ulica);
            numer_domu = std::move(other.numer_domu);
        }

        // przeciążony operator przypisania przenoszącego
        Adres& operator=(Adres&& other) noexcept {
            if (this == &other) {
                return *this;
            }

            ulica = std::move(other.ulica);
            numer_domu = std::move(other.numer_domu);

            return *this;
        }

        // operator <<
        friend std::ostream& operator<<(std::ostream& output, const Adres& adres) {
            output << adres.ulica << " " << adres.numer_domu;
            return output;
        }

        // operator >>
        friend std::istream& operator>>(std::istream& input, Adres& adres) {
            std::cout << "Ulica: ";
            std::getline(input, adres.ulica);
            std::cout << "Numer domu: ";
            input >> adres.numer_domu;
            return input;
        }

        // operator ==
        bool operator==(const Adres& right) const { return ulica == right.ulica && numer_domu == right.numer_domu; }

        // Gettery
        std::string get_ulica() const { return ulica; }
        unsigned int get_numer_domu() const { return numer_domu; }

        // Settery
        void set_ulica(std::string ulica) { this->ulica = ulica; }
        void set_numer_domu(unsigned int numer_domu) { this->numer_domu = numer_domu; }
    };

    std::string imie;
    std::string email;
    std::string numer_telefonu;
    unsigned int numer_ID;
    Adres adres;
    Ksiazka** wypozyczone_ksiazki;
    size_t liczba_wypozyczonych_ksiazek;
    mutable size_t licznik_wyswietlen;

    friend class Biblioteka;

    void powiekszTablice();

   public:
    // konstruktor domyślny
    Czytelnik();

    Czytelnik(std::string, std::string, std::string, unsigned int, Adres);

    // konstruktor kopiujący
    Czytelnik(const Czytelnik&);

    // destruktor
    ~Czytelnik();

    // przeciążony operator przypisania
    Czytelnik& operator=(const Czytelnik&);

    // operator ==
    bool operator==(const Czytelnik&) const;

    // konstruktor przenoszący
    Czytelnik(Czytelnik&&) noexcept;

    // przeciążony operator przypisania przenoszącego
    Czytelnik& operator=(Czytelnik&&) noexcept;

    friend std::ostream& operator<<(std::ostream&, const Czytelnik&);

    friend std::istream& operator>>(std::istream&, Czytelnik&);

    Ksiazka& operator[](size_t);

    const Ksiazka& operator[](size_t) const;

    // Metody
    void wyswietl() const override;
    void edytuj() override;
    void dodaj(Ksiazka*);
    void gen_data() override;

    // Gettery
    std::string get_imie() const;
    std::string get_email() const;
    std::string get_numer_telefonu() const;
    unsigned int get_numer_ID() const;
    Adres get_adres() const;
    std::string get_ulica() const;
    unsigned int get_numer_domu() const;
    Ksiazka** get_wypozyczone_ksiazki() const;
    size_t get_liczba_wypozyczonych_ksiazek() const;

    // Settery
    void set_imie(std::string);
    void set_email(std::string);
    void set_numer_telefonu(std::string);
    void set_numer_ID(unsigned int);
    void set_adres(Adres);
    void set_ulica(std::string);
    void set_numer_domu(unsigned int);
    void set_wypozyczone_ksiazki(Ksiazka**);
    void set_liczba_wypozyczonych_ksiazek(size_t);
};