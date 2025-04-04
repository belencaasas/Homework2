#include <iostream>
#include "complejo.h"
#include "entero.h"
#include "real.h"



int main(){
    //parametros ya definidos 
    unique_ptr<Numero> entero1= make_unique<Entero>(10);
    unique_ptr<Numero> entero2 = make_unique<Entero>(19);

    unique_ptr<Numero> real1 =  make_unique<Real>(1.5);
    unique_ptr<Numero> real2 = make_unique<Real>(3.5);

    unique_ptr<Numero> complejo1 = make_unique<Complejo>(1,2);
    unique_ptr<Numero> complejo2 = make_unique<Complejo>(19,10);



    unique_ptr<Numero> sumaEnteros(entero1->suma(*entero2));
    cout << "La suma de enteros es: " << sumaEnteros->toString() << endl;

    unique_ptr<Numero> restaEnteros(entero1->resta(*entero2));
    cout << "La resta de enteros es: " << restaEnteros->toString() << endl;

    unique_ptr<Numero> multipliacionEnteros(entero1->multiplicacion(*entero2));
    cout << "La multiplicacion de enteros es: " << multipliacionEnteros->toString() << endl;



    unique_ptr<Numero> sumaReales(real1->suma(*real2));
    cout << "La suma de reales es: " << sumaReales->toString() << endl;

    unique_ptr<Numero> restaReales(real1->resta(*real2));
    cout << "La resta de reales es: " << restaReales->toString() << endl;

    unique_ptr<Numero> multipliacionReales(real1->multiplicacion(*real2));
    cout << "La multiplicacion de reales es: " << multipliacionReales->toString() << endl;



    unique_ptr<Numero> sumaComplejos(complejo1->suma(*complejo2));
    cout << "La suma de complejos es: " << sumaComplejos->toString() << endl;

    unique_ptr<Numero> restaComplejos(complejo1->resta(*complejo2));
    cout << "La resta de complejos es: " << restaComplejos->toString() << endl;

    unique_ptr<Numero> multipliacionComplejos(complejo1->multiplicacion(*complejo2));
    cout << "La multiplicacion de complejos es: " << multipliacionComplejos->toString() << endl;

    return 0; 
}