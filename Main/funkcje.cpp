#include <iostream>
#include <string>
#include <vector>

#include "struktury.h"  // Dołączenie pliku nagłówkowego ze strukturami.

using std::cout, std::cin, std::endl;

// Funkcja dodająca nowego czytelnika do listy.
void dodaj(std::vector<Czytelnik>& czytelnicy, size_t& last_id) {
    std::string imie;
    std::string email;
    std::string numerTelefonu;
    unsigned int numerID = ++last_id;  // Automatyczne przypisanie numeru ID.
    Adres adres;
    cout << "Podaj imie i nazwisko: ";
    std::getline(cin, imie);
    cout << "Podaj email: ";
    std::getline(cin, email);
    cout << "Podaj numer telefonu: ";
    std::getline(cin, numerTelefonu);
    cout << "Podaj ulice: ";
    std::getline(cin, adres.ulica);
    cout << "Podaj numer domu: ";
    cin >> adres.numerDomu;
    cin.ignore();
    czytelnicy.push_back({imie, email, numerTelefonu, numerID, adres});  // Dodanie nowego czytelnika do listy.
}

// Funkcja wyświetlająca listę czytelników.
void wyswietl(std::vector<Czytelnik>& czytelnicy) {
    int i = 1;
    cout << "Lista czytelnikow:" << endl;
    for (Czytelnik& czytelnik : czytelnicy) {
        cout << ++i << ". " << czytelnik.imie << endl;
        cout << "      Email: " << czytelnik.email << endl;
        cout << "      Numer telefonu: " << czytelnik.numerTelefonu << endl;
        cout << "      Numer ID: " << czytelnik.numerID << endl;
        cout << "      Adres: " << czytelnik.adres.ulica << " " << czytelnik.adres.numerDomu << endl;
        cout << "      Wypozyczone ksiazki: ";
        for (const Ksiazka& ksiazka : czytelnik.wypozyczoneKsiazki) {
            cout << ksiazka.tytul << " - " << ksiazka.autor << ", ";
        }
        cout << endl;
    }
}

// Funkcja umożliwiająca edycję danych czytelnika.
void edytuj(std::vector<Czytelnik>& czytelnicy, size_t index) {
    cout << "1. Edytowanie imienia" << endl;
    cout << "2. Edytowanie emaila" << endl;
    cout << "3. Edytowanie numeru telefonu" << endl;
    cout << "4. Edytowanie adresu" << endl;
    int wybor;
    cout << "Wybor: ";
    cin >> wybor;
    cin.ignore();
    switch (wybor) {
        case 1:
            cout << "Imie i nazwisko: ";
            std::getline(cin, czytelnicy[index].imie);  // Aktualizacja imienia i nazwiska.
            break;
        case 2:
            cout << "Email: ";
            std::getline(cin, czytelnicy[index].email);  // Aktualizacja adresu email.
            break;
        case 3:
            cout << "Numer telefonu: ";
            cin >> czytelnicy[index].numerTelefonu;  // Aktualizacja numeru telefonu.
            cin.ignore();
            break;
        case 4:
            cout << "Ulica: ";
            std::getline(cin, czytelnicy[index].adres.ulica);  // Aktualizacja ulicy.
            cout << "Numer domu: ";
            cin >> czytelnicy[index].adres.numerDomu;  // Aktualizacja numeru domu.
            cin.ignore();
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru.
            break;
    }
}

// Funkcja usuwająca czytelnika z listy.
void usun(std::vector<Czytelnik>& czytelnicy, size_t index) { czytelnicy.erase(czytelnicy.begin() + index); }

// Funkcja dodająca nową książkę do listy.
void dodaj(std::vector<Ksiazka>& ksiazki) {
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
    ksiazki.push_back({tytul, autor, wydawnictwo, rokWydania, lokalizacja});  // Dodanie nowej książki do listy.
}

// Funkcja wyświetlająca listę książek.
void wyswietl(std::vector<Ksiazka>& ksiazki) {
    int i = 1;
    cout << "Lista ksiazek:" << endl;
    for (const Ksiazka& ksiazka : ksiazki) {
        cout << i << ". " << ksiazka.tytul << " - " << ksiazka.autor << endl;
        i++;
    }
}

// Funkcja umożliwiająca edycję danych książki.
void edytuj(std::vector<Ksiazka>& ksiazki, size_t index) {
    cout << "1. Edytowanie tytulu" << endl;
    cout << "2. Edytowanie autora" << endl;
    cout << "3. Edytowanie wydawnictwa" << endl;
    cout << "4. Edytowanie roku wydania" << endl;
    cout << "5. Edytowanie lokalizacji" << endl;
    int wybor;
    cout << "Wybor: ";
    cin >> wybor;
    cin.ignore();
    switch (wybor) {
        case 1:
            cout << "Tytul: ";
            std::getline(cin, ksiazki[index].tytul);  // Aktualizacja tytułu książki.
            break;
        case 2:
            cout << "Autor: ";
            std::getline(cin, ksiazki[index].autor);  // Aktualizacja autora książki.
            break;
        case 3:
            cout << "Wydawnictwo: ";
            std::getline(cin, ksiazki[index].wydawnictwo);  // Aktualizacja wydawnictwa.
            break;
        case 4:
            cout << "Rok wydania: ";
            cin >> ksiazki[index].rokWydania;  // Aktualizacja roku wydania.
            cin.ignore();
            break;
        case 5:
            cout << "Dzial: ";
            std::getline(cin, ksiazki[index].lokalizacja.dzial);  // Aktualizacja działu.
            cout << "Numer regalu: ";
            cin >> ksiazki[index].lokalizacja.numerRegalu;  // Aktualizacja numeru regału.
            cin.ignore();
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru.
            break;
    }
}

// Funkcja usuwająca książkę z listy.
void usun(std::vector<Ksiazka>& ksiazki, size_t index) { ksiazki.erase(ksiazki.begin() + index); }
