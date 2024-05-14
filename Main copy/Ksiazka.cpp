#include "Ksiazka.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// #include "dane.h"
#include "funkcje.h"

// konstruktor domyślny
Ksiazka::Ksiazka() {
    tytul = "tytul";
    autor = "autor";
    wydawnictwo = "wydawnictwo";
    gatunek = "gatunek";
    rok_wydania = generujLiczbeLosowa(1900, 2021);
    ISBN = generujLiczbeLosowa(1000000000000, 9999999999999);
    wypozyczona = false;
};

// lista inicjalizacyjna
Ksiazka::Ksiazka(std::string tytul, std::string autor, std::string wydawnictwo, std::string gatunek,
                 unsigned int rok_wydania, long ISBN, bool wypozyczona)
    : tytul(tytul),
      autor(autor),
      wydawnictwo(wydawnictwo),
      gatunek(gatunek),
      rok_wydania(rok_wydania),
      ISBN(ISBN),
      wypozyczona(wypozyczona){};

// konstruktor kopiujący
Ksiazka::Ksiazka(const Ksiazka& right) {
    tytul = right.tytul;
    autor = right.autor;
    wydawnictwo = right.wydawnictwo;
    gatunek = right.gatunek;
    rok_wydania = right.rok_wydania;
    ISBN = right.ISBN;
    wypozyczona = right.wypozyczona;
    for (int i = 0; i < right.oceny.size(); i++) {
        oceny.push_back(right.oceny[i]);
    }
};

// operator przypisania
Ksiazka& Ksiazka::operator=(const Ksiazka& right) {
    if (this == &right) {
        return *this;
    }

    tytul = right.tytul;
    autor = right.autor;
    wydawnictwo = right.wydawnictwo;
    gatunek = right.gatunek;
    rok_wydania = right.rok_wydania;
    ISBN = right.ISBN;
    wypozyczona = right.wypozyczona;
    for (int i = 0; i < right.oceny.size(); i++) {
        oceny.push_back(right.oceny[i]);
    }

    return *this;
};

// konstruktor przenoszący
Ksiazka::Ksiazka(Ksiazka&& other) noexcept
    : tytul(std::move(other.tytul)),
      autor(std::move(other.autor)),
      wydawnictwo(std::move(other.wydawnictwo)),
      gatunek(std::move(other.gatunek)),
      rok_wydania(std::move(other.rok_wydania)),
      ISBN(std::move(other.ISBN)),
      wypozyczona(std::move(other.wypozyczona)),
      oceny(std::move(other.oceny)){};

// operator przypisania przenoszącego
Ksiazka& Ksiazka::operator=(Ksiazka&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    tytul = std::move(other.tytul);
    autor = std::move(other.autor);
    wydawnictwo = std::move(other.wydawnictwo);
    gatunek = std::move(other.gatunek);
    rok_wydania = std::move(other.rok_wydania);
    ISBN = std::move(other.ISBN);
    wypozyczona = std::move(other.wypozyczona);
    oceny = std::move(other.oceny);

    return *this;
};

// operator <<
std::ostream& operator<<(std::ostream& output, const Ksiazka& ksiazka) {
    output << "Tytul: " << ksiazka.tytul << std::endl;
    output << "Autor: " << ksiazka.autor << std::endl;
    output << "Wydawnictwo: " << ksiazka.wydawnictwo << std::endl;
    output << "Gatunek: " << ksiazka.gatunek << std::endl;
    output << "Rok wydania: " << ksiazka.rok_wydania << std::endl;
    output << "ISBN: " << ksiazka.ISBN << std::endl;
    if (ksiazka.oceny.size() == 0) {
        output << "Ocena: Brak ocen" << std::endl;
    } else {
        int suma = 0;
        int dzielnik = 0;
        for (const auto& ocena : ksiazka.oceny) {
            suma += ocena;
            dzielnik++;
        }
        output << "Ocena: " << std::fixed << std::setprecision(2) << (float)suma / dzielnik << std::endl;
    }
    output << "Wypozyczona: " << (ksiazka.wypozyczona ? "Tak" : "Nie") << std::endl;

    return output;
};

// operator >>
std::istream& operator>>(std::istream& input, Ksiazka& ksiazka) {
    std::cout << "Podaj tytul: ";
    std::getline(input, ksiazka.tytul);
    std::cout << "Podaj autora: ";
    std::getline(input, ksiazka.autor);
    std::cout << "Podaj wydawnictwo: ";
    std::getline(input, ksiazka.wydawnictwo);
    std::cout << "Podaj gatunek: ";
    std::getline(input, ksiazka.gatunek);
    std::cout << "Podaj rok wydania: ";
    input >> ksiazka.rok_wydania;
    input.ignore();
    std::cout << "Podaj ISBN: ";
    input >> ksiazka.ISBN;
    input.ignore();
    std::cout << "Podawaj oceny od 1-5(-1 konczy wprowadzanie): ";
    int ocena;
    while (true) {
        input >> ocena;
        input.ignore();
        if (ocena == -1) {
            break;
        }
        ksiazka.oceny.push_back(ocena);
    }

    return input;
};

Ksiazka::~Ksiazka(){};

// Metody
void Ksiazka::wyswietl() const {
    std::cout << *this;
    std::cout << "-----------------------------------------\n";
};

void Ksiazka::edytuj() {
    int wybor;
    do {
        std::cout << "Wybor: ";
        std::cin >> wybor;
        std::cin.ignore();
        switch (wybor) {
            case 1:
                std::cout << "Podaj nowy tytul: ";
                std::getline(std::cin, tytul);
                break;
            case 2:
                std::cout << "Podaj nowego autora: ";
                std::getline(std::cin, autor);
                break;
            case 3:
                std::cout << "Podaj nowe wydawnictwo: ";
                std::getline(std::cin, wydawnictwo);
                break;
            case 4:
                std::cout << "Podaj nowy rok wydania: ";
                std::cin >> rok_wydania;
                break;
            case 5:
                std::cout << "Podaj nowy ISBN: ";
                std::cin >> ISBN;
                break;
            case 6:
                std::cout << "Podaj nowy gatunek: ";
                std::cin >> gatunek;
                break;
            case 7:
                break;
            default:
                break;
        }
    } while (wybor != 7);
}

void Ksiazka::ocen() {
    int ocena;
    std::cout << "Podaj ocene od 1-5: ";
    std::cin >> ocena;
    std::cin.ignore();
    oceny.push_back(ocena);
}

void Ksiazka::gen_data() {
    static std::random_device rd;
    static std::default_random_engine dfe(rd());
    static std::uniform_int_distribution<int> numDistTytul(0, nTytuly - 1);
    static std::uniform_int_distribution<int> numDistImie(0, nImiona - 1);
    static std::uniform_int_distribution<int> numDistNazwisko(0, nNazwiska - 1);
    static std::uniform_int_distribution<int> numDistWydawnictwo(0, nWydawnictwa - 1);
    static std::uniform_int_distribution<int> numDistDzial(0, nDzialy - 1);
    static std::uniform_int_distribution<int> DistRokWydania(1900, 2024);
    static std::uniform_int_distribution<long> DistISBN(1000000000000, 9999999999999);
    static std::uniform_int_distribution<int> DistOcena(1, 5);
    static std::uniform_int_distribution<int> DistOcenaSize(0, 10);

    size_t index_tytulu1 = numDistTytul(dfe);
    size_t index_tytulu2 = numDistTytul(dfe);
    size_t index_imienia = numDistImie(dfe);
    size_t index_nazwiska = numDistNazwisko(dfe);
    size_t index_wydawnictwa = numDistWydawnictwo(dfe);
    size_t index_gatunku = numDistDzial(dfe);

    tytul = std::string(Tytuly1[index_tytulu1]) + " " + std::string(Tytuly2[index_tytulu2]);
    autor = std::string(Imiona[index_imienia]) + " " + std::string(Nazwiska[index_nazwiska]);
    wydawnictwo = Wydawnictwa[index_wydawnictwa];
    gatunek = Dzialy[index_gatunku];
    rok_wydania = DistRokWydania(dfe);
    ISBN = DistISBN(dfe);
    wypozyczona = false;
    for (int i = 0; i < DistOcenaSize(dfe); i++) {
        oceny.push_back(DistOcena(dfe));
    }
}

// Gettery
std::string Ksiazka::get_tytul() const { return tytul; };
std::string Ksiazka::get_autor() const { return autor; };
std::string Ksiazka::get_wydawnictwo() const { return wydawnictwo; };
std::string Ksiazka::get_gatunek() const { return gatunek; };
unsigned int Ksiazka::get_rok_wydania() const { return rok_wydania; };
long Ksiazka::get_ISBN() const { return ISBN; };
bool Ksiazka::get_wypozyczona() const { return wypozyczona; };
std::vector<int> Ksiazka::get_oceny() const { return oceny; };

// Settery
void Ksiazka::set_tytul(std::string tytul) { this->tytul = tytul; };
void Ksiazka::set_autor(std::string autor) { this->autor = autor; };
void Ksiazka::set_wydawnictwo(std::string wydawnictwo) { this->wydawnictwo = wydawnictwo; };
void Ksiazka::set_gatunek(std::string gatunek) { this->gatunek = gatunek; };
void Ksiazka::set_rok_wydania(unsigned int rok_wydania) { this->rok_wydania = rok_wydania; };
void Ksiazka::set_ISBN(long ISBN) { this->ISBN = ISBN; };
void Ksiazka::set_wypozyczona(bool wypozyczona) { this->wypozyczona = wypozyczona; };
void Ksiazka::set_oceny(std::vector<int> oceny) { this->oceny = oceny; };
