#include "cajadeahorro.h"

CajaDeAhorro::CajaDeAhorro(double balanceIn , string titular) : CuentaBancaria(balanceIn,titular) , VecesMostro(0){} 
CajaDeAhorro::~CajaDeAhorro(){}

void CajaDeAhorro::retirar(double cantidad){
    if (cantidad > balance){
        cout << "No tiene esa cantidad de dinero en la Caja de Ahorro. " << endl;   
    } else { 
        balance -= cantidad;
    }
}

void CajaDeAhorro::mostrarInfo(){
    VecesMostro++;
    if (VecesMostro > 2 ){
        cout << "Se van a restar $20 porque se mostro la informacion mas de dos veces" << endl;
        retirar(20);
    }
    cout<< "------Informacion de la caja de ahorro------" << endl;
    cout<< "Titular de la cuenta: " <<titularCuenta << endl;
    cout<< "Balance: " << balance << endl;
} 
