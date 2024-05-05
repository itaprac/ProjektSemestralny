#pragma once
#include <string>

#include "WyswietlalnyEdytowalny.h"
#include "dane.h"

class Ksiazka : public WyswietlalnyEdytowalny {
    std::string tytul;
    std::string autor;
    std::string wydawnictwo;
    std::string gatunek;
    unsigned int rok_wydania;
    long ISBN;
    bool wypozyczona;

    friend class Biblioteka;

   public:
    // konstruktor domyślny
    Ksiazka();

    // lista inicjalizacyjna
    Ksiazka(std::string tytul, std::string autor, std::string wydawnictwo, std::string gatunek,
            unsigned int rok_wydania, long ISBN, bool wypozyczona);

    // konstruktor kopiujący
    Ksiazka(const Ksiazka& right);

    // destruktor
    ~Ksiazka();

    // przeciążony operator przypisania
    Ksiazka& operator=(const Ksiazka& right);

    // konstruktor przenoszący
    Ksiazka(Ksiazka&& other) noexcept;

    // przeciążony operator przypisania przenoszącego
    Ksiazka& operator=(Ksiazka&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& output, const Ksiazka& ksiazka);

    friend std::istream& operator>>(std::istream& input, Ksiazka& ksiazka);

    // Metody
    void wyswietl() const override;
    void edytuj() override;
    void gen_data();

    // Gettery
    std::string get_tytul() const;
    std::string get_autor() const;
    std::string get_wydawnictwo() const;
    std::string get_gatunek() const;
    unsigned int get_rok_wydania() const;
    long get_ISBN() const;
    bool get_wypozyczona() const;

    // Settery
    void set_tytul(std::string tytul);
    void set_autor(std::string autor);
    void set_wydawnictwo(std::string wydawnictwo);
    void set_gatunek(std::string gatunek);
    void set_rok_wydania(unsigned int rok_wydania);
    void set_ISBN(long ISBN);
    void set_wypozyczona(bool wypozyczona);
};