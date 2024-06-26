#include "Biblioteka.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Czytelnik.h"
#include "Ksiazka.h"
#include "RejestratorZdarzen.h"
#include "funkcje.h"

using std::cout, std::cin, std::endl;
using namespace Books;
using namespace Readers;
using namespace Objects;

Biblioteka* Biblioteka::biblioteka = nullptr;

Biblioteka* Biblioteka::get_biblioteka() {
    if (biblioteka == nullptr) {
        biblioteka = new Biblioteka();
    }
    return biblioteka;
};

Biblioteka::Biblioteka() {
    liczba_ksiazek = 0;
    last_id = 0;
    czytelnicy = {};
    for (auto& element : usuniete_elementy) {
        element = nullptr;
    }
    liczba_usunietych = 0;
};

// lista inicjalizacyjna
Biblioteka::Biblioteka(std::vector<Ksiazka*> ksiazki, size_t liczba_ksiazek,
                       std::map<size_t, Czytelnik, CzytelnikComparator> czytelnicy, size_t last_id,
                       std::vector<std::shared_ptr<Obiekt>> usuniete_elementy, size_t liczba_usunietych)
    : ksiazki(ksiazki),
      liczba_ksiazek(liczba_ksiazek),
      czytelnicy(czytelnicy),
      last_id(last_id),
      usuniete_elementy(usuniete_elementy),
      liczba_usunietych(liczba_usunietych){};

// konstruktor kopiujący
Biblioteka::Biblioteka(const Biblioteka& right) {
    ksiazki = right.ksiazki;
    usuniete_elementy = right.usuniete_elementy;
    liczba_ksiazek = right.liczba_ksiazek;
    czytelnicy = right.czytelnicy;
    last_id = right.last_id;
    liczba_usunietych = right.liczba_usunietych;
};

// operator przypisania
Biblioteka& Biblioteka::operator=(const Biblioteka& right) {
    if (this == &right) {
        return *this;
    }
    ksiazki = right.ksiazki;
    liczba_ksiazek = right.liczba_ksiazek;
    czytelnicy = right.czytelnicy;
    last_id = right.last_id;
    usuniete_elementy = right.usuniete_elementy;
    liczba_usunietych = right.liczba_usunietych;
    return *this;
};

// konstruktor przenoszący
Biblioteka::Biblioteka(Biblioteka&& other) noexcept {
    ksiazki = std::move(other.ksiazki);
    liczba_ksiazek = std::move(other.liczba_ksiazek);
    czytelnicy = std::move(other.czytelnicy);
    last_id = std::move(other.last_id);
    usuniete_elementy = std::move(other.usuniete_elementy);
    liczba_usunietych = std::move(other.liczba_usunietych);
};

// operator przypisania przenoszącego
Biblioteka& Biblioteka::operator=(Biblioteka&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    ksiazki = std::move(other.ksiazki);
    liczba_ksiazek = std::move(other.liczba_ksiazek);
    czytelnicy = std::move(other.czytelnicy);
    last_id = std::move(other.last_id);
    usuniete_elementy = std::move(other.usuniete_elementy);
    liczba_usunietych = std::move(other.liczba_usunietych);

    return *this;
};

// destruktor
Biblioteka::~Biblioteka() {
    // for (auto ptr : usuniete_elementy) {
    //     delete ptr;
    // }
    for (auto ptr : ksiazki) {
        delete ptr;
    }
    usuniete_elementy.clear();
    ksiazki.clear();
};

// Metody

void Biblioteka::dodaj(Ksiazka* ksiazka) {
    ksiazki.push_back(ksiazka);
    liczba_ksiazek++;
};

void Biblioteka::dodaj(Czytelnik czytelnik) { czytelnicy.insert(std::make_pair(czytelnik.get_numer_ID(), czytelnik)); };

void Biblioteka::wyswietlCzytelnikow() {
    system("clear");
    cout << "\n=========================================\n";
    cout << "            Lista Czytelnikow          \n";
    cout << "=========================================\n";
    int i = 1;
    for (const auto& [id, czytelnik] : czytelnicy) {
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
    nowyCzytelnik.set_numer_ID(++last_id);  // Automatyczne przypisanie numeru ID.
    size_t pozycja = 0;
    size_t poprzednia_pozycja = 0;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.set_imie(daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.set_email(daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.set_numer_telefonu(daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
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

void Biblioteka::usunCzytelnika(size_t id) {
    for (auto* ksiazka : czytelnicy[id].get_wypozyczone_ksiazki()) {
        zwrocKsiazke(ksiazka->get_ISBN());
    }
    auto usuniety = std::make_shared<Czytelnik>(std::move(czytelnicy[id]));
    usuniete_elementy.push_back(std::move(usuniety));
    liczba_usunietych++;
    czytelnicy.erase(id);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Usunieto czytelnika");
}

void Biblioteka::usunKsiazke(size_t index) {
    zwrocKsiazke(ksiazki[index]->get_ISBN());
    auto usunieta = std::make_shared<Ksiazka>(std::move(*ksiazki[index]));
    usuniete_elementy.push_back(std::move(usunieta));
    liczba_usunietych++;
    liczba_ksiazek--;
    ksiazki.erase(ksiazki.begin() + index);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Usunieto ksiazke");
}

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
        Ksiazka* ksiazka = new Ksiazka;
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
    if (ksiazka.get_tytul() == "tytul" || czytelnik.get_imie() == "imie") {
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

void Biblioteka::zwroc() {
    system("clear");
    cout << "\n=========================================\n"
         << "           Zwracanie Ksiazki          \n"
         << "=========================================\n";
    int i = 0;
    int j = 0;
    std::vector<int> wypozyczone;
    for (const auto& ksiazka : ksiazki) {
        if (ksiazka->get_wypozyczona() == true) {
            cout << ++i << ". ";
            ksiazka->wyswietl();
            wypozyczone.push_back(j);
        }
        j++;
    }
    if (i == 0) {
        return;
    }
    cin.ignore();
    int wybor;
    cout << "Wybierz ksiazke do zwrotu: ";
    cin >> wybor;
    cin.ignore();
    if (wybor > 0 && wybor <= wypozyczone.size()) {
        int index = wypozyczone[wybor - 1];
        zwrocKsiazke(ksiazki[index]->get_ISBN());
        cout << "Ksiazka zostala zwrocona" << endl;
        ksiazki[index]->ocen();
        cout << "Wciśnij dowolny klawisz aby kontynuowac" << endl;
        cin.get();
    } else {
        cout << "Ksiazka nie jest wypozyczona" << endl;
        cout << "Wciśnij dowolny klawisz aby kontynuowac" << endl;
        cin.get();
    }
}

void Biblioteka::zwrocKsiazke(long ISBN) {
    for (auto& ksiazka : ksiazki) {
        if (ksiazka->get_ISBN() == ISBN && ksiazka->get_wypozyczona()) {
            ksiazka->set_wypozyczona(false);
            for (auto& czytelnik : czytelnicy) {
                czytelnik.second.usun(ISBN);
            }
            return;
        }
    }
}

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

void Biblioteka::wyswietlUsuniete() {
    system("clear");
    cout << "\n=========================================\n";
    cout << "            Usuniete elementy          \n";
    cout << "=========================================\n";
    for (size_t i = 0; i < liczba_usunietych; i++) {
        usuniete_elementy[i]->wyswietl();
    }
};

// void Biblioteka::wyswietlOpublikowaneKsiazkiPo(int rok) {
//     std::vector<Ksiazka*> opublikowane;
//     std::copy_if(ksiazki.begin(), ksiazki.end(), std::back_inserter(opublikowane), czyOpublikowana(rok));
//     system("clear");
//     cout << "\n=========================================\n";
//     cout << "Ksiazki opublikowane po " << rok << ": " << rok << std::endl;
//     cout << "=========================================\n";
//     for (auto& ksiazka : opublikowane) {
//         ksiazka->wyswietl();
//     }
//     cout << "Nacisnij enter aby kontynuowac... ";
//     cin.get();
// }

void Biblioteka::wyswietlOpublikowaneKsiazkiPo(int rok) {
    std::vector<Ksiazka*> opublikowane;
    std::copy_if(ksiazki.begin(), ksiazki.end(), std::back_inserter(opublikowane),
                 [rok](const Ksiazka* ksiazka) { return ksiazka->get_rok_wydania() > rok; });
    system("clear");
    cout << "\n=========================================\n";
    cout << "Ksiazki opublikowane po " << rok << std::endl;
    cout << "=========================================\n";
    for (auto& ksiazka : opublikowane) {
        ksiazka->wyswietl();
    }
    cout << "Nacisnij enter aby kontynuowac... ";
    cin.get();
}

// Gettery
std::vector<Ksiazka*> Biblioteka::get_ksiazki() const { return ksiazki; };
size_t Biblioteka::get_liczba_ksiazek() const { return liczba_ksiazek; };
std::map<size_t, Czytelnik, CzytelnikComparator> Biblioteka::get_czytelnicy() const { return czytelnicy; };
size_t Biblioteka::get_last_id() const { return last_id; };

// Settery
void Biblioteka::set_ksiazki(std::vector<Ksiazka*> ksiazki) { this->ksiazki = ksiazki; };
void Biblioteka::set_liczba_ksiazek(size_t liczba_ksiazek) { this->liczba_ksiazek = liczba_ksiazek; };
void Biblioteka::set_czytelnicy(std::map<size_t, Czytelnik, CzytelnikComparator> czytelnicy) {
    this->czytelnicy = czytelnicy;
};
void Biblioteka::set_last_id(size_t last_id) { this->last_id = last_id; };
