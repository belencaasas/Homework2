#include "complejo.h"

Complejo::Complejo(double real,double imaginario) : real(real) , imaginario(imaginario){} 

unique_ptr<Numero> Complejo::suma(Numero&otro){ //suma real con real e imaginario con imaginario
    Complejo& c = dynamic_cast<Complejo&>(otro);
    return make_unique<Complejo>(real + c.real, imaginario + c.imaginario);
    
}

unique_ptr<Numero> Complejo::resta(Numero& otro){//resta real con real e imaginario con imaginario
    Complejo& c = dynamic_cast<Complejo&>(otro);
    return make_unique<Complejo>(real - c.real, imaginario - c.imaginario);
    
}

unique_ptr<Numero> Complejo::multiplicacion(Numero& otro){ // la multiplicacion de complejos es de la forma (a + bi)(c + di)  = ac + bd + bci + adi
    Complejo& c = dynamic_cast<Complejo&>(otro); 
        double resultReal = real * c.real  -  imaginario * c.imaginario;
        double resulImagi = real * c.imaginario + imaginario * c.real;
        return make_unique<Complejo>(resultReal,resulImagi);
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

