#include "Biblioteka.h"

#include <iostream>
#include <string>
#include <vector>

#include "Czytelnik.h"
#include "Ksiazka.h"
#include "RejestratorZdarzen.h"
#include "funkcje.h"

Biblioteka* Biblioteka::biblioteka = nullptr;
using std::cout, std::cin, std::endl;

Biblioteka* Biblioteka::get_biblioteka() {
    if (biblioteka == nullptr) {
        biblioteka = new Biblioteka();
    }
    return biblioteka;
};

Biblioteka::Biblioteka() {
    ksiazki = nullptr;
    liczba_ksiazek = 0;
    last_id = 0;
    czytelnicy = {};
};

// konstruktor kopiujący
Biblioteka::Biblioteka(const Biblioteka& right) {
    ksiazki = new Ksiazka*[right.liczba_ksiazek];
    for (size_t i = 0; i < right.liczba_ksiazek; i++) {
        ksiazki[i] = new Ksiazka(*right.ksiazki[i]);
    }
    liczba_ksiazek = right.liczba_ksiazek;
    czytelnicy = right.czytelnicy;
    last_id = right.last_id;
};

// operator przypisania
Biblioteka& Biblioteka::operator=(const Biblioteka& right) {
    if (this == &right) {
        return *this;
    }

    for (size_t i = 0; i < liczba_ksiazek; i++) {
        delete ksiazki[i];
    }
    delete[] ksiazki;

    ksiazki = new Ksiazka*[right.liczba_ksiazek];
    for (size_t i = 0; i < right.liczba_ksiazek; i++) {
        ksiazki[i] = new Ksiazka(*right.ksiazki[i]);
    }
    liczba_ksiazek = right.liczba_ksiazek;
    czytelnicy = right.czytelnicy;
    last_id = right.last_id;

    return *this;
};

// konstruktor przenoszący
Biblioteka::Biblioteka(Biblioteka&& other) noexcept {
    ksiazki = std::move(other.ksiazki);
    liczba_ksiazek = std::move(other.liczba_ksiazek);
    czytelnicy = std::move(other.czytelnicy);
    last_id = std::move(other.last_id);
};

// operator przypisania przenoszącego
Biblioteka& Biblioteka::operator=(Biblioteka&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    for (size_t i = 0; i < liczba_ksiazek; i++) {
        delete ksiazki[i];
    }
    delete[] ksiazki;

    ksiazki = std::move(other.ksiazki);
    liczba_ksiazek = std::move(other.liczba_ksiazek);
    czytelnicy = std::move(other.czytelnicy);
    last_id = std::move(other.last_id);

    return *this;
};

// destruktor
Biblioteka::~Biblioteka() {
    for (size_t i = 0; i < liczba_ksiazek; i++) {
        delete ksiazki[i];
    }
    delete[] ksiazki;
};

// Metody

void Biblioteka::dodaj(Ksiazka* ksiazka) {
    Ksiazka** nowe_ksiazki = new Ksiazka*[liczba_ksiazek + 1];
    for (size_t i = 0; i < liczba_ksiazek; i++) {
        nowe_ksiazki[i] = ksiazki[i];
    }
    nowe_ksiazki[liczba_ksiazek] = ksiazka;
    delete[] ksiazki;
    ksiazki = nowe_ksiazki;
    liczba_ksiazek++;
};

void Biblioteka::dodaj(Czytelnik czytelnik) { czytelnicy.push_back(czytelnik); };

void Biblioteka::wyswietlCzytelnikow() {
    system("clear");
    cout << "\n=========================================\n";
    cout << "            Lista Czytelnikow          \n";
    cout << "=========================================\n";
    int i = 1;
    for (auto& czytelnik : czytelnicy) {
        cout << i << ". ";
        czytelnik.wyswietl();
        i++;
    }
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wyswietlono liste czytelnikow");
};

void Biblioteka::wyswietlKsiazki() {
    system("clear");
    cout << "\n=========================================\n";
    cout << "            Lista Ksiazek          \n";
    cout << "=========================================\n";
    for (size_t i = 0; i < liczba_ksiazek; i++) {
        cout << i + 1 << ". ";
        ksiazki[i]->wyswietl();
    }
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wyswietlono liste ksiazek");
};

void Biblioteka::utworzCzytelnika() {
    system("clear");
    cout << "\n=========================================\n";
    cout << "          Dodawanie Czytelnika          \n";
    cout << "=========================================\n";

    std::string daneWejsciowe;
    bool poprawneDane;
    do {
        poprawneDane = true;
        cout << "Podaj dane czytelnika w formacie 'Imie Nazwisko, Email, Numer telefonu, Ulica, Numer domu': ";
        std::getline(cin, daneWejsciowe);
        // Sprawdzenie, czy dane wejściowe są w poprawnym formacie.
        size_t pos = 0;
        for (size_t i = 0; i < 4; i++) {
            pos = daneWejsciowe.find(", ", pos);
            if (pos == std::string::npos) {
                poprawneDane = false;
                cout << "Niepoprawny format danych" << endl;
                break;
            }
            pos = pos + 2;
        }
    } while (poprawneDane == false);

    Czytelnik nowyCzytelnik;
    nowyCzytelnik.numer_ID = ++last_id;  // Automatyczne przypisanie numeru ID.
    size_t pozycja = 0;
    size_t poprzednia_pozycja = 0;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.imie = (daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.email = (daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.numer_telefonu = (daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.set_ulica(daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    nowyCzytelnik.set_numer_domu(
        std::stoi(daneWejsciowe.substr(poprzednia_pozycja, daneWejsciowe.size() - poprzednia_pozycja)));

    Czytelnik nowy(std::move(nowyCzytelnik));
    Biblioteka::get_biblioteka()->dodaj(nowy);

    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Dodano nowego czytelnika");
};

void Biblioteka::utworzKsiazke() {
    system("clear");
    cout << "\n=========================================\n";
    cout << "          Dodawanie Ksiazki          \n";
    cout << "=========================================\n";

    Ksiazka* nowaKsiazka = new Ksiazka();
    cin >> *nowaKsiazka;
    dodaj(nowaKsiazka);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Dodano nowa ksiazke");
}

void Biblioteka::edytujCzytelnika(size_t index) {
    system("clear");
    std::cout << "\n=========================================\n"
              << "           Edytowanie Czytelnika          \n"
              << "=========================================\n"
              << "1. Edytowanie imienia\n"
              << "2. Edytowanie emaila\n"
              << "3. Edytowanie numeru telefonu\n"
              << "4. Edytowanie adresu\n"
              << "5. Powrot\n"
              << "=========================================\n";
    czytelnicy[index].edytuj();
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Edytowano czytelnika");
}

void Biblioteka::edytujKsiazke(size_t index) {
    system("clear");
    std::cout << "\n=========================================\n"
              << "           Edytowanie Ksiazki          \n"
              << "=========================================\n"
              << "1. Edytowanie tytulu\n"
              << "2. Edytowanie autora\n"
              << "3. Edytowanie wydawnictwa\n"
              << "4. Edytowanie roku wydania\n"
              << "5. Edytowanie ISBN\n"
              << "6. Edytowanie gatuunku\n"
              << "7. Powrot\n"
              << "=========================================\n";
    ksiazki[index]->edytuj();
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Edytowano ksiazke");
}

void Biblioteka::usunCzytelnika(size_t index) {
    czytelnicy.erase(czytelnicy.begin() + index);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Usunieto czytelnika");
}

void Biblioteka::usunKsiazke(size_t index) {
    usun(ksiazki[index]);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Usunieto ksiazke");
}

void Biblioteka::usun(Ksiazka* ksiazka) {
    Ksiazka** nowe_ksiazki = new Ksiazka*[liczba_ksiazek - 1];
    size_t j = 0;
    for (size_t i = 0; i < liczba_ksiazek; i++) {
        if (ksiazki[i] != ksiazka) {
            nowe_ksiazki[j] = ksiazki[i];
            j++;
        }
    }
    delete ksiazka;
    delete[] ksiazki;
    ksiazki = nowe_ksiazki;
    liczba_ksiazek--;
};

// void Biblioteka::usun(Czytelnik& czytelnik) {
//     // usun czytelnika
//     for (size_t i = 0; i < czytelnicy.size(); i++) {
//         if (czytelnicy[i] == czytelnik) {
//             czytelnicy.erase(czytelnicy.begin() + i);
//             break;
//         }
//     }
// };

Czytelnik& Biblioteka::szukajCzytelnika() {
    system("clear");
    cout << "\n=========================================\n";
    cout << "          Szukanie czytelnika          \n";
    cout << "=========================================\n";
    cout << "1. Szukanie po id" << endl << "2. Szukanie po Imieniu i Nazwsku" << endl << "Wybierz opcje wyszukiwania: ";
    size_t wybor;
    cin >> wybor;
    cin.ignore();
    size_t index;
    switch (wybor) {
        case 1:
            cout << "Wprowadz id: ";
            size_t id;
            cin >> id;
            cin.ignore();
            index = szukajCzytelnikaPoID(id);
            break;
        case 2:
            cout << "Podaj imie i nazwiska zwracaja uwage na wielkie litery: ";
            std::string imie;
            std::getline(cin, imie);
            index = szukajCzytelnikaPoImieniu(imie);
            break;
    }
    if (index == -1) {
        cout << "Nie znaleziono czytelnika" << endl;
        Czytelnik* czytelnik = new Czytelnik();
        return *czytelnik;
    }
    czytelnicy[index].wyswietl();
    cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
    cin.get();
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wyszukano czytelnika");
    return czytelnicy[index];
};

size_t Biblioteka::szukajCzytelnikaPoID(size_t id) {
    size_t left = 0;
    size_t right = czytelnicy.size() - 1;
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (czytelnicy[mid].get_numer_ID() == id) {
            return mid;
        }
        if (czytelnicy[mid].get_numer_ID() < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
};

size_t Biblioteka::szukajCzytelnikaPoImieniu(std::string imie) {
    for (size_t i = 0; i < czytelnicy.size(); i++) {
        if (czytelnicy[i].get_imie() == imie) {
            return i;
        }
    }
    return -1;
};

size_t Biblioteka::szukajKsiazkiPoTytule(std::string tytul) {
    for (size_t i = 0; i < liczba_ksiazek; i++) {
        if (ksiazki[i]->get_tytul() == tytul) {
            return i;
        }
    }
    return -1;
};

size_t Biblioteka::szukajKsiazkiPoISBN(long ISBN) {
    for (size_t i = 0; i < liczba_ksiazek; i++) {
        if (ksiazki[i]->get_ISBN() == ISBN) {
            return i;
        }
    }
    return -1;
};

Ksiazka& Biblioteka::szukajKsiazki() {
    system("clear");
    cout << "\n=========================================\n";
    cout << "          Szukanie ksiazki          \n";
    cout << "=========================================\n";
    cout << "1. Szukanie po ISBN" << endl << "2. Szukanie po Tytule" << endl << "Wybierz opcje wyszukiwania: ";
    size_t wybor;
    cin >> wybor;
    cin.ignore();
    size_t index;
    switch (wybor) {
        case 1:
            cout << "Wprowadz ISBN: ";
            size_t isbn;
            cin >> isbn;
            cin.ignore();
            index = szukajKsiazkiPoISBN(isbn);
            break;
        case 2:
            cout << "Podaj tytul ksiazki zwracajac uwage na wielkie litery: ";
            std::string tytul;
            std::getline(cin, tytul);
            index = szukajKsiazkiPoTytule(tytul);
            break;
    }
    if (index == -1) {
        cout << "Nie znaleziono ksiazki" << endl;
        Ksiazka* ksiazka = new Ksiazka();
        return *ksiazka;
    }
    ksiazki[index]->wyswietl();
    cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
    cin.get();
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wyszukano ksiazke");
    return *ksiazki[index];
};

void Biblioteka::wypozycz() {
    system("clear");
    cout << "\n=========================================\n"
         << "           Wypozyczanie Ksiazki          \n"
         << "=========================================\n";
    Ksiazka& ksiazka = szukajKsiazki();
    Czytelnik& czytelnik = szukajCzytelnika();
    if (ksiazka.tytul == "tytul" || czytelnik.imie == "imie") {
        cout << "Nie znaleziono ksiazki lub czytelnika" << endl;
        cout << "wciśnij dowolny klawisz aby kontynuowac" << endl;
        cin.get();
        return;
    }
    if (ksiazka.get_wypozyczona() == false) {
        ksiazka.set_wypozyczona(true);
        czytelnik.dodaj(ksiazka);
    } else {
        cout << "Ksiazka jest juz wypozyczona" << endl;
        cout << "Wciśnij dowolny klawisz aby kontynuowac" << endl;
        cin.get();
    }
};

// funkcja generujaca losowych czytelnikow i dodajaca ich do listy czytelnikow
void Biblioteka::stworzCzytelnikow(size_t ilosc) {
    for (size_t i = 0; i < ilosc; i++) {
        Czytelnik nowy;
        nowy.gen_data();
        nowy.set_numer_ID(++last_id);
        dodaj(nowy);
    }
};

void Biblioteka::stworzKsiazki(size_t ilosc) {
    for (size_t i = 0; i < ilosc; i++) {
        Ksiazka* nowaKsiazka = new Ksiazka();
        nowaKsiazka->gen_data();
        dodaj(nowaKsiazka);
    }
};

// Gettery
Ksiazka** Biblioteka::get_ksiazki() const { return ksiazki; };
size_t Biblioteka::get_liczba_ksiazek() const { return liczba_ksiazek; };
std::vector<Czytelnik> Biblioteka::get_czytelnicy() const { return czytelnicy; };
size_t Biblioteka::get_last_id() const { return last_id; };

// Settery
void Biblioteka::set_ksiazki(Ksiazka** ksiazki) { this->ksiazki = ksiazki; };
void Biblioteka::set_liczba_ksiazek(size_t liczba_ksiazek) { this->liczba_ksiazek = liczba_ksiazek; };
void Biblioteka::set_czytelnicy(std::vector<Czytelnik> czytelnicy) { this->czytelnicy = czytelnicy; };
void Biblioteka::set_last_id(size_t last_id) { this->last_id = last_id; };