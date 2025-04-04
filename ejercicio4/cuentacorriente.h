#pragma once
#include "cuentabancaria.h"
#include "cajadeahorro.h"

class CuentaCorriente : public CuentaBancaria{
    private:
        CajaDeAhorro*  CajaDeAhorroPrestada;
    public: 
        virtual ~CuentaCorriente();
        CuentaCorriente(double balanceIn , CajaDeAhorro* CDA);
        void retirar(double cantidad) override;
        void mostrarInfo() override;
          
};