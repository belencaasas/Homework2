#include "cuentacorriente.h"

CuentaCorriente::CuentaCorriente(double balanceIn, CajaDeAhorro* CDA) : CuentaBancaria(balanceIn, CDA->titularCuenta), CajaDeAhorroPrestada(CDA) {} 
CuentaCorriente::~CuentaCorriente(){}

void CuentaCorriente::retirar(double cantidad){
    if (cantidad > balance){
        cout << "No tiene ese dinero en la cuenta corriente, lo obtiene de la caja de ahorro." << endl;
        this->CajaDeAhorroPrestada->retirar(cantidad-this->balance);
    } else if(cantidad < balance){
        balance -= cantidad;
    } else{
        cout << "No tiene esa cantidad de dinero en el banco. " << endl;
    }    
}


void CuentaCorriente::mostrarInfo(){
    cout<< "------Informacion de la cuenta corriente ------" << endl;
    cout<< "Titular de la cuenta: " <<titularCuenta << endl;
    cout<< "Balance: " << balance << endl; 
}

