#include <iostream>
#include <string>
#include <vector>

size_t generujLiczbeLosowa(size_t begin, size_t end);

// struct Adres {
//     std::string ulica = "ulica";
//     unsigned int numerDomu = 0;
// };

class Adres {
    std::string ulica = "ulica";
    unsigned int numerDomu = 0;

   public:
    Adres(std::string ulica = "ulica", unsigned int numerDomu = generujLiczbeLosowa(1, 100))
        : ulica(ulica), numerDomu(numerDomu) {}
    std::string getUlica() const { return ulica; };
    void setUlica(std::string Ulica) { ulica = Ulica; };
    unsigned int getNumerDomu() const { return numerDomu; };
    void setNumerDomu(unsigned int NumerDomu) { numerDomu = NumerDomu; };
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

// struct Czytelnik {
//     std::string imie = "imie nazwisko";
//     std::string email = "sample@mail.com";
//     std::string numerTelefonu = "123321123";
//     unsigned int numerID = 0;
//     Adres adres;
//     Ksiazka* wypozyczoneKsiazki = nullptr;
//     size_t liczbaWypozyczonych = 0;
//     // std::vector<Ksiazka> wypozyczoneKsiazki;
// };

class Czytelnik {
    std::string imie = "imie nazwisko";
    std::string email = "sample@mail.com";
    std::string numerTelefonu;
    unsigned int numerID = 0;
    Adres adres;
    Ksiazka* wypozyczoneKsiazki = nullptr;
    size_t liczbaWypozyczonych = 0;

   public:
    Czytelnik(std::string imie = "imie nazwisko", std::string email = "sample@mail.com",
              std::string numerTelefonu = std::to_string(generujLiczbeLosowa(111111111, 999999999)),
              unsigned int numerID = 0, Adres adres = Adres(), Ksiazka* wypozyczoneKsiazki = nullptr,
              size_t liczbaWypozyczonych = 0)
        : imie(imie),
          email(email),
          numerTelefonu(numerTelefonu),
          numerID(numerID),
          adres(adres),
          wypozyczoneKsiazki(wypozyczoneKsiazki),
          liczbaWypozyczonych(liczbaWypozyczonych) {}

    std::string getImie() const { return imie; };
    void setImie(std::string Imie) { imie = Imie; };
    std::string getEmail() const { return email; };
    void setEmail(std::string Email) { email = Email; };
    std::string getNumerTelefonu() const { return numerTelefonu; };
    void setNumerTelefonu(std::string NumerTelefonu) { numerTelefonu = NumerTelefonu; };
    unsigned int getNumerID() const { return numerID; };
    void setNumerID(unsigned int NumerID) { numerID = NumerID; };
    std::string getUlica() const { return adres.getUlica(); };
    void setUlica(std::string ulica) { adres.setUlica(ulica); };
    unsigned int getNumerDomu() const { return adres.getNumerDomu(); };
    void setNumerDomu(unsigned int numerDomu) { adres.setNumerDomu(numerDomu); };
    Adres getAdres() const { return adres; };
    void setAdres(Adres Adres) { adres = Adres; };
    Ksiazka* getWypozyczoneKsiazki() const { return wypozyczoneKsiazki; };
    void setWypozyczoneKsiazki(Ksiazka* WypozyczoneKsiazki) { wypozyczoneKsiazki = WypozyczoneKsiazki; };
    size_t getLiczbaWypozyczonych() const { return liczbaWypozyczonych; };
    void setLiczbaWypozyczonych(size_t LiczbaWypozyczonych) { liczbaWypozyczonych = LiczbaWypozyczonych; };
};