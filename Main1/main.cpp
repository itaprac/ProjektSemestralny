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

    int wybor;
    do {
        menuGlowne();
        cin >> wybor;
        cin.ignore();  // Czyszczenie entera
        switch (wybor) {
            case 1:
                // zardzadanie czytelnikami
                menuCzytelnikow(czytelnicy, last_id);
                break;
            case 2:
                // zarzadanie ksiazkami
                menuKsiazek(ksiazki);
                break;
            case 3:
                cout << "Wychodzenie z programu...\n";
                break;
            default:
                // cout << "Nieprawidlowy wybor" << endl;
                break;
        }
    } while (wybor != 3);
}