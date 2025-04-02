#include <iostream>
#include "numero.h"

int main(){
    //parametros ya definidos 
    Numero* entero1= new Entero(10);
    Numero* entero2 = new Entero(19);

    Numero* real1 =  new Real(1.5);
    Numero* real2 = new Real (3.5);

    Numero* complejo1 = new Complejo(1,2);
    Numero* complejo2 = new Complejo(19,10);



    Numero* sumaEnteros = entero1->suma(entero2);
    cout << "La suma de enteros es: " << sumaEnteros->toString() << endl;

    Numero* restaEnteros = entero1->resta(entero2);
    cout << "La resta de enteros es: " << restaEnteros->toString() << endl;

    Numero* multipliacionEnteros = entero1->multiplicacion(entero2);
    cout << "La multiplicacion de enteros es: " << multipliacionEnteros->toString() << endl;



    Numero* sumaReales = real1->suma(real2);
    cout << "La suma de reales es: " << sumaReales->toString() << endl;

    Numero* restaReales = real1->resta(real2);
    cout << "La resta de reales es: " << restaReales->toString() << endl;

    Numero* multipliacionReales = real1->multiplicacion(real2);
    cout << "La multiplicacion de reales es: " << multipliacionReales->toString() << endl;



    Numero* sumaComplejos = complejo1->suma(complejo2);
    cout << "La suma de complejos es: " << sumaComplejos->toString() << endl;

    Numero* restaComplejos = complejo1->resta(complejo2);
    cout << "La resta de complejos es: " << restaComplejos->toString() << endl;

    Numero* multipliacionComplejos = complejo1->multiplicacion(complejo2);
    cout << "La multiplicacion de complejos es: " << multipliacionComplejos->toString() << endl;

    delete entero1;
    delete entero2;
    delete sumaEnteros;
    delete restaEnteros;
    delete multipliacionEnteros;
    delete real1;
    delete real2;
    delete sumaReales;
    delete restaReales;
    delete multipliacionReales;
    delete complejo1;
    delete complejo2;
    delete sumaComplejos;
    delete restaComplejos;
    delete multipliacionComplejos;



    return 0; 
}