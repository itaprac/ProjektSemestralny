#include <iostream>
#include <string>
#include <vector>

using std::cout, std::cin, std::endl;
size_t generujLiczbeLosowa(size_t begin, size_t end);

struct Lokalizacja {
    std::string dzial;
    unsigned int numerRegalu;
};

class RejestratorZdarzen {
   private:
    static RejestratorZdarzen* rejestratorZdarzen;
    std::vector<std::string> zdarzenia;
    size_t maxLiczbaZdarzen;

    RejestratorZdarzen(size_t maxLiczba = 100) : maxLiczbaZdarzen(maxLiczba) {}

   public:
    static RejestratorZdarzen* get_rejestratorZdarzen() {
        if (rejestratorZdarzen == nullptr) {
            rejestratorZdarzen = new RejestratorZdarzen();
        }
        return rejestratorZdarzen;
    }

    static void usun_rejestratorZdarzen() {
        delete rejestratorZdarzen;
        rejestratorZdarzen = nullptr;
    }

    void dodajZdarzenie(const std::string& zdarzenie) {
        if (zdarzenia.size() >= maxLiczbaZdarzen) {
            zdarzenia.erase(zdarzenia.begin());
        }
        zdarzenia.push_back(zdarzenie);
    }

    const std::vector<std::string>& getZdarzenia() const { return zdarzenia; }
};

// struct Ksiazka {
//     std::string tytul;
//     std::string autor;
//     std::string wydawnictwo;
//     unsigned int rokWydania;
//     Lokalizacja lokalizacja;
//     bool dostepna = true;
// };

class Ksiazka {
   public:
    std::string tytul;
    std::string autor;
    std::string wydawnictwo;
    unsigned int rokWydania;
    Lokalizacja lokalizacja;
    bool dostepna = true;

    Ksiazka(std::string tytul = "tytul", std::string autor = "autor", std::string wydawnictwo = "wydawnictwo",
            unsigned int rokWydania = generujLiczbeLosowa(1900, 2021), Lokalizacja lokalizacja = Lokalizacja(),
            bool dostepna = true)
        : tytul(tytul),
          autor(autor),
          wydawnictwo(wydawnictwo),
          rokWydania(rokWydania),
          lokalizacja(lokalizacja),
          dostepna(dostepna){};

    friend std::ostream& operator<<(std::ostream& output, const Ksiazka& ksiazka) {
        output << ksiazka.tytul << " - " << ksiazka.autor << endl
               << "Wydawnictwo: " << ksiazka.wydawnictwo << endl
               << "Rok wydania: " << ksiazka.rokWydania << endl
               << "Lokalizacja: " << ksiazka.lokalizacja.dzial << " " << ksiazka.lokalizacja.numerRegalu << endl
               << "Dostepnosc: " << (ksiazka.dostepna ? "Dostepna" : "Niedostepna") << endl;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, Ksiazka& ksiazka) {
        std::getline(input, ksiazka.tytul, ',');
        std::getline(input, ksiazka.autor, ',');
        std::getline(input, ksiazka.wydawnictwo, ',');
        input >> ksiazka.rokWydania;
        input.ignore();
        std::getline(input, ksiazka.lokalizacja.dzial, ',');
        input >> ksiazka.lokalizacja.numerRegalu;
        input.ignore();
        return input;
    }

    std::string getTytul() const { return tytul; };
    void setTytul(std::string Tytul) { tytul = Tytul; };
    std::string getAutor() const { return autor; };
    void setAutor(std::string Autor) { autor = Autor; };
    std::string getWydawnictwo() const { return wydawnictwo; };
    void setWydawnictwo(std::string Wydawnictwo) { wydawnictwo = Wydawnictwo; };
    unsigned int getRokWydania() const { return rokWydania; };
    void setRokWydania(unsigned int RokWydania) { rokWydania = RokWydania; };
    Lokalizacja getLokalizacja() const { return lokalizacja; };
    void setLokalizacja(Lokalizacja Lokalizacja) { lokalizacja = Lokalizacja; };
    bool getDostepna() const { return dostepna; };
    void setDostepna(bool Dostepna) { dostepna = Dostepna; };
};

class UzytkownikBiblioteki {
   public:
    virtual void wypozyczKsiazke(Ksiazka& ksiazka) = 0;
    virtual void zwrocKsiazke(Ksiazka& ksiazka) = 0;
    virtual ~UzytkownikBiblioteki() = 0;
};

class Czytelnik : public UzytkownikBiblioteki {
    class Adres {
        std::string ulica;
        unsigned int numerDomu;
        friend class Czytelnik;

       public:
        Adres(std::string ulica = "ulica", unsigned int numerDomu = generujLiczbeLosowa(1, 100))
            : ulica(ulica), numerDomu(numerDomu){};

        // konstruktor kopjujacy
        Adres(const Adres& right) {
            ulica = right.ulica;
            numerDomu = right.numerDomu;
        }

        // operator przypisania
        Adres operator=(const Adres& right) {
            if (this != &right) {
                ulica = right.ulica;
                numerDomu = right.numerDomu;
            }
            return *this;
        }

        Adres(Adres&& other) noexcept : ulica(std::move(other.ulica)), numerDomu(other.numerDomu) {
            other.numerDomu = 0;
        }

        Adres& operator=(Adres&& other) noexcept {
            if (this != &other) {
                ulica = std::move(other.ulica);
                numerDomu = other.numerDomu;
                other.numerDomu = 0;
            }
            return *this;
        }

        std::string getUlica() const { return ulica; };
        void setUlica(std::string Ulica) { ulica = Ulica; };
        unsigned int getNumerDomu() const { return numerDomu; };
        void setNumerDomu(unsigned int NumerDomu) { numerDomu = NumerDomu; };
    };

    std::string imie;
    std::string email;
    std::string numerTelefonu;
    unsigned int numerID;
    Adres adres;
    Ksiazka* wypozyczoneKsiazki = nullptr;
    size_t liczbaWypozyczonych;
    mutable size_t licznikWyswietlen;

    void powiekszTablice() {
        Ksiazka* nowa_tablica = new Ksiazka[liczbaWypozyczonych + 1];
        for (size_t i = 0; i < liczbaWypozyczonych; i++) {
            nowa_tablica[i] = wypozyczoneKsiazki[i];
        }
        delete[] wypozyczoneKsiazki;
        wypozyczoneKsiazki = nowa_tablica;
    };

   public:
    Czytelnik(std::string imie = "imie nazwisko", std::string email = "sample@mail.com",
              std::string numerTelefonu = std::to_string(generujLiczbeLosowa(111111111, 999999999)),
              unsigned int numerID = 0, Adres adres = Adres(), Ksiazka* wypozyczoneKsiazki = nullptr,
              size_t liczbaWypozyczonych = 0, size_t licznikWyswietlen = 0)
        : imie(imie),
          email(email),
          numerTelefonu(numerTelefonu),
          numerID(numerID),
          adres(adres),
          wypozyczoneKsiazki(wypozyczoneKsiazki),
          liczbaWypozyczonych(liczbaWypozyczonych),
          licznikWyswietlen(licznikWyswietlen) {}

    // konsruktor kopiujacy
    Czytelnik(const Czytelnik& right) {
        imie = right.imie;
        email = right.email;
        numerTelefonu = right.numerTelefonu;
        numerID = right.numerID;
        adres = right.adres;
        wypozyczoneKsiazki = right.wypozyczoneKsiazki;
        liczbaWypozyczonych = right.liczbaWypozyczonych;
        licznikWyswietlen = right.licznikWyswietlen;

        wypozyczoneKsiazki = new Ksiazka[liczbaWypozyczonych];
        for (size_t i = 0; i < liczbaWypozyczonych; i++) {
            wypozyczoneKsiazki[i] = right.wypozyczoneKsiazki[i];
        }
    }

    // destruktor
    ~Czytelnik() { delete[] wypozyczoneKsiazki; }

    // operator przypisania przeciazony poniewaz mamy dynamiczna tablice wiec musimy go uzyc aby kazdy czytelnik mial
    // wlasna tablice wypozyczonych ksiazek
    Czytelnik operator=(const Czytelnik& right) {
        if (this != &right) {
            this->~Czytelnik();

            imie = right.imie;
            email = right.email;
            numerTelefonu = right.numerTelefonu;
            numerID = right.numerID;
            adres = right.adres;
            wypozyczoneKsiazki = right.wypozyczoneKsiazki;
            liczbaWypozyczonych = right.liczbaWypozyczonych;
            licznikWyswietlen = right.licznikWyswietlen;

            wypozyczoneKsiazki = new Ksiazka[liczbaWypozyczonych];
            for (size_t i = 0; i < liczbaWypozyczonych; i++) {
                wypozyczoneKsiazki[i] = right.wypozyczoneKsiazki[i];
            }
        }
        return *this;
    }

    // Konstruktor przenoszący
    Czytelnik(Czytelnik&& other) noexcept
        : imie(std::move(other.imie)),
          email(std::move(other.email)),
          numerTelefonu(std::move(other.numerTelefonu)),
          numerID(std::move(other.numerID)),
          adres(std::move(other.adres)),
          wypozyczoneKsiazki(std::move(other.wypozyczoneKsiazki)),
          liczbaWypozyczonych(other.liczbaWypozyczonych),
          licznikWyswietlen(other.licznikWyswietlen) {
        other.wypozyczoneKsiazki = nullptr;
        other.liczbaWypozyczonych = 0;
        other.licznikWyswietlen = 0;
    }

    // Operator przypisania przenoszący
    Czytelnik& operator=(Czytelnik&& other) noexcept {
        if (this != &other) {
            delete[] wypozyczoneKsiazki;
            imie = std::move(other.imie);
            email = std::move(other.email);
            numerTelefonu = std::move(other.numerTelefonu);
            numerID = std::move(other.numerID);
            adres = std::move(other.adres);
            wypozyczoneKsiazki = std::move(other.wypozyczoneKsiazki);
            liczbaWypozyczonych = other.liczbaWypozyczonych;
            licznikWyswietlen = other.licznikWyswietlen;
            other.wypozyczoneKsiazki = nullptr;
            other.liczbaWypozyczonych = 0;
            other.licznikWyswietlen = 0;
        }
        return *this;
    }

    Ksiazka& operator[](const size_t index) { return wypozyczoneKsiazki[index]; }

    const Ksiazka& operator[](const size_t index) const { return wypozyczoneKsiazki[index]; }

    // wypozycznie ksiazki (do uzupełnienia)
    // void wypozyczKsiazke(const Ksiazka& ksiazka) {
    //     powiekszTablice();
    //     wypozyczoneKsiazki[liczbaWypozyczonych] = ksiazka;
    //     liczbaWypozyczonych++;
    // }

    void wypozyczKsiazke(Ksiazka& ksiazka) override {
        powiekszTablice();
        wypozyczoneKsiazki[liczbaWypozyczonych] = ksiazka;
        liczbaWypozyczonych++;
    }

    void zwrocKsiazke(Ksiazka& ksiazka) override {
        for (size_t i = 0; i < liczbaWypozyczonych; i++) {
            if (wypozyczoneKsiazki[i].tytul == ksiazka.tytul) {
                for (size_t j = i; j < liczbaWypozyczonych - 1; j++) {
                    wypozyczoneKsiazki[j] = wypozyczoneKsiazki[j + 1];
                }
                liczbaWypozyczonych--;
                break;
            }
        }
    }

    // Funkcja wyswitlajaca dane czytelnika
    void wyswietl() const {
        cout << "\n-----------------------------------------\n"
             << "Imie i nazwisko: " << imie << endl
             << "Email: " << email << endl
             << "Numer telefonu: " << numerTelefonu << endl
             << "Numer ID: " << numerID << endl
             << "Adres: " << adres.ulica << " " << adres.numerDomu << endl
             << "Wypozyczone ksiazki: ";
        if (liczbaWypozyczonych <= 1) {
            cout << "Brak wypozyczonych ksiazek" << endl;
        } else {
            for (size_t i = 0; i < liczbaWypozyczonych; i++) {
                cout << (*this)[i].tytul << endl;
            }
        };
        licznikWyswietlen++;
    }

    int getLicznikWyswietlen() const { return licznikWyswietlen; };
    void setLicznikWyswietlen(size_t LicznikWyswietlen) { licznikWyswietlen = LicznikWyswietlen; };

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
    size_t getLiczbaWypozyczonych() const { return liczbaWypozyczonych; };
};
