#include <iostream>

struct Czytelnik {
    std::string imie;
    std::string email;
    size_t numerTelefonu;
    size_t numerID;
    struct Adres {
        std::string ulica;
        size_t numerDomu;
    } adres;
    std::vector<struct Ksiazka> wypozyczoneKsiazki;
};

struct Ksiazka {
    std::string tytul;
    std::string autor;
    std::string wydawnictwo;
    size_t rokWydania;
    struct Lokalizacja {
        std::string dzial;
        size_t numerRegalu;
    } lokalizacja;
    bool dostepna = true;
};

void showMainMenu() {
    std::cout << "\n------- Main Menu -------\n"
              << "1. Manage Readers\n"
              << "2. Manage Books\n"
              << "3. Exit\n"
              << "-------------------------\n"
              << "Enter your choice: ";
}

void manageReaders() {
    std::cout << "\n--- Manage Readers ---\n"
              << "1. Add Reader\n"
              << "2. Display Readers\n"
              << "3. Edit Reader\n"
              << "4. Delete Reader\n"
              << "----------------------\n"
              << "Enter your choice: ";
    // Your reader management logic here
}

void manageBooks() {
    std::cout << "\n--- Manage Books ---\n"
              << "1. Add Book\n"
              << "2. Display Books\n"
              << "3. Edit Book\n"
              << "4. Delete Book\n"
              << "---------------------\n"
              << "Enter your choice: ";
    // Your book management logic here
}

int main() {
    int choice;
    do {
        showMainMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer

        switch (choice) {
            case 1:
                manageReaders();
                break;
            case 2:
                manageBooks();
                break;
            case 3:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid option, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void wyswietl(const std::vector<Czytelnik>& czytelnicy) {
    using std::cout;
    cout << "\n==============================\n";
    cout << "          Lista Czytelnikow          \n";
    cout << "==============================\n";
    int i = 1;
    for (const Czytelnik& czytelnik : czytelnicy) {
        cout << i++ << ". " << czytelnik.imie << "\n"
             << "   Email: " << czytelnik.email << "\n"
             << "   Numer telefonu: " << czytelnik.numerTelefonu << "\n"
             << "   Numer ID: " << czytelnik.numerID << "\n"
             << "   Adres: " << czytelnik.adres.ulica << " " << czytelnik.adres.numerDomu << "\n"
             << "   Wypozyczone ksiazki: ";
        if (czytelnik.wypozyczoneKsiazki.empty()) {
            cout << "Brak";
        } else {
            for (const Ksiazka& ksiazka : czytelnik.wypozyczoneKsiazki) {
                cout << ksiazka.tytul << " (" << ksiazka.autor << "), ";
            }
        }
        cout << "\n------------------------------\n";
    }
    cout << "==============================\n\n";
}
