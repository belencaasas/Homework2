#include "banco.h"

CuentaBancaria::CuentaBancaria(double balanceIn , string titular) : balance(balanceIn), titularCuenta(titular){}
CuentaBancaria:: ~CuentaBancaria(){}

void CuentaBancaria::depositar(double cantidad){
    if(cantidad < 0){
        cout<< "Error, plata ingresada negativa." << endl;
    }else{
        balance += cantidad;
    }
    
}

CajaDeAhorro::CajaDeAhorro(double balanceIn , string titular) : CuentaBancaria(balanceIn,titular) , VecesMostro(0){} 

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

CuentaCorriente::CuentaCorriente(double balanceIn, CajaDeAhorro* CDA) : CuentaBancaria(balanceIn, CDA->titularCuenta), CajaDeAhorroPrestada(CDA) {} 

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



