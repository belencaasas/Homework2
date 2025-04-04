#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Estudiante{
    private: 
        string nombreCompleto;
        int legajo;
        vector<pair<string,double>> cursosConNotas; 
        vector<double> notas;

    public: 
        Estudiante(string nombre,int legajo);
        string getNombre();
        int getLegajo();
        void agregarNota(double nota);
        double calcularPromedio();
        bool operator<(const Estudiante& otro);
        friend ostream& operator<<(ostream& variable, Estudiante estudiante);  
};
