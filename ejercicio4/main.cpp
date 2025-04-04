#include <iostream>
#include "cuentacorriente.h"
#include "cuentabancaria.h"
#include "cajadeahorro.h"

int main(){
    CajaDeAhorro CajaDeAhorro(500,"Belen");
    CuentaCorriente CuentaCorriente(20, &CajaDeAhorro);
    cout << "**********Inicializacion de la cuenta**********" << endl; 
    cout << "Titular de la cuenta: Belen " << endl; 
    cout << "Dinero de la caja de ahorro: $500" << endl;  
    cout << "Dinero de la cuenta corriente: $20\n" << endl; 

    cout << "**********Depositar dinero**********" << endl; 
    CajaDeAhorro.depositar(100);
    CuentaCorriente.depositar(80);
    cout << "Se ha depositado $100 en la caja de ahorro." << endl; 
    cout << "Se ha depositado $80 en la cuenta corriente."<< endl; 
    CajaDeAhorro.mostrarInfo();
    CuentaCorriente.mostrarInfo();
    cout << endl;

    cout << "**********Retirar Dinero y no tiene**********" << endl;
    CajaDeAhorro.retirar(700);
    cout << endl; 

    cout << "**********Retirar Dinero**********" << endl;
    cout << "Se han retirado $100 de la caja de ahorro." << endl;
    CajaDeAhorro.retirar(100);
    CajaDeAhorro.mostrarInfo();
    cout << "Se han retirado $50 de la cuenta corriente." << endl;
    CuentaCorriente.retirar(50);
    CuentaCorriente.mostrarInfo();
    cout << endl;

    cout << "**********Retira dinero de la cuenta corriente y no tiene, usa la caja de ahorro**********" << endl; 
    CuentaCorriente.retirar(100);
    CuentaCorriente.mostrarInfo(); 
    CajaDeAhorro.mostrarInfo(); //en esta linea hago que le cobre la multa 
    cout << endl;

    cout <<"**********Retira dinero que no posee en el banco**********" << endl;
    CuentaCorriente.retirar(1000);
    cout << endl; 

    cout << "**********Retira el dinero y queda en cero**********" << endl; 
    CajaDeAhorro.retirar(430);
    CajaDeAhorro.mostrarInfo();


}