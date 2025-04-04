#include "real.h"

Real::Real(double valor) : valor(valor){}   
                                             

unique_ptr<Numero> Real::suma(Numero& otro) {  
    Real& r= static_cast<Real&>(otro); 
    return make_unique<Real>(valor + r.valor);
}

unique_ptr<Numero> Real::resta(Numero& otro){
    Real& r = static_cast<Real&>(otro);
    return make_unique<Real>(valor - r.valor);
    
}

unique_ptr<Numero> Real::multiplicacion(Numero& otro){
    Real& r = static_cast<Real&>(otro);
return make_unique<Real>(valor * r.valor);
    
}

string Real::toString(){
    stringstream ss;
    ss << valor; 
    return ss.str(); 
}

