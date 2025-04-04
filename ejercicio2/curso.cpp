#include "Curso.h"

Curso::Curso(const Curso& otro){
    for (size_t i =0; i < otro.estudiantes.size(); i++){
        Estudiante* nuevoEstudiante = new Estudiante(*otro.estudiantes[i]);
        estudiantes.push_back(nuevoEstudiante);
    }
}

Curso::~Curso(){  //destructor
    for(size_t i=0 ; i < estudiantes.size(); i++){
        delete estudiantes[i];
    }
}

void Curso::inscribir(Estudiante* estudiante){
    if(estudiantes.size() < capacidadMaxEstu){
        estudiantes.push_back(estudiante);
    }else{ 
        cout << "El curso esta completo, no se puede inscribir al estudiante." << endl;
    }
}

void Curso::desinscribir(int legajo){
    for (size_t i = 0; i<estudiantes.size() ; i++){
        if(estudiantes[i]->getLegajo() == legajo){
            delete estudiantes[i];
            estudiantes.erase(estudiantes.begin() + i);
            cout << "El estudiante con legajo " << legajo << " se desinscribio correctamente." << endl;
            return;
        }
    }
    cout << "El estudiante con legajo " << legajo << " no esra inscripto en el curso." << endl;

}

bool Curso::estaInscripto(int legajo){
    for (size_t i =0 ; i < estudiantes.size(); i++){
        if(estudiantes[i]->getLegajo() == legajo){
            return true;
        }
    }
    return false;
}

void Curso::imprimirEstudiantes(){
    sort(estudiantes.begin(), estudiantes.end() , [](Estudiante* a , Estudiante* b){
        return *a < *b;
    });
    for (size_t i =0 ; i<estudiantes.size(); i++){
        cout << *estudiantes[i] << endl;
    }
} 

bool Curso::estaCompleto(){
    return estudiantes.size() >= capacidadMaxEstu;
}

Estudiante* Curso::buscarEstudiante(int legajo){
    for(size_t i=0 ; i < estudiantes.size(); i++){
        if(estudiantes[i]->getLegajo()==legajo){
            return estudiantes[i];
        }  
    }
    return nullptr;
}