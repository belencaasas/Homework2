#pragma once
#include <memory>
#include <string>
#include <sstream>
using namespace std;


class Numero{
    public: 
        virtual unique_ptr<Numero> suma(Numero& otro) = 0;
        virtual unique_ptr<Numero> resta(Numero& otro) = 0;
        virtual unique_ptr<Numero> multiplicacion(Numero& otro) = 0;
        virtual string toString() = 0;
        virtual ~Numero() = default;
        
};

