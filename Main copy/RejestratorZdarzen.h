#pragma once

#include <string>
#include <vector>

class RejestratorZdarzen {
    static RejestratorZdarzen* rejestratorZdarzen;
    std::vector<std::string> zdarzenia;
    size_t max_liczba_zdarzen;

   public:
    RejestratorZdarzen(size_t maxZdarzen = 100);
    static RejestratorZdarzen* get_rejestratorZdarzen();
    void dodajZdarzenie(const std::string& zdarzenie);
    void wyswietlZdarzenia() const;
    void usunRejestratorZdarzen();
};