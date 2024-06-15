#pragma once
#include <string>
#include <vector>

#include "Obiekt.h"
// #include "dane.h"
namespace Books {

using namespace Objects;

class Ksiazka : public Obiekt {
    std::string tytul;
    std::string autor;
    std::string wydawnictwo;
    std::string gatunek;
    unsigned int rok_wydania;
    long ISBN;
    bool wypozyczona;
    std::vector<int> oceny;

    friend class Biblioteka;

   public:
    // konstruktor domyślny
    Ksiazka();

    // lista inicjalizacyjna
    Ksiazka(std::string, std::string, std::string, std::string, unsigned int, long, bool);

    // konstruktor kopiujący
    Ksiazka(const Ksiazka&);

    // destruktor
    ~Ksiazka();

    // przeciążony operator przypisania
    Ksiazka& operator=(const Ksiazka&);

    // konstruktor przenoszący
    Ksiazka(Ksiazka&&) noexcept;

    // przeciążony operator przypisania przenoszącego
    Ksiazka& operator=(Ksiazka&&) noexcept;

    friend std::ostream& operator<<(std::ostream&, const Ksiazka&);

    friend std::istream& operator>>(std::istream&, Ksiazka&);

    // Metody
    void wyswietl() const override;
    void edytuj() override;
    void gen_data() override;
    void ocen();
    std::tuple<std::string, std::string> tytul_i_autor() const;
    void get_data() const;

    // Gettery
    std::string get_tytul() const;
    std::string get_autor() const;
    std::string get_wydawnictwo() const;
    std::string get_gatunek() const;
    unsigned int get_rok_wydania() const;
    long get_ISBN() const;
    bool get_wypozyczona() const;
    std::vector<int> get_oceny() const;

    // Settery
    void set_tytul(std::string);
    void set_autor(std::string);
    void set_wydawnictwo(std::string);
    void set_gatunek(std::string);
    void set_rok_wydania(unsigned int);
    void set_ISBN(long);
    void set_wypozyczona(bool);
    void set_oceny(std::vector<int>);
};
}  // namespace Books