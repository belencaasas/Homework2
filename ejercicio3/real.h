#pragma once
#include "numero.h"

class Real: public Numero {  //la clase real es una derivada de la clase numero
    private: 
        double valor; 
    public: 
        Real(double valor);
        unique_ptr<Numero> suma(Numero& otro) override;
        unique_ptr<Numero> resta(Numero& otro) override;
        unique_ptr<Numero> multiplicacion(Numero& otro) override;
        string toString() override;
        ~Real() override = default;
};