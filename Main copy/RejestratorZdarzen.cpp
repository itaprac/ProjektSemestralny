#include "RejestratorZdarzen.h"

#include <iostream>
#include <string>
#include <vector>

RejestratorZdarzen* RejestratorZdarzen::rejestratorZdarzen = nullptr;

RejestratorZdarzen::RejestratorZdarzen(size_t maxZdarzen) : max_liczba_zdarzen(maxZdarzen) {}

RejestratorZdarzen* RejestratorZdarzen::get_rejestratorZdarzen() {
    if (rejestratorZdarzen == nullptr) {
        rejestratorZdarzen = new RejestratorZdarzen();
    }
    return rejestratorZdarzen;
};

void RejestratorZdarzen::dodajZdarzenie(const std::string& zdarzenie) {
    if (zdarzenia.size() >= max_liczba_zdarzen) {
        zdarzenia.erase(zdarzenia.begin());
    }
    zdarzenia.push_back(zdarzenie);
};

void RejestratorZdarzen::wyswietlZdarzenia() const {
    for (const auto& zdarzenie : zdarzenia) {
        std::cout << zdarzenie << std::endl;
    }
};

void RejestratorZdarzen::usunRejestratorZdarzen() {
    delete rejestratorZdarzen;
    rejestratorZdarzen = nullptr;
};
