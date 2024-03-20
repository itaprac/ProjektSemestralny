#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "dane.h"       // Dołączenie pliku nagłówkowego z danymi
#include "struktury.h"  // Dołączenie pliku nagłówkowego ze strukturami.

void gen_data(Czytelnik* czytelnik);

void dodaj(std::vector<Czytelnik>& czytelnicy, size_t& last_id);

void wyswietl(std::vector<Czytelnik>& czytelnicy);

void edytuj(std::vector<Czytelnik>& czytelnicy, size_t index);

void usun(std::vector<Czytelnik>& czytelnicy, size_t index);

void dodaj(Ksiazka**& ksiazki, size_t& liczba_ksiazek);

void wyswietl(Ksiazka**& ksiazki, size_t& liczba_ksiazek);

void edytuj(Ksiazka**& ksiazki, size_t index);

void usun(Ksiazka**& ksiazki, size_t& liczba_ksiazek, size_t index);

void stworz(std::vector<Czytelnik>& czytelnicy, size_t& last_id, size_t rozmiar);

void stworz(Ksiazka*& ksiazka);

void stworz(Ksiazka**& ksiazki, size_t rozmiar, size_t& liczba_ksiazek);

void usun(Ksiazka**& ksiazki, size_t& liczba_ksiazek);

using std::cout, std::cin, std::endl;

// Funkcja pokazujaca menu glowne
void menuGlowne() {
    system("clear");
    cout << "\n========================================\n"
         << "              Menu Glowne\n"
         << "========================================\n"
         << "1. Zarzadanie czytelnikami\n"
         << "2. Zarzadanie ksiazkami\n"
         << "3. Wyjscie\n"
         << "========================================\n"
         << "Wybierz opcje: ";
}

// Funkcja pokazujaca menu zarzadania czytelnikami
void menuCzytelnikow(std::vector<Czytelnik>& czytelnicy, size_t& last_id) {
    int wybor;
    do {
        system("clear");
        cout << "\n=========================================\n"
             << "          Zarzadanie Czytelnikami       \n"
             << "=========================================\n"
             << "1. Dodaj czytelnika\n"
             << "2. Wyswietl czytelnikow\n"
             << "3. Edytuj czytelnika\n"
             << "4. Usun czytelnika\n"
             << "5. Generuj czytelnikow\n"
             << "6. Powrot\n"
             << "=========================================\n"
             << "Wybierz opcje: ";
        cin >> wybor;
        cin.ignore();
        switch (wybor) {
            case 1:
                // Dodaj nowego Czytelnika
                dodaj(czytelnicy, last_id);
                break;
            case 2:
                // Wyświetl listę  Czytelnikow
                wyswietl(czytelnicy);
                cout << "Naciśnij Enter, aby kontynuować...";
                cin.get();  // Oczekiwanie na naciśnięcie klawisza Enter
                break;
            case 3:
                // Edytuj Czytelnika
                wyswietl(czytelnicy);
                cout << "Wybierz, którego czytelnika chcesz edytować: ";
                size_t index;
                cin >> index;
                cin.ignore();
                edytuj(czytelnicy, index - 1);
                break;
            case 4:
                // Usuń Czytelnika
                wyswietl(czytelnicy);
                cout << "Wybierz, którego czytelnika chcesz usunąć: ";
                size_t index2;
                cin >> index2;
                cin.ignore();
                usun(czytelnicy, index2 - 1);
                break;
            case 5:
                cout << "Ile czytelnikow chcesz wygenerowac: ";
                size_t ilosc;
                cin >> ilosc;
                cin.ignore();
                stworz(czytelnicy, last_id, ilosc);
                break;
            case 6:
                break;
            default:
                // cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru
                break;
        }
    } while (wybor != 6);
}

// Funkcja pokazujaca menu zarzadania ksiazkami
void menuKsiazek(Ksiazka**& ksiazki, size_t& liczba_ksiazek) {
    int wybor;
    do {
        system("clear");
        cout << "\n=========================================\n"
             << "          Zarzadanie Ksiazkami       \n"
             << "=========================================\n"
             << "1. Dodaj ksiazke\n"
             << "2. Wsywietl ksiazki\n"
             << "3. Edytuj ksiazke\n"
             << "4. Usun ksiazke\n"
             << "5. Stworz Baze Ksiazek\n"
             << "6. Powrot\n"
             << "=========================================\n"
             << "Wybierz opcje: ";
        cin >> wybor;
        cin.ignore();
        switch (wybor) {
            case 1:
                // Dodaj nową Książkę
                dodaj(ksiazki, liczba_ksiazek);
                break;
            case 2:
                // Wyświetl listę obiektów Książka
                wyswietl(ksiazki, liczba_ksiazek);
                cout << "Naciśnij Enter, aby kontynuować...";
                cin.get();  // Oczekiwanie na naciśnięcie klawisza Enter
                break;
            case 3:
                // Edytuj Książkę
                wyswietl(ksiazki, liczba_ksiazek);
                cout << "Wybierz, którą książkę chcesz edytować: ";
                size_t index1;
                cin >> index1;
                cin.ignore();
                edytuj(ksiazki, index1 - 1);
                break;
            case 4:
                // Usuń Książkę
                wyswietl(ksiazki, liczba_ksiazek);
                cout << "Wybierz, którą książkę chcesz usunąć: ";
                size_t index2;
                cin >> index2;
                cin.ignore();
                usun(ksiazki, liczba_ksiazek, index2 - 1);
                break;
            case 5:
                // Stworz baze ksiazek
                cout << "Ile ksiazek chcesz wygenerowac: ";
                size_t ilosc;
                cin >> ilosc;
                cin.ignore();
                stworz(ksiazki, ilosc, liczba_ksiazek);
                break;
            case 6:
                break;
            default:
                // cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru
                break;
        }
    } while (wybor != 6);
}

// Funkcja dodająca nowego czytelnika do listy.
void dodaj(std::vector<Czytelnik>& czytelnicy, size_t& last_id) {
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
    nowyCzytelnik.setNumerID(++last_id);  // Automatyczne przypisanie numeru ID.
    size_t pozycja = 0;
    size_t poprzednia_pozycja = 0;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.setImie(daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.setEmail(daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.setNumerTelefonu(daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    pozycja = daneWejsciowe.find(", ", poprzednia_pozycja);
    nowyCzytelnik.setUlica(daneWejsciowe.substr(poprzednia_pozycja, pozycja - poprzednia_pozycja));
    poprzednia_pozycja = pozycja + 2;
    nowyCzytelnik.setNumerDomu(
        std::stoi(daneWejsciowe.substr(poprzednia_pozycja, daneWejsciowe.size() - poprzednia_pozycja)));
    czytelnicy.push_back(nowyCzytelnik);  // Dodanie nowego czytelnika do listy.
    // std::string imie;
    // std::string email;
    // std::string numerTelefonu;
    // unsigned int numerID = ++last_id;  // Automatyczne przypisanie numeru ID.
    // Adres adres;
    // cout << "Podaj imie i nazwisko: ";
    // std::getline(cin, imie);
    // cout << "Podaj email: ";
    // std::getline(cin, email);
    // cout << "Podaj numer telefonu: ";
    // std::getline(cin, numerTelefonu);
    // cout << "Podaj ulice: ";
    // std::getline(cin, adres.ulica);
    // cout << "Podaj numer domu: ";
    // cin >> adres.numerDomu;
    // cin.ignore();
    // czytelnicy.push_back({imie, email, numerTelefonu, numerID, adres});  // Dodanie nowego czytelnika do listy.
}

// Funkcja wyświetlająca listę czytelników.
void wyswietl(std::vector<Czytelnik>& czytelnicy) {
    using std::cout;
    system("clear");
    cout << "\n=========================================\n";
    cout << "            Lista Czytelnikow          \n";
    cout << "=========================================\n";
    int i = 1;
    for (const Czytelnik& czytelnik : czytelnicy) {
        cout << i++ << ". " << czytelnik.getImie() << endl
             << "   Email: " << czytelnik.getEmail() << endl
             << "   Numer telefonu: " << czytelnik.getNumerTelefonu() << endl
             << "   Numer ID: " << czytelnik.getNumerID() << endl
             << "   Adres: " << czytelnik.getUlica() << " " << czytelnik.getNumerDomu() << endl
             << "   Wypozyczone ksiazki: ";
        if (czytelnik.getWypozyczoneKsiazki() ==
            nullptr) {  // Sprawdzenie, czy wektor wypozyczonych ksiazek jest pusty.
            cout << "Brak";
        } else {
            for (size_t i = 0; i < czytelnik.getLiczbaWypozyczonych(); i++) {
                cout << czytelnik.getWypozyczoneKsiazki()[i].tytul << " - "
                     << czytelnik.getWypozyczoneKsiazki()[i].autor << ", ";
            }
        }
        cout << "\n-----------------------------------------\n";
    }
    cout << "=========================================\n";
}

// Funkcja umożliwiająca edycję danych czytelnika.
void edytuj(std::vector<Czytelnik>& czytelnicy, size_t index) {
    system("clear");
    cout << "\n=========================================\n"
         << "           Edytowanie Czytelnika          \n"
         << "=========================================\n"
         << "1. Edytowanie imienia\n"
         << "2. Edytowanie emaila\n"
         << "3. Edytowanie numeru telefonu\n"
         << "4. Edytowanie adresu\n"
         << "5. Powrot\n"
         << "=========================================\n";
    int wybor;
    do {
        cout << "Wybor: ";
        cin >> wybor;
        cin.ignore();
        switch (wybor) {
            case 1: {
                cout << "Imie i nazwisko: ";
                std::string imie;
                std::getline(cin, imie);  // Aktualizacja imienia i nazwiska.
                czytelnicy[index].setImie(imie);
                break;
            }
            case 2: {
                cout << "Email: ";
                std::string email;
                std::getline(cin, email);  // Aktualizacja adresu email.
                czytelnicy[index].setEmail(email);
                break;
            }
            case 3: {
                cout << "Numer telefonu: ";
                std::string numerTelefonu;
                std::getline(cin, numerTelefonu);  // Aktualizacja numeru telefonu.
                czytelnicy[index].setNumerTelefonu(numerTelefonu);
                break;
            }
            case 4: {
                cout << "Ulica: ";
                std::string ulica;
                unsigned int numerDomu;
                std::getline(cin, ulica);  // Aktualizacja ulicy.
                cout << "Numer domu: ";
                cin >> numerDomu;  // Aktualizacja numeru domu.
                cin.ignore();
                czytelnicy[index].setUlica(ulica);
                czytelnicy[index].setNumerDomu(numerDomu);
                break;
            }
            default:
                cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru.
                break;
        }
        cout << "-----------------------------------------\n";
    } while (wybor != 5);
}

// Funkcja usuwająca czytelnika z listy.
void usun(std::vector<Czytelnik>& czytelnicy, size_t index) { czytelnicy.erase(czytelnicy.begin() + index); }

// Funkcja dodająca nową książkę do listy.
void dodaj(Ksiazka**& ksiazki, size_t& liczba_ksiazek) {
    system("clear");
    cout << "\n=========================================\n";
    cout << "          Dodawanie Ksiazki          \n";
    cout << "=========================================\n";
    std::string tytul;
    std::string autor;
    std::string wydawnictwo;
    unsigned int rokWydania;
    Lokalizacja lokalizacja;
    cout << "Podaj tytul: ";
    std::getline(cin, tytul);
    cout << "Podaj autora: ";
    std::getline(cin, autor);
    cout << "Podaj wydawnictwo: ";
    std::getline(cin, wydawnictwo);
    cout << "Podaj rok wydania: ";
    cin >> rokWydania;
    cin.ignore();
    cout << "Podaj dzial: ";
    std::getline(cin, lokalizacja.dzial);
    cout << "Podaj numer regalu: ";
    cin >> lokalizacja.numerRegalu;
    cin.ignore();

    Ksiazka** temp = new Ksiazka*[liczba_ksiazek + 1];
    for (size_t i = 0; i < liczba_ksiazek; i++) {
        temp[i] = ksiazki[i];
    }
    temp[liczba_ksiazek] = new Ksiazka{tytul, autor, wydawnictwo, rokWydania, lokalizacja};
    delete[] ksiazki;
    ksiazki = temp;
    liczba_ksiazek++;
}

// Funkcja wyświetlająca listę książek.
void wyswietl(Ksiazka**& ksiazki, size_t& liczba_ksiazek) {
    system("clear");
    cout << "\n=========================================\n";
    cout << "            Lista Ksiazek          \n";
    cout << "=========================================\n";

    for (size_t i = 0; i < liczba_ksiazek; i++) {
        cout << i + 1 << ". " << ksiazki[i]->tytul << " - " << ksiazki[i]->autor << endl;
        cout << "   Wydawnictwo: " << ksiazki[i]->wydawnictwo << endl
             << "   Rok wydania: " << ksiazki[i]->rokWydania << endl
             << "   Lokalizacja: " << ksiazki[i]->lokalizacja.dzial << " " << ksiazki[i]->lokalizacja.numerRegalu
             << endl
             << "   Dostepnosc: " << (ksiazki[i]->dostepna ? "Dostepna" : "Niedostepna") << endl;
        cout << "-----------------------------------------\n";
    }
    cout << "=========================================\n";
}

// Funkcja umożliwiająca edycję danych książki.
void edytuj(Ksiazka**& ksiazki, size_t index) {
    system("clear");
    cout << "\n=========================================\n"
         << "           Edytowanie Ksiazki          \n"
         << "=========================================\n"
         << "1. Edytowanie tytulu\n"
         << "2. Edytowanie autora\n"
         << "3. Edytowanie wydawnictwa\n"
         << "4. Edytowanie roku wydania\n"
         << "5. Edytowanie lokalizacji\n"
         << "6. Powrot\n"
         << "=========================================\n";
    int wybor;
    do {
        cout << "Wybor: ";
        cin >> wybor;
        cin.ignore();
        switch (wybor) {
            case 1:
                cout << "Tytul: ";
                std::getline(cin, ksiazki[index]->tytul);  // Aktualizacja tytułu książki.
                break;
            case 2:
                cout << "Autor: ";
                std::getline(cin, ksiazki[index]->autor);  // Aktualizacja autora książki.
                break;
            case 3:
                cout << "Wydawnictwo: ";
                std::getline(cin, ksiazki[index]->wydawnictwo);  // Aktualizacja wydawnictwa.
                break;
            case 4:
                cout << "Rok wydania: ";
                cin >> ksiazki[index]->rokWydania;  // Aktualizacja roku wydania.
                cin.ignore();
                break;
            case 5:
                cout << "Dzial: ";
                std::getline(cin, ksiazki[index]->lokalizacja.dzial);  // Aktualizacja działu.
                cout << "Numer regalu: ";
                cin >> ksiazki[index]->lokalizacja.numerRegalu;  // Aktualizacja numeru regału.
                cin.ignore();
                break;
            default:
                cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru.
                break;
        }
        cout << "-----------------------------------------\n";
    } while (wybor != 6);
}

// Funkcja usuwająca książkę z listy.
void usun(Ksiazka**& ksiazki, size_t& liczba_ksiazek, size_t index) {
    Ksiazka** temp = new Ksiazka*[liczba_ksiazek - 1];
    for (size_t i = 0; i < index; i++) {
        temp[i] = ksiazki[i];
    }
    for (size_t i = index; i < liczba_ksiazek - 1; i++) {
        temp[i] = ksiazki[i + 1];
    };
    delete[] ksiazki;
    ksiazki = temp;
    liczba_ksiazek--;
}

// Funkcja generujaca dane dla czytelnika
void gen_data(Czytelnik& czytelnik) {
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
    std::string_view imie = Imiona[index_imienia];
    std::string_view nazwisko = Nazwiska[index_nazwiska];
    std::string_view ulica = Ulice[index_ulicy];
    std::string_view email = Emaile[index_emaila];

    czytelnik.setImie(std::string(imie) + " " + std::string(nazwisko));
    Adres adres;
    adres.setNumerDomu(DistNumerDomu(dfe));
    adres.setUlica(std::string(ulica));
    czytelnik.setAdres(adres);
    std::string imieMale = std::string(imie);
    imieMale[0] = std::tolower(imieMale[0]);
    std::string nazwiskoMale = std::string(nazwisko);
    nazwiskoMale[0] = std::tolower(nazwiskoMale[0]);
    czytelnik.setEmail(std::string(imieMale) + '.' + std::string(nazwiskoMale) + std::string(email));
    czytelnik.setNumerTelefonu(std::to_string(DistNumerTelefonu(dfe)));
};

// funkcja ktora generuje czytelnikow i dodaje ich do vectora
void stworz(std::vector<Czytelnik>& czytelnicy, size_t& last_id, size_t rozmiar) {
    for (size_t i = 0; i < rozmiar; i++) {
        Czytelnik nowy;
        gen_data(nowy);
        nowy.setNumerID(++last_id);
        czytelnicy.push_back(nowy);
    }
}

size_t ostatni_regal = 1;
// funkcja generujaca dane dla ksiazki
void gen_data(Ksiazka* ksiazka) {
    static std::random_device rd;
    static std::default_random_engine dfe(rd());
    static std::uniform_int_distribution<int> numDistTytul(0, nTytuly - 1);
    static std::uniform_int_distribution<int> numDistImie(0, nImiona - 1);
    static std::uniform_int_distribution<int> numDistNazwisko(0, nNazwiska - 1);
    static std::uniform_int_distribution<int> numDistWydawnictwo(0, nWydawnictwa - 1);
    static std::uniform_int_distribution<int> numDistDzial(0, nDzialy - 1);
    static std::uniform_int_distribution<int> DistRokWydania(1900, 2024);

    size_t index_tytulu1 = numDistTytul(dfe);
    size_t index_tytulu2 = numDistTytul(dfe);
    size_t index_imienia = numDistImie(dfe);
    size_t index_nazwiska = numDistNazwisko(dfe);
    size_t index_wydawnictwa = numDistWydawnictwo(dfe);
    size_t index_dzialu = numDistDzial(dfe);

    ksiazka->tytul = std::string(Tytuly1[index_tytulu1]) + " " + std::string(Tytuly2[index_tytulu2]);
    ksiazka->autor = std::string(Imiona[index_imienia]) + " " + std::string(Nazwiska[index_nazwiska]);
    ksiazka->wydawnictwo = Wydawnictwa[index_wydawnictwa];
    ksiazka->rokWydania = DistRokWydania(dfe);
    ksiazka->lokalizacja.dzial = Dzialy[index_dzialu];
    ksiazka->lokalizacja.numerRegalu = ostatni_regal++;
}

// funkcja ktora tworzy losowa ksiazke
void stworz(Ksiazka*& ksiazka) {
    ksiazka = new Ksiazka;
    gen_data(ksiazka);
}

// funkcja ktora tworzy baze ksiazek i dodaje je do tablicy
void stworz(Ksiazka**& ksiazki, size_t rozmiar, size_t& liczba_ksiazek) {
    if (ksiazki != nullptr) {
        usun(ksiazki, liczba_ksiazek);
    }
    ksiazki = new Ksiazka*[rozmiar];
    for (size_t i = 0; i < rozmiar; i++) {
        stworz(ksiazki[i]);
        liczba_ksiazek++;
    }
}

// funckcja do usuwania tablicy ksiazek i czyszczenia pamieci
void usun(Ksiazka**& ksiazki, size_t& liczba_ksiazek) {
    for (size_t i = 0; i < liczba_ksiazek; i++) {
        delete ksiazki[i];
    }
    delete[] ksiazki;
    ksiazki = nullptr;
    liczba_ksiazek = 0;
    ostatni_regal = 1;
}

size_t generujLiczbeLosowa(size_t begin, size_t end) {
    static std::random_device seed;
    static std::mt19937 engine(seed());
    static std::uniform_int_distribution<size_t> uniformDist(begin, end);
    return uniformDist(engine);
}