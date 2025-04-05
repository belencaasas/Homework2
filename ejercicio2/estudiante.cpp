#include "Estudiante.h"

Estudiante::Estudiante(string nombre, int legajo) : nombreCompleto(nombre) , legajo(legajo){}

string Estudiante::getNombre(){
    return nombreCompleto;
}

int Estudiante::getLegajo(){
    return legajo;
}

void Estudiante::agregarNota(double nota){
    notas.push_back(nota);
}

double Estudiante::calcularPromedio(){
    double sumaNotas = 0; 
    size_t cantidadCurso = notas.size();

    for (size_t i =0 ; i < cantidadCurso ; i++){
        sumaNotas += notas[i];
    }
    if (cantidadCurso > 0){
        return sumaNotas / cantidadCurso;
    }else{
        return 0; 
    } 
}


//sobrecarga del operador < para comparar estudiantes por nombre
bool Estudiante::operator<(const Estudiante& otro){
    return nombreCompleto < otro.nombreCompleto;
}

ostream& operator<<(ostream& variable, Estudiante estudiante){
    variable << "Nombre: " << estudiante.nombreCompleto << ", Legajo:" << estudiante.legajo << ", Promedio:" << estudiante.calcularPromedio();
    return variable;
}

