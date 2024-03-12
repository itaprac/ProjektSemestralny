#include <iostream>
#include <string>
#include <vector>

#include "funkcje.h"

int main(void) {
    using std::cout, std::cin, std::endl;

    // Tworzenie wektora czytelnikow
    std::vector<Czytelnik> czytelnicy = {
        {"Jan Kowalski", "jan.kowalski@example.com", "123456789", 1, {"Krakowska", 10}},
        {"Anna Nowak", "anna.nowak@example.com", "987654321", 2, {"Warszawska", 20}},
        {"Piotr Zielinski", "piotr.zielinski@example.com", "456789123", 3, {"Poznanska", 30}}};

    // Tworzenie wektora ksiazek
    std::vector<Ksiazka> ksiazki = {
        {"Krzyżacy", "Henryk Sienkiewicz", "Wydawnictwo Literackie", 1900, {"Literatura Polska", 1}, true},
        {"Pan Tadeusz", "Adam Mickiewicz", "Wydawnictwo Literackie", 1834, {"Literatura Polska", 2}, true},
        {"Lalka", "Bolesław Prus", "Wydawnictwo Literackie", 1890, {"Literatura Polska", 3}, true},
        {"Dziady", "Adam Mickiewicz", "Wydawnictwo Literackie", 1822, {"Literatura Polska", 4}, true}};

    size_t last_id = czytelnicy.size();  // Przypisanie ostatniego numeru ID czytelnika

    int wybor1;
    do {
        menuGlowne();
        cin >> wybor1;
        cin.ignore();
        switch (wybor1) {
            case 1:
                // zardzadanie czytelnikami
                int wybor2;
                do {
                    menuCzytelnikow();
                    cin >> wybor2;
                    cin.ignore();
                    switch (wybor2) {
                        case 1:
                            // Dodaj nowego Czytelnika
                            dodaj(czytelnicy, last_id);
                            break;
                        case 2:
                            // Wyświetl listę obiektów Czytelnik
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
                        default:
                            // cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru
                            break;
                    }
                } while (wybor2 != 5);
                break;
            case 2:
                // zarzadanie ksiazkami
                int wybor3;
                do {
                    menuKsiazek();
                    cin >> wybor3;
                    cin.ignore();
                    switch (wybor3) {
                        case 1:
                            // Dodaj nową Książkę
                            dodaj(ksiazki);
                            break;
                        case 2:
                            // Wyświetl listę obiektów Książka
                            wyswietl(ksiazki);
                            cout << "Naciśnij Enter, aby kontynuować...";
                            cin.get();  // Oczekiwanie na naciśnięcie klawisza Enter
                            break;
                        case 3:
                            // Edytuj Książkę
                            wyswietl(ksiazki);
                            cout << "Wybierz, którą książkę chcesz edytować: ";
                            size_t index3;
                            cin >> index3;
                            cin.ignore();
                            edytuj(ksiazki, index3 - 1);
                            break;
                        case 4:
                            // Usuń Książkę
                            wyswietl(ksiazki);
                            cout << "Wybierz, którą książkę chcesz usunąć: ";
                            size_t index4;
                            cin >> index4;
                            cin.ignore();
                            usun(ksiazki, index4 - 1);
                            break;
                        default:
                            // cout << "Nie ma takiej opcji" << endl;  // Obsługa niepoprawnego wyboru
                            break;
                    }
                } while (wybor3 != 5);
                break;
            case 3:
                cout << "Wychodzenie z programu..." << endl;
                break;
            default:
                // cout << "Nieprawidlowy wybor" << endl;
                break;
        }
    } while (wybor1 != 3);
}