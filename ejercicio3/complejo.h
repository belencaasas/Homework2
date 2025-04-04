#pragma once
#include "numero.h"

class Complejo: public Numero {  //la clase complejo es una derivada de la clase numero
    private: 
        double real , imaginario; 
    public: 
        Complejo(double real, double imaginario);
        unique_ptr<Numero> suma(Numero& otro) override;
        unique_ptr<Numero> resta(Numero& otro) override;
        unique_ptr<Numero> multiplicacion(Numero& otro) override;
        string toString() override;
        ~Complejo() override = default;
};