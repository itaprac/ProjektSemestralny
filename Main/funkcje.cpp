#include "funkcje.h"

#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Biblioteka.h"
#include "RejestratorZdarzen.h"
#include "dane.h"

using std::cout, std::cin, std::endl;

void menuGlowne() {
    int wybor;
    do {
        system("clear");
        cout << "\n========================================\n"
             << "              Menu Glowne\n"
             << "========================================\n"
             << "1. Zarzadanie czytelnikami\n"
             << "2. Zarzadanie ksiazkami\n"
             << "3. Wypożyczanie książek\n"
             << "4. Wyjscie\n"
             << "========================================\n"
             << "Wybierz opcje: ";
        RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wyswietlono menu glowne");
        cin >> wybor;
        cin.ignore();  // Czyszczenie entera
        switch (wybor) {
            case 1:
                // zardzadanie czytelnikami
                menuCzytelnikow();
                break;
            case 2:
                // zarzadanie ksiazkami
                menuKsiazek();
                break;
            case 3:
                Biblioteka::get_biblioteka()->wypozycz();
                break;
            case 4:
                cout << "Wychodzenie z programu...\n";
                // usun biblioteke
                Biblioteka::get_biblioteka()->~Biblioteka();
                break;
            default:
                // cout << "Nieprawidlowy wybor" << endl;
                break;
        }
    } while (wybor != 4);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Program zakonczony");
}

// menu czytelnikow ktore przyjmuje biblioteke jako argument
void menuCzytelnikow() {
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
             << "6. Szukaj czytelnika\n"
             << "7. Powrot\n"
             << "=========================================\n"
             << "Wybierz opcje: ";
        RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wyswietlono menu zarzadzania czytelnikami");
        cin >> wybor;
        cin.ignore();
        RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wybrano opcje " + std::to_string(wybor));
        switch (wybor) {
            case 1:
                // Dodaj nowego Czytelnika
                Biblioteka::get_biblioteka()->utworzCzytelnika();
                break;
            case 2:
                // Wyświetl listę  Czytelnikow
                Biblioteka::get_biblioteka()->wyswietlCzytelnikow();
                cout << "Naciśnij Enter, aby kontynuować...";
                cin.get();  // Oczekiwanie na naciśnięcie klawisza Enter
                break;
            case 3:
                // Edytuj Czytelnika
                Biblioteka::get_biblioteka()->wyswietlCzytelnikow();
                cout << "Wybierz, którego czytelnika chcesz edytować: ";
                size_t index;
                cin >> index;
                cin.ignore();
                Biblioteka::get_biblioteka()->edytujCzytelnika(index - 1);
                break;
            case 4:
                // Usuń Czytelnika
                Biblioteka::get_biblioteka()->wyswietlCzytelnikow();
                cout << "Wybierz, którego czytelnika chcesz usunąć: ";
                size_t index2;
                cin >> index2;
                cin.ignore();
                Biblioteka::get_biblioteka()->usunCzytelnika(index2 - 1);
                break;
            case 5:
                cout << "Ile czytelnikow chcesz wygenerowac: ";
                size_t ilosc;
                cin >> ilosc;
                cin.ignore();
                Biblioteka::get_biblioteka()->stworzCzytelnikow(ilosc);
                break;
            case 6:
                Biblioteka::get_biblioteka()->szukajCzytelnika();
                cout << "Naciśnij Enter, aby kontynuować...";
                cin.get();  // Oczekiwanie na naciśnięcie klawisza Enter
                break;
            case 7:
                break;
            default:
                // cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru
                break;
        }

    } while (wybor != 7);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Powrot do menu glownego");
}

void menuKsiazek() {
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
        RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wyswietlono menu zarzadzania ksiazkami");
        cin >> wybor;
        cin.ignore();
        RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wybrano opcje " + std::to_string(wybor));
        switch (wybor) {
            case 1:
                // Dodaj nową Książkę
                Biblioteka::get_biblioteka()->utworzKsiazke();
                break;
            case 2:
                // Wyświetl listę obiektów Książka
                Biblioteka::get_biblioteka()->wyswietlKsiazki();
                cout << "Naciśnij Enter, aby kontynuować...";
                cin.get();  // Oczekiwanie na naciśnięcie klawisza Enter
                break;
            case 3:
                // Edytuj Książkę
                Biblioteka::get_biblioteka()->wyswietlKsiazki();
                cout << "Wybierz, którą książkę chcesz edytować: ";
                size_t index1;
                cin >> index1;
                cin.ignore();
                Biblioteka::get_biblioteka()->edytujKsiazke(index1 - 1);
                break;
            case 4:
                // Usuń Książkę
                Biblioteka::get_biblioteka()->wyswietlKsiazki();
                cout << "Wybierz, którą książkę chcesz usunąć: ";
                size_t index2;
                cin >> index2;
                cin.ignore();
                Biblioteka::get_biblioteka()->usunKsiazke(index2 - 1);
                break;
            case 5:
                // Stworz baze ksiazek
                cout << "Ile ksiazek chcesz wygenerowac: ";
                size_t ilosc;
                cin >> ilosc;
                cin.ignore();
                Biblioteka::get_biblioteka()->stworzKsiazki(ilosc);
                break;
            case 6:
                break;
            default:
                // cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru
                break;
        }

    } while (wybor != 6);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Powrot do menu glownego");
}

size_t generujLiczbeLosowa(size_t begin, size_t end) {
    static std::random_device seed;
    static std::mt19937 engine(seed());
    static std::uniform_int_distribution<size_t> uniformDist(begin, end);
    return uniformDist(engine);
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Wygenerowano liczbe losowa");
};

const size_t nImiona = 22;
const size_t nNazwiska = 17;
const size_t nUlice = 22;
const size_t nEmaile = 12;
const size_t nWydawnictwa = 12;
const size_t nTytuly = 20;
const size_t nDzialy = 10;
std::string_view Imiona[nImiona]{"Adam",   "Bartek", "Cezary", "Dawid",  "Emil",   "Filip",   "Grzegorz", "Henryk",
                                 "Igor",   "Janusz", "Kamil",  "Lukasz", "Marek",  "Norbert", "Oskar",    "Pawel",
                                 "Robert", "Stefan", "Tomasz", "Wiktor", "Szymon", "Jan"};

std::string_view Nazwiska[nNazwiska]{"Nowak",      "Kowalski",  "Wisniewski", "Dabrowski",     "Lewandowski",
                                     "Wojcik",     "Kaminski",  "Kowalczyk",  "Zielinski",     "Szymanski",
                                     "Wozniak",    "Kozlowski", "Jankowski",  "Wojciechowski", " Kwiatkowski",
                                     "Malinowski", "Zawadzki"};

std::string_view Ulice[nUlice]{"Mickiewicza", "Slowackiego",  "Sienkiewicza",  "Konopnickiej",   "Reymonta",
                               "Lelewela",    "Moniuszki",    "Pilsudskiego",  "Sobieskiego",    "Kosciuszki",
                               "Piastowska",  "Jagiellonska", "Wyspianskiego", "Matejki",        "Krasickiego",
                               "Orzeszkowej", "Kasprowicza",  "Staszica",      "Kochanowskiego", "Malczewskiego",
                               "Roosevelta",  "Churchilla"};

std::string_view Emaile[nEmaile]{"@gmail.com",  "@mail.com",   "@yahoo.com",    "@outlook.com",
                                 "@icloud.com", "@aol.com",    "@zoho.com",     "@protonmail.com",
                                 "@gmx.com",    "@yandex.com", "@fastmail.com", "@hotmail.com"};

std::string_view Wydawnictwa[nWydawnictwa]{
    "Wydawnictwo Literackie", "Wydawnictwo Naukowe PWN", "Wydawnictwo Znak",      "Wydawnictwo Ossolineum",
    "Wydawnictwo Czarne",     "Wydawnictwo WAB",         "Wydawnictwo Iskry",     "Wydawnictwo Zysk",
    "Wydawnictwo Otwarte",    "Wydawnictwo Agora",       "Wydawnictwo Marginesy", "Wydawnictwo Noir sur Blanc"};

std::string_view Dzialy[nDzialy]{"Literatura Polska", "Literatura Obca", "Fantastyka",      "Kryminał",
                                 "Sensacja",          "Horror",          "Science Fiction", "Biografia",
                                 "Historyczna",       "Popularnonaukowa"};

std::string_view Tytuly1[nTytuly]{"Cicha",      "Wieczna",  "Złota",    "Ostatnia",   "Zaginiona",
                                  "Tajemnicza", "Stara",    "Pierwsza", "Zimowa",     "Letnia",
                                  "Wiosenna",   "Jesienna", "Północna", "Południowa", "Wschodnia",
                                  "Zachodnia",  "Czarna",   "Biała",    "Szara",      "Czerwona"};

std::string_view Tytuly2[nTytuly]{"Noc",      "Wieża",     "Róża",    "Księga",  "Droga",    "Przepaść", "Łąka",
                                  "Pustynia", "Tajemnica", "Burza",   "Rzeka",   "Światło",  "Cisza",    "Gwiazda",
                                  "Kraina",   "Pieśń",     "Ścieżka", "Forteca", "Przystań", "Opowieść"};