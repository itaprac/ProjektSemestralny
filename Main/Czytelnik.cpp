#include "Czytelnik.h"

#include <iostream>
#include <string>
#include <vector>

#include "Ksiazka.h"
#include "funkcje.h"

// konstruktor domyślny
Czytelnik::Czytelnik() {
    imie = "imie";
    email = "email";
    numer_telefonu = numer_telefonu = std::to_string(generujLiczbeLosowa(111111111, 999999999));
    numer_ID = generujLiczbeLosowa(0, 999);
    adres = Adres();
    wypozyczone_ksiazki = nullptr;
    liczba_wypozyczonych_ksiazek = 0;
    licznik_wyswietlen = 0;
};

// lista inicjalizacyjna

Czytelnik::Czytelnik(std::string imie, std::string email, std::string numer_telefonu, unsigned int numer_ID,
                     Adres adres)
    : imie(imie),
      email(email),
      numer_telefonu(numer_telefonu),
      numer_ID(numer_ID),
      adres(adres),
      wypozyczone_ksiazki(nullptr),
      liczba_wypozyczonych_ksiazek(0),
      licznik_wyswietlen(0){};

// konstruktor kopiujący ksiazki jest tablica jednowymiarowa
Czytelnik::Czytelnik(const Czytelnik& right)
    : imie(right.imie),
      email(right.email),
      numer_telefonu(right.numer_telefonu),
      numer_ID(right.numer_ID),
      adres(right.adres),
      liczba_wypozyczonych_ksiazek(right.liczba_wypozyczonych_ksiazek),
      licznik_wyswietlen(right.licznik_wyswietlen) {
    wypozyczone_ksiazki = new Ksiazka[right.liczba_wypozyczonych_ksiazek];
    for (size_t i = 0; i < right.liczba_wypozyczonych_ksiazek; i++) {
        wypozyczone_ksiazki[i] = (right.wypozyczone_ksiazki[i]);
    }
};

// operator przypisania
Czytelnik& Czytelnik::operator=(const Czytelnik& right) {
    if (this == &right) {
        return *this;
    }

    imie = right.imie;
    email = right.email;
    numer_telefonu = right.numer_telefonu;
    numer_ID = right.numer_ID;
    adres = right.adres;
    delete[] wypozyczone_ksiazki;
    wypozyczone_ksiazki = new Ksiazka[right.liczba_wypozyczonych_ksiazek];
    for (size_t i = 0; i < right.liczba_wypozyczonych_ksiazek; i++) {
        wypozyczone_ksiazki[i] = (right.wypozyczone_ksiazki[i]);
    }
    liczba_wypozyczonych_ksiazek = right.liczba_wypozyczonych_ksiazek;
    licznik_wyswietlen = right.licznik_wyswietlen;

    return *this;
};

// operator ==
bool Czytelnik::operator==(const Czytelnik& right) const {
    return imie == right.imie && email == right.email && numer_telefonu == right.numer_telefonu &&
           numer_ID == right.numer_ID && adres == right.adres;
};

// konstruktor przenoszący
Czytelnik::Czytelnik(Czytelnik&& other) noexcept
    : imie(std::move(other.imie)),
      email(std::move(other.email)),
      numer_telefonu(std::move(other.numer_telefonu)),
      numer_ID(std::move(other.numer_ID)),
      adres(std::move(other.adres)),
      wypozyczone_ksiazki(std::move(other.wypozyczone_ksiazki)),
      liczba_wypozyczonych_ksiazek(std::move(other.liczba_wypozyczonych_ksiazek)),
      licznik_wyswietlen(std::move(other.licznik_wyswietlen)) {
    other.wypozyczone_ksiazki = nullptr;
};

// operator przypisania przenoszącego
Czytelnik& Czytelnik::operator=(Czytelnik&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    imie = std::move(other.imie);
    email = std::move(other.email);
    numer_telefonu = std::move(other.numer_telefonu);
    numer_ID = std::move(other.numer_ID);
    adres = std::move(other.adres);
    delete[] wypozyczone_ksiazki;
    wypozyczone_ksiazki = std::move(other.wypozyczone_ksiazki);
    liczba_wypozyczonych_ksiazek = std::move(other.liczba_wypozyczonych_ksiazek);
    licznik_wyswietlen = std::move(other.licznik_wyswietlen);

    return *this;
};

// operator <<
std::ostream& operator<<(std::ostream& output, const Czytelnik& czytelnik) {
    output << "Imie: " << czytelnik.imie << std::endl;
    output << "Email: " << czytelnik.email << std::endl;
    output << "Numer telefonu: " << czytelnik.numer_telefonu << std::endl;
    output << "Numer ID: " << czytelnik.numer_ID << std::endl;
    output << "Adres: " << czytelnik.adres << std::endl;
    output << "Liczba wypozyczonych ksiazek: " << czytelnik.liczba_wypozyczonych_ksiazek << std::endl;
    output << "Wypozyczone ksiazki: " << std::endl;
    if (czytelnik.liczba_wypozyczonych_ksiazek == 0) {
        output << "Brak wypozyczonych ksiazek" << std::endl;
    } else {
        for (size_t i = 0; i < czytelnik.liczba_wypozyczonych_ksiazek; i++) {
            output << czytelnik[i] << std::endl;
        }
    }
    output << "Licznik wyswietlen: " << czytelnik.licznik_wyswietlen << std::endl;

    return output;
};

// operator >>
std::istream& operator>>(std::istream& input, Czytelnik& czytelnik) {
    std::cout << "Podaj imie: ";
    std::getline(input, czytelnik.imie);
    std::cout << "Podaj email: ";
    std::getline(input, czytelnik.email);
    std::cout << "Podaj numer telefonu: ";
    std::getline(input, czytelnik.numer_telefonu);
    std::cout << "Podaj numer ID: ";
    input >> czytelnik.numer_ID;
    std::cout << "Podaj adres: ";
    input.ignore();
    input >> czytelnik.adres;

    return input;
};

// destruktor
Czytelnik::~Czytelnik() {
    if (wypozyczone_ksiazki != nullptr) {
        delete[] wypozyczone_ksiazki;
        wypozyczone_ksiazki = nullptr;
    }
}

Czytelnik::Adres::~Adres() {}

Ksiazka& Czytelnik::operator[](size_t index) { return wypozyczone_ksiazki[index]; };

const Ksiazka& Czytelnik::operator[](size_t index) const { return wypozyczone_ksiazki[index]; };

// Metody

void Czytelnik::wyswietl() const {
    std::cout << *this;
    licznik_wyswietlen++;
    std::cout << "-----------------------------------------\n";
};

void Czytelnik::edytuj() {
    int wybor;
    do {
        std::cout << "Wybor: ";
        std::cin >> wybor;
        std::cin.ignore();
        switch (wybor) {
            case 1: {
                std::cout << "Podaj imie: ";
                std::getline(std::cin, imie);
                break;
            }
            case 2: {
                std::cout << "Podaj email: ";
                std::getline(std::cin, email);
                break;
            }
            case 3: {
                std::cout << "Podaj numer telefonu: ";
                std::getline(std::cin, numer_telefonu);
                break;
            }
            case 4: {
                std::cin >> adres;
                break;
            }
            case 5:
                break;
            default:
                std::cout << "Nie ma takiej opcji!\n";
                break;
        }
    } while (wybor != 5);
};

void Czytelnik::powiekszTablice() {
    Ksiazka* nowa_tablica = new Ksiazka[liczba_wypozyczonych_ksiazek + 1];
    for (size_t i = 0; i < liczba_wypozyczonych_ksiazek; i++) {
        nowa_tablica[i] = wypozyczone_ksiazki[i];
    }
    delete[] wypozyczone_ksiazki;
    wypozyczone_ksiazki = nowa_tablica;
};

void Czytelnik::dodaj(Ksiazka& ksiazka) {
    this->powiekszTablice();
    this->wypozyczone_ksiazki[this->liczba_wypozyczonych_ksiazek] = ksiazka;
    this->liczba_wypozyczonych_ksiazek++;
};

void Czytelnik::gen_data() {
    static std::random_device rd;
    static std::default_random_engine dfe(rd());
    static std::uniform_int_distribution<int> numDistImie(0, nImiona - 1);
    static std::uniform_int_distribution<int> numDistNazwisko(0, nNazwiska - 1);
    static std::uniform_int_distribution<int> numDistUlica(0, nUlice - 1);
    static std::uniform_int_distribution<int> numDistEmail(0, nEmaile - 1);
    static std::uniform_int_distribution<unsigned long> DistNumerTelefonu(111111111, 999999999);
    static std::uniform_int_distribution<int> DistNumerDomu(1, 99);

    size_t index_imienia = numDistImie(dfe);
    size_t index_nazwiska = numDistNazwisko(dfe);
    size_t index_ulicy = numDistUlica(dfe);
    size_t index_emaila = numDistEmail(dfe);
    std::string_view Imie = Imiona[index_imienia];
    std::string_view Nazwisko = Nazwiska[index_nazwiska];
    std::string_view Ulica = Ulice[index_ulicy];
    std::string_view Email = Emaile[index_emaila];

    imie = (std::string(Imie) + " " + std::string(Nazwisko));
    set_numer_domu(DistNumerDomu(dfe));
    set_ulica(std::string(Ulica));
    std::string imieMale = std::string(Imie);
    imieMale[0] = std::tolower(imieMale[0]);
    std::string nazwiskoMale = std::string(Nazwisko);
    nazwiskoMale[0] = std::tolower(nazwiskoMale[0]);
    email = (std::string(imieMale) + '.' + std::string(nazwiskoMale) + std::string(Email));
    numer_telefonu = (std::to_string(DistNumerTelefonu(dfe)));
    wypozyczone_ksiazki = nullptr;
    liczba_wypozyczonych_ksiazek = 0;
    licznik_wyswietlen = 0;
};

// Gettery
std::string Czytelnik::get_imie() const { return imie; };
std::string Czytelnik::get_email() const { return email; };
std::string Czytelnik::get_numer_telefonu() const { return numer_telefonu; };
unsigned int Czytelnik::get_numer_ID() const { return numer_ID; };
Czytelnik::Adres Czytelnik::get_adres() const { return adres; };
std::string Czytelnik::get_ulica() const { return adres.get_ulica(); };
unsigned int Czytelnik::get_numer_domu() const { return adres.get_numer_domu(); };
Ksiazka* Czytelnik::get_wypozyczone_ksiazki() const { return wypozyczone_ksiazki; };
size_t Czytelnik::get_liczba_wypozyczonych_ksiazek() const { return liczba_wypozyczonych_ksiazek; };

// Settery
void Czytelnik::set_imie(std::string imie) { this->imie = imie; };
void Czytelnik::set_email(std::string email) { this->email = email; };
void Czytelnik::set_numer_telefonu(std::string numer_telefonu) { this->numer_telefonu = numer_telefonu; };
void Czytelnik::set_numer_ID(unsigned int numer_ID) { this->numer_ID = numer_ID; };
void Czytelnik::set_adres(Adres adres) { this->adres = adres; };
void Czytelnik::set_ulica(std::string ulica) { adres.set_ulica(ulica); };
void Czytelnik::set_numer_domu(unsigned int numer_domu) { adres.set_numer_domu(numer_domu); };
void Czytelnik::set_wypozyczone_ksiazki(Ksiazka* wypozyczone_ksiazki) {
    this->wypozyczone_ksiazki = wypozyczone_ksiazki;
};
void Czytelnik::set_liczba_wypozyczonych_ksiazek(size_t liczba_wypozyczonych_ksiazek) {
    this->liczba_wypozyczonych_ksiazek = liczba_wypozyczonych_ksiazek;
};
