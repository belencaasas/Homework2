#pragma once

#include <string>
#include <sstream>
using namespace std;


class Numero{
    public: 
        virtual Numero* suma(Numero* otro) = 0;
        virtual Numero* resta(Numero* otro) = 0;
        virtual Numero* multiplicacion(Numero* otro) = 0;
        virtual string toString() = 0;
        virtual ~Numero();
        
};

class Entero: public Numero {  //la clase entero es una derivada de la clase numero
    private: 
        int valor; 
    public: 
        Entero(int valor);
        Numero* suma(Numero* otro) override;
        Numero* resta(Numero* otro) override;
        Numero* multiplicacion(Numero* otro) override;
        string toString() override;
        virtual ~Entero();
        
};

class Real: public Numero {  //la clase entero es una derivada de la clase numero
    private: 
        double valor; 
    public: 
        Real(double valor);
        Numero* suma(Numero* otro) override;
        Numero* resta(Numero* otro) override;
        Numero* multiplicacion(Numero* otro) override;
        string toString() override;
        virtual ~Real();
};

class Complejo: public Numero {  //la clase entero es una derivada de la clase numero
    private: 
        double real , imaginario; 
    public: 
        Complejo(double real, double imaginario);
        Numero* suma(Numero* otro) override;
        Numero* resta(Numero* otro) override;
        Numero* multiplicacion(Numero* otro) override;
        string toString() override;
        virtual ~Complejo();
};