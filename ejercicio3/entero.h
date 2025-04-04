#pragma once
#include "numero.h"
using namespace std;

class Entero: public Numero {  //la clase entero es una derivada de la clase numero
    private: 
        int valor; 
    public: 
        Entero(int valor);
        unique_ptr<Numero> suma(Numero& otro) override;
        unique_ptr<Numero> resta(Numero& otro) override;
        unique_ptr<Numero> multiplicacion(Numero& otro) override;
        string toString() override;
        ~Entero() override = default;
        
};