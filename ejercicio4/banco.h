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



class CajaDeAhorro : public CuentaBancaria{
    private: /* Son accesibles dentro de la misma clase y no pueden ser accedidos ni modificados directamente desde fuera de la clase,
             ni siquiera desde una clase derivada (en el caso de la herencia*/
        int VecesMostro; 
    
    public: 
        CajaDeAhorro (double balanceIn , string titular);
        void retirar (double cantidad) override;
        void mostrarInfo() override;
        friend class CuentaCorriente; //caja de ahorro acceda al estado de la cuenta corriente 
}; 



class CuentaCorriente : public CuentaBancaria{
    private:
        CajaDeAhorro*  CajaDeAhorroPrestada;
    public: 
        CuentaCorriente(double balanceIn , CajaDeAhorro* CDA);
        void retirar(double cantidad) override;
        void mostrarInfo() override;
          
};