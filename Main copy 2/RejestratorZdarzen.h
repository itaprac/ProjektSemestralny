#pragma once

#include <string>
#include <vector>

class RejestratorZdarzen {
    static RejestratorZdarzen* rejestratorZdarzen;
    std::vector<std::string> zdarzenia;
    size_t max_liczba_zdarzen;

   public:
    RejestratorZdarzen();
    RejestratorZdarzen(size_t);
    static RejestratorZdarzen* get_rejestratorZdarzen();
    void dodajZdarzenie(const std::string&);
    void wyswietlZdarzenia() const;
    void usunRejestratorZdarzen();
};
