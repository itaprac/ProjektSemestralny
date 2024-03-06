#include <cstdlib>   // nie używamy <cstdio>, ponieważ cstdlib ta biblioteka
#include <iostream>  // odpowiednikiem w jęsyku C jest #include <stdio.h>
#include <string>
// zawiera <cstdio>, srand(), rand()
#include <locale>
// import <ctime>; // time()

// using namespace std;

struct Osoba {
    size_t pesel;
    size_t rocznik;
    size_t wzrost;
    char godnosc[100];
};
void print(Osoba);
void print(Osoba*);
void print(const auto, const auto);
void print(const Osoba* const* const* const, const auto, const auto);
void wprowadz(Osoba*);
void wprowadz(Osoba&);
void stworz(Osoba**);
void stworz(Osoba*&);
void stworz(Osoba*&, const size_t);
void stworz(Osoba**&, const size_t);
void stworz(Osoba***&, const size_t, const size_t);

void usun(Osoba**);
void usun(Osoba*&);
void usun(Osoba*&, const size_t);
void usun(Osoba**&, size_t&, size_t);
void usun(Osoba**&, size_t&);
void usun_kolumne(Osoba***&, const size_t, size_t&);

void dodaj_kolumne(Osoba***&, const size_t, size_t&);

void ini(Osoba* const, const size_t);
void ini(Osoba* const* const, const size_t);
void ini(Osoba* const* const* const, const size_t, const size_t);

void przyklad_1();
void przyklad_2();
void przyklad_3();
void przyklad_4();
void przyklad_5();
void przyklad_6();
void przyklad_7();
void przyklad_8();
void przyklad_9();
void przyklad_10();
void przyklad_11();
void pokaz_temat(std::string);  // string - następny temat, nie teraz

int main() {
    setlocale(LC_CTYPE, "Polish");
    std::cout << "Witaj świat C++ !\n";
    std::puts("C++ jest super !");
    // przyklad_1();
    // przyklad_2();
    // przyklad_3();
    // przyklad_4();
    przyklad_5();
    przyklad_6();
    przyklad_7();
    przyklad_8();
    przyklad_9();
    przyklad_10();
    przyklad_11();

    /*   using namespace std::string_literals;
    auto tekst = "Hello world"s;*/

    std::cout
        << "-----------------------------------------------------------------"
        << std::endl;
}
void pokaz_temat(std::string temat) {
    std::cout
        << "-----------------------------------------------------------------"
        << std::endl;
    std::cout << "Temat : " << temat << std::endl;
}
//-------------------------------------------------------------------
// I.1. Użycie std:: . Używamy na razie formalnie, szczególowe wyjaśnienie
// później
//-------------------------------------------------------------------
void przyklad_1() {
    pokaz_temat("Użycie std::, printf()");
    std::puts("C++ jest super !");
    Osoba _Osoba{};
    _Osoba.pesel = 1001344;
    // funkcja języka C wyświetlanie z formatowaniem
    std::printf("pesel osoby = %zd \n", _Osoba.pesel);
    printf("pesel osoby = %zd \n", _Osoba.pesel);
}
//-------------------------------------------------------------------
// I.2. Proste wyświetlanie w C++ (bez formatowania)
//-------------------------------------------------------------------
void przyklad_2() {
    pokaz_temat("Użycie obiektu 'cout' języka C++ do celów wyświetlania");
    Osoba _Osoba{.pesel = 1001344};
    // użycie obiektu "cout" języka C++ do celów wyświetlania
    std::cout << _Osoba.pesel << std::endl;
}
//-------------------------------------------------------------------
// I.3. Wprowadzenie danych w stylu języka C
//-------------------------------------------------------------------
void przyklad_3() {
    pokaz_temat("użycie scanf_s w C++");
    Osoba _Osoba{.pesel = 1001344, .wzrost = 177};
    // użycie scanf_s w C++
    std::cout << "Wprowadź godność : ";
    scanf("%s", _Osoba.godnosc, 100);  // wartość godnosc nie może mieć spacji
    std::cout << std::endl << "Godność osoby : " << _Osoba.godnosc << std::endl;
}
//-------------------------------------------------------------------
// I.4. Proste wprowadzenie danych w stylu języka C++
//-------------------------------------------------------------------
void przyklad_4() {
    pokaz_temat("Proste wprowadzenie danych w stylu języka C++");
    Osoba _Osoba{.pesel = 1001344};
    std::cout << "Wprowadź numer PESEL : ";
    std::cin >> _Osoba.pesel;
    std::cout << "Wprowadź godność : ";
    std::cin >> _Osoba.godnosc;  // Tak samo jak w C, nie może być spacji
    std::cout << std::endl << "Godność osoby : " << _Osoba.godnosc << std::endl;
}
//-------------------------------------------------------------------
// I.5. Argumenty funkcji, w stylu języka C (użycie wskaźnika)
//-------------------------------------------------------------------
void print(Osoba _Osoba) {
    std::cout << std::endl << "Godność osoby : " << _Osoba.godnosc;
    std::cout << std::endl << "PESEL         : " << _Osoba.pesel;
    std::cout << std::endl;
}
void wprowadz(Osoba* _Osoba) {
    _Osoba->pesel = 1001344;
    std::cout << "Wprowadź numer PESEL : ";
    std::cin >> _Osoba->pesel;
    std::cout << "Wprowadź godność : ";
    std::cin >> _Osoba->godnosc;  // Tak samo jak w C, nie może być spacji
}
void przyklad_5() {
    pokaz_temat("Argumenty funkcji, w stylu języka C (użycie wskaźnika)");
    Osoba osoba{};
    wprowadz(&osoba);
    print(osoba);
}
//-------------------------------------------------------------------
// I.6. Argumenty funkcji, w stylu języka C++ (użycie &, REFERENCJI)
//      Funkcje przeładowane (przeciążone), wprowadź() oraz print()
//-------------------------------------------------------------------
void print(Osoba* _Osoba) {
    std::cout << std::endl << "Godność osoby : " << _Osoba->godnosc;
    std::cout << std::endl << "PESEL         : " << _Osoba->pesel;
    std::cout << std::endl;
}
void wprowadz(Osoba& _Osoba) {
    _Osoba.pesel = 1001344;
    std::cout << "Wprowadź numer PESEL : ";
    std::cin >> _Osoba.pesel;
    std::cout << "Wprowadź godność : ";
    std::cin >> _Osoba.godnosc;  // Tak samo jak w C, nie może być spacji
}
void przyklad_6() {
    pokaz_temat("Argumenty funkcji, w stylu języka C++ (użycie &, REFERENCJI)");
    Osoba osoba{};
    wprowadz(osoba);
    print(&osoba);
}
//-------------------------------------------------------------------
// I.7 Pamięć dynamiczna (nizki posiom); odpowiednik malloc() w języku C
//     TWORZENIE POJEDYNCZEGO OBIEKTU
//-------------------------------------------------------------------
void stworz(Osoba** osoba) {
    Osoba* temp = (Osoba*)malloc(sizeof(Osoba));
    *osoba = temp;
}
void usun(Osoba** osoba) {
    free(*osoba);
    *osoba = NULL;
}
void przyklad_7() {  // program w stylu C
    pokaz_temat("Pamięć dynamiczna a funkcje (nizki posiom) w stylu języka C");
    Osoba* osoba{NULL};
    stworz(&osoba);
    wprowadz(osoba);
    print(osoba);
    usun(&osoba);
}
//-------------------------------------------------------------------
// I.8 Pamięć dynamiczna (nizki posiom) w języku C++
//     TWORZENIE POJEDYNCZEGO OBIEKTU na stercie
//-------------------------------------------------------------------
void stworz(Osoba*& osoba) { osoba = new Osoba; }
void usun(Osoba*& osoba) {
    delete osoba;
    osoba = nullptr;
}
void przyklad_8() {
    pokaz_temat(
        "Pamięć dynamiczna a funkcje (nizki posiom) w stylu języka C++");
    Osoba* osoba{nullptr};
    stworz(osoba);
    wprowadz(osoba);
    print(osoba);
    usun(osoba);
}
//-------------------------------------------------------------------
// I.9. Pamięć dynamiczna (nizki posiom). Jednowymiarowa (1-D) Tablica obiektów
// w C++
//-------------------------------------------------------------------
void stworz(Osoba*& osoba, const size_t rozmiar) { osoba = new Osoba[rozmiar]; }
void usun(Osoba*& osoba, const size_t rozmiar) {
    delete[] osoba;
    osoba = nullptr;
}
void ini(Osoba* const osoby, const size_t rozmiar) {
    int max = 1000;
    int rocznik = 30;
    char string_buf[100];
    for (size_t ind = 0; ind < rozmiar; ind++) {
        char nazwisko[100];
        osoby[ind].pesel = rand() % max + 10000;
        osoby[ind].rocznik = rand() % rocznik + 20;
        sprintf(string_buf, "%zd", ind);
        strcpy(nazwisko, "Kowalski_");
        strcat(nazwisko, string_buf);
        strcpy(osoby[ind].godnosc, nazwisko);
    }
}
void print(Osoba* osoby, const size_t rozmiar) {
    std::cout << "<========= Osoby =========>" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        std::cout << osoby[ind].pesel << "\t" << osoby[ind].godnosc << "\t"
                  << osoby[ind].rocznik << std::endl;
    }
}
void przyklad_9() {
    pokaz_temat("Jednowymiarowa tablica obiektów w C++ na stercie");
    // std::srand(static_cast<unsigned int>(std::time(nullptr))); // Bład
    // kompilacji w MS VS 22 (niedopracowane przez MS) std::srand(std::time(0));
    // // Bład kompilacji w MS VS 22 (niedopracowane przez MS)
    const size_t rozmiar = 10;
    Osoba* osoby{nullptr};
    stworz(osoby, rozmiar);
    ini(osoby, rozmiar);
    print(osoby, rozmiar);
    usun(osoby, rozmiar);
}
//---------------------------------------------------------------------------
// I.10. TWORZENIE 1-D TABLICY WSKAŹNIKÓW OBIEKTÓW
//---------------------------------------------------------------------------
void gen_data(Osoba* osoba) {
    size_t max = 1000;
    size_t rocznik = 30;
    size_t num = rand() % 100000 + 1;
    char nazwisko[100];
    char string_buf[100];
    osoba->pesel = rand() % max + 10000;
    osoba->rocznik = rand() % rocznik + 20;
    sprintf(string_buf, "%zd", num);
    strcpy(nazwisko, "Kowalski_");
    strcat(nazwisko, string_buf);
    strcpy(osoba->godnosc, nazwisko);
}
void stworz(Osoba**& osoby, const size_t rozmiar) {
    osoby = new Osoba*[rozmiar];
    for (size_t ind = 0; ind < rozmiar; ind++) osoby[ind] = new Osoba;
}
void usun(Osoba**& osoby, size_t& rozmiar) {
    for (size_t ind = 0; ind < rozmiar; ind++) delete osoby[ind];
    delete[] osoby;
    osoby = nullptr;
    rozmiar = 0;
}
void print(const auto osoby, const auto rozmiar) {
    std::cout << "<========== Osoby ==========>" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        std::cout << osoby[ind]->pesel << "\t" << osoby[ind]->godnosc << "\t"
                  << osoby[ind]->rocznik << std::endl;
    }
}
void ini(Osoba* const* const osoby, const size_t rozmiar) {
    for (size_t ind = 0; ind < rozmiar; ind++) {
        gen_data(osoby[ind]);
    }
}
void dodaj(Osoba**& kartoteka, size_t& size) {
    Osoba** temp = new Osoba*[size + 1];
    if (size == 0) {
        temp[size] = new Osoba;
    } else {
        for (size_t i = 0; i < size; ++i) temp[i] = kartoteka[i];
        temp[size] = new Osoba;
        delete[] kartoteka;
    }
    kartoteka = temp;
    ++size;
}
void usun(Osoba**& kartoteka, size_t& size, size_t index) {
    if (index < size) {
        Osoba** temp = new Osoba*[size - 1];
        short int j{-1};
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                ++j;
                temp[j] = kartoteka[i];
            }
        delete[] kartoteka;
        kartoteka = temp;
        --size;
    } else
        std::cout << "ERROR: Index jest nieprawidłowy ! " << std::endl;
}
void przyklad_10() {
    pokaz_temat("Jednowymiarowa tablica wskaźników na stercie w C++");
    size_t rozmiar = 10;
    Osoba** osoby;
    stworz(osoby, rozmiar);
    ini(osoby, rozmiar);
    print(osoby, rozmiar);
    size_t index = 0;
    usun(osoby, rozmiar, index);
    print(osoby, rozmiar);
    index = 1;
    usun(osoby, rozmiar, index);
    print(osoby, rozmiar);
    dodaj(osoby, rozmiar);
    dodaj(osoby, rozmiar);
    usun(osoby, rozmiar);
    if (osoby == nullptr) std::cout << "Tablica jest pusta !  " << std::endl;
}
//---------------------------------------------------------------------------
// I.11. TWORZENIE 2-D TABLICY WSKAŹNIKÓW do OBIEKTÓW
//---------------------------------------------------------------------------
void stworz(Osoba***& osoby, const size_t rows, const size_t cols) {
    // Tworzymy kontener kolumn
    osoby = new Osoba**[cols];
    // Tworzymy i dodajemy kolumny
    for (size_t i = 0; i < cols; i++) {
        osoby[i] = new Osoba*[rows];
    }
    for (size_t i = 0; i < cols; i++) {
        for (size_t j = 0; j < rows; j++) {
            osoby[i][j] = new Osoba;
        }
    }
}
void ini(Osoba* const* const* const osoby, const size_t rows,
         const size_t cols) {
    for (size_t i = 0; i < cols; i++) {
        for (size_t j = 0; j < rows; j++) {
            gen_data(osoby[i][j]);
        }
    }
}
void print(const Osoba* const* const* const osoby, const auto rows,
           const auto cols) {
    std::cout << "<======= Tablica, (" << rows << "," << cols << ") =======>"
              << std::endl;
    for (size_t j = 0; j < rows; j++) {
        for (size_t i = 0; i < cols; i++)
            std::cout << osoby[i][j]->rocznik << "\t";
        std::cout << std::endl;
    }
}
void usun(Osoba***& osoby, size_t& rows, size_t& cols) {
    // Usunięcie osób
    for (size_t i = 0; i < cols; i++) {
        for (size_t j = 0; j < rows; j++) delete osoby[i][j];
    }
    // Usunięcie kolumn
    for (size_t i = 0; i < cols; i++) delete[] osoby[i];
    // Usunięcie pojemnika
    delete[] osoby;
    osoby = nullptr;
    rows = cols = 0;
}
void dodaj_kolumne(Osoba***& osoby, const size_t rows, size_t& cols) {
    // Program dostawia kolumnę
    // Tworzymy nowy kontener kolumn
    Osoba*** temp = new Osoba**[cols + 1];
    // Kopiuj kolumny ( podwójne wskaźniki )
    for (size_t i = 0; i < cols; i++) {
        temp[i] = osoby[i];
    }
    // Stwórz i dodaj kolumnę
    temp[cols] = new Osoba*[rows];
    // Stwórz obiekty w nowej kolumnie
    for (size_t i = 0; i < rows; i++) {
        temp[cols][i] = new Osoba;
        gen_data(temp[cols][i]);
    }
    // Usuń stary pojemnik
    delete[] osoby;
    osoby = nullptr;
    ++cols;
    osoby = temp;
}
void usun_kolumne(Osoba***& osoby, const size_t rows, size_t& cols) {
    // Program usuwa ostatnią kolumnę
    // Tworzymy nowy kontener kolumn
    Osoba*** temp = new Osoba**[cols - 1];
    // Kopiuj kolumny ( podwójne wskaźniki )
    for (size_t i = 0; i < cols - 1; i++) temp[i] = osoby[i];
    for (size_t i = 0; i < cols - 1; i++) temp[i] = osoby[i];
    for (size_t j = 0; j < rows; j++) delete osoby[cols - 1][j];
    delete[] osoby[cols - 1];
    osoby = nullptr;
    --cols;
    osoby = temp;
}
void przyklad_11() {
    Osoba*** plansza{
        nullptr};  // każda kratka planszy skojarzona ze wskaźnikiem do Osoba
    size_t rows = 7;
    size_t cols = 10;
    stworz(plansza, rows, cols);
    ini(plansza, rows, cols);
    print(plansza, rows, cols);
    dodaj_kolumne(plansza, rows, cols);
    print(plansza, rows, cols);
    usun_kolumne(plansza, rows, cols);
    print(plansza, rows, cols);
    usun(plansza, rows, cols);
}
