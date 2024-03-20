#include <iostream>
#include <string>
#include <vector>

#include "funkcje.h"

int main(void) {
    using std::cout, std::cin, std::endl;

    // Tworzenie wektora czytelnikow
    std::vector<Czytelnik> czytelnicy = {};
    size_t last_id = czytelnicy.size();  // Przypisanie ostatniego numeru ID czytelnika

    Ksiazka** ksiazki{nullptr};
    size_t liczba_ksiazek = 0;

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
                menuKsiazek(ksiazki, liczba_ksiazek);
                break;
            case 3:
                cout << "Wychodzenie z programu...\n";
                usun(ksiazki, liczba_ksiazek);
                break;
            default:
                // cout << "Nieprawidlowy wybor" << endl;
                break;
        }
    } while (wybor != 3);
}