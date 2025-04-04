#include "cuentabancaria.h"

CuentaBancaria::CuentaBancaria(double balanceIn , string titular) : balance(balanceIn), titularCuenta(titular){}
CuentaBancaria:: ~CuentaBancaria(){}

void CuentaBancaria::depositar(double cantidad){
    if(cantidad < 0){
        cout<< "Error, plata ingresada negativa." << endl;
    }else{
        balance += cantidad;
    }
    
}






