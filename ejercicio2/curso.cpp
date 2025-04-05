#include "Curso.h"

Curso::Curso(const Curso& otro){
    for (size_t i =0; i < otro.estudiantes.size(); i++){
        estudiantes.push_back(make_unique<Estudiante>(*otro.estudiantes[i]));
    }
}

Curso::~Curso(){}  //destructor

void Curso::inscribir(unique_ptr<Estudiante> estudiante){
    if(estudiantes.size() < capacidadMaxEstu){
        estudiantes.push_back(move(estudiante));
        cout << "El estudiante " << estudiantes.back()->getNombre() << " esta inscripto" << endl;
    }else{ 
        cout << "El curso esta completo, no se puede inscribir al estudiante." << endl;
    }
}

void Curso::desinscribir(int legajo){
    for (size_t i = 0; i<estudiantes.size() ; i++){
        if(estudiantes[i]->getLegajo() == legajo){
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
    sort(estudiantes.begin(), estudiantes.end() , [](unique_ptr<Estudiante>& a, unique_ptr<Estudiante>& b){
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
            return estudiantes[i].get();
        }  
    }
    return nullptr;
}