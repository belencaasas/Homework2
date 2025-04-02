#include "numero.h"
Numero::~Numero(){}

Entero::Entero(int valor) : valor(valor){}   //define el constructor de la clase entero

Numero* Entero::suma(Numero* otro) {  
    Entero* e= dynamic_cast<Entero*>(otro); //un cast dinamico que convierte el puntero a un de tipo entero
    if(e){   
        return new Entero(valor + e->valor);
    }
    return nullptr;
}

Numero* Entero::resta(Numero* otro){
    Entero* e = dynamic_cast<Entero*>(otro);
    if (e){
        return new Entero(valor - e->valor);
    }
    return nullptr;
}

Numero* Entero::multiplicacion(Numero* otro){
    Entero* e = dynamic_cast<Entero*>(otro);
    if (e) {
        return new Entero(valor * e->valor);
    }
    return nullptr;
}

string Entero::toString(){
    stringstream ss;
    ss << valor; 
    return ss.str(); 
}

Entero::~Entero(){}





Real::Real(double valor) : valor(valor){}   
                                             

Numero* Real::suma(Numero* otro) {  
    Real* r= dynamic_cast<Real*>(otro); 
    if(r){  
        return new Real(valor + r->valor);

    }
    return nullptr;
}

Numero* Real::resta(Numero* otro){
    Real* r = dynamic_cast<Real*>(otro);
    if (r){
        return new Real(valor - r->valor);
    }
    return nullptr;
}

Numero* Real::multiplicacion(Numero* otro){
    Real* r = dynamic_cast<Real*>(otro);
    if (r) {
        return new Real(valor * r->valor);
    }
    return nullptr;
}

string Real::toString(){
    stringstream ss;
    ss << valor; 
    return ss.str(); 
}

Real::~Real(){}





Complejo::Complejo(double real,double imaginario) : real(real) , imaginario(imaginario){} 

Numero* Complejo::suma(Numero* otro){ //suma real con real e imaginario con imaginario
    Complejo* c = dynamic_cast<Complejo*>(otro);
    if (c) {
        return new Complejo(real + c->real, imaginario + c->imaginario);
    }
    return nullptr;
}

Numero* Complejo::resta(Numero* otro){//resta real con real e imaginario con imaginario
    Complejo* c = dynamic_cast<Complejo*>(otro);
    if (c) {
        return new Complejo(real - c->real, imaginario - c->imaginario);
    }
    return nullptr;
}

Numero* Complejo::multiplicacion(Numero* otro){ // la multiplicacion de complejos es de la forma (a + bi)(c + di)  = ac + bd + bci + adi
    Complejo* c = dynamic_cast<Complejo*>(otro); 
    if (c) {
        double resultReal = real * c->real  -  imaginario * c->imaginario;
        double resulImagi = real * c->imaginario + imaginario * c->real;
        return new Complejo(resultReal,resulImagi);
    }
    return nullptr;
}

string Complejo::toString(){
    stringstream ss;
    ss << real;

    if(imaginario >= 0){
        ss << " + " << imaginario << "i";
    }else{
        ss << " - " << -imaginario << "i";
    }

    return ss.str(); 
}

Complejo::~Complejo(){}