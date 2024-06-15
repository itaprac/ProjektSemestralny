#pragma once
class Obiekt {
   public:
    virtual void wyswietl() const = 0;
    virtual void edytuj() = 0;
    virtual void gen_data() = 0;
    virtual void ocen() = 0;
    virtual ~Obiekt(){};
};