#pragma once 

#include <string>
#include <iostream>
using namespace std;

class CuentaBancaria{
    protected: /*el uso de protected es para que sus clases derivadas puedan usar lo que esta adentro de el, ya que sino no podrian acceder 
                a sus datos, pero no son accesibles desde fuera de las clases o sus derivadas */
        double balance; 
        string titularCuenta;
    
    public: /*son accesibles desde cualquier parte del programa, ya sea dentro de la clase, fuera de la clase, o desde otras clases.*/
        CuentaBancaria (double balanceIn , string titular);
        virtual ~CuentaBancaria();
        void depositar(double cantidad);
        virtual void retirar (double cantidad) = 0;
        virtual void mostrarInfo() = 0;
};


