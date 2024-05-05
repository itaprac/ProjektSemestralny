#include "Biblioteka.h"
#include "Czytelnik.h"
#include "Ksiazka.h"
#include "RejestratorZdarzen.h"
#include "WyswietlalnyEdytowalny.h"
#include "dane.h"
#include "funkcje.h"

int main(void) {
    Biblioteka::get_biblioteka();
    RejestratorZdarzen::get_rejestratorZdarzen()->dodajZdarzenie("Program uruchomiony");
    menuGlowne();
    std::cout << "\n\n========================================\n"
              << "              Rejestr Zdarzen\n"
              << "========================================\n";
    RejestratorZdarzen::get_rejestratorZdarzen()->wyswietlZdarzenia();

    RejestratorZdarzen::get_rejestratorZdarzen()->usunRejestratorZdarzen();
}