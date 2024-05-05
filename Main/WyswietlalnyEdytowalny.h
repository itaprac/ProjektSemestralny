#pragma once
class WyswietlalnyEdytowalny {
   public:
    virtual void wyswietl() const = 0;
    virtual void edytuj() = 0;
    virtual ~WyswietlalnyEdytowalny(){};
};