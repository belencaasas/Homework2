#pragma once 
#include "cuentabancaria.h"

class CajaDeAhorro : public CuentaBancaria{
    private: /* Son accesibles dentro de la misma clase y no pueden ser accedidos ni modificados directamente desde fuera de la clase,
             ni siquiera desde una clase derivada (en el caso de la herencia*/
        int VecesMostro; 
    
    public: 
        virtual ~CajaDeAhorro();
        CajaDeAhorro (double balanceIn , string titular);
        void retirar (double cantidad) override;
        void mostrarInfo() override;
        friend class CuentaCorriente; //caja de ahorro acceda al estado de la cuenta corriente 
}; 
