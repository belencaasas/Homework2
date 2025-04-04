#include "entero.h"

Entero::Entero(int valor) : valor(valor){}   //define el constructor de la clase entero

unique_ptr<Numero> Entero::suma(Numero& otro) {  
    Entero& e= static_cast<Entero&>(otro); //un cast dinamico que convierte el puntero a un de tipo entero  
    return make_unique<Entero>(valor + e.valor);
}

unique_ptr<Numero> Entero::resta(Numero& otro){
    Entero& e = static_cast<Entero&>(otro);
    return make_unique<Entero>(valor - e.valor);
    
}

unique_ptr<Numero> Entero::multiplicacion(Numero& otro){
    Entero& e = static_cast<Entero&>(otro);
    return make_unique<Entero>(valor * e.valor);
    
}

string Entero::toString(){
    stringstream ss;
    ss << valor; 
    return ss.str(); 
}

