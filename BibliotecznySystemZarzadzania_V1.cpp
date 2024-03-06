#include <iostream>
#include <string>

struct Adres {
    char miasto[100];
    char ulica[100];
    size_t numerDomu;
};

struct Lokalizacja {
    char Dzial[100];
    size_t numerRegalu;
};

struct Ksiazka {
    char tytul[100];
    char autor[100];
    char wydawnictwo[100];
    size_t rokWydania;
    Lokalizacja lokalizacja;
    bool wyporzyczona;
};

struct Czytelnik {
    char imie[100];
    char email[100];
    size_t numerTelefonu;
    size_t numerID;
    Adres adres;
    size_t liczbaKsiazek;
    Ksiazka *wyporzyczoneKsiazki;
};

void stworz(Czytelnik *&czytelnicy, const size_t rozmiar) {
    czytelnicy = new Czytelnik[rozmiar];
}

void usun(Czytelnik *&czytelnicy) {
    delete[] czytelnicy;
    czytelnicy = nullptr;
}

void wprowadz_po_index(Czytelnik *&czytelnicy, const int index) {
    using std::cout, std::cin, std::endl;
    cout << "Imie: " << endl;
    cin >> czytelnicy[index].imie;
    cout << "Email: " << endl;
    cin >> czytelnicy[index].email;
    cout << "Numer telefonu " << endl;
    cin >> czytelnicy[index].numerTelefonu;
    cout << "Numer ID: " << endl;
    cin >> czytelnicy[index].numerID;
    cout << "Miasto: " << endl;
    cin >> czytelnicy[index].adres.miasto;
    cout << "Ulica: " << endl;
    cin >> czytelnicy[index].adres.ulica;
    cout << "Numer domu: " << endl;
    cin >> czytelnicy[index].adres.numerDomu;
};

int main(void) {
    using std::cout, std::cin, std::endl;
    int n;
    while (true) {
        cout << "1. stworz liste czytelnikow" << endl;
        cout << "2. usun liste czytelnikow" << endl;
        cout << "3. wprowadz uzytkownika po indeksie" << endl;
        cout << "Wybor: " << endl;
        cin >> n;
        switch (n) {
            case 1:

            case 2:;
        }
    };
}