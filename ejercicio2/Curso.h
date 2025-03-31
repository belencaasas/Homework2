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
        vector<pair<string,double>> cursosConNotas; //cursos con su nota final
        vector<double> notas;

    public: 
        Estudiante(string nombre,int legajo);
        string getNombre();
        int getLegajo();
        void agregarNota(double nota);
        double calcularPromedio();
        bool operator<(const Estudiante& otro);
        friend ostream& operator<<(ostream& variable, Estudiante estudiante);  //?????
};

class Curso{
    private: 
        vector<Estudiante*> estudiantes;
        size_t capacidadMaxEstu = 20;  //un curso como maximo puede haber 20 estudiantes
    
    public: 
        Curso() {}
        Curso(const Curso& otro);  //constructor para la copia ????
        /*Se realiza una copia profunda porque el vector `estudiantes` contiene punteros a objetos.
        Si se hiciera una copia superficial, el vector copiado y el original compartirían los mismos
        punteros, lo que podría generar problemas de doble eliminación de memoria (double deletion)
        al destruir uno de los objetos `Curso`.
        Al usar `new` para duplicar los objetos `Estudiante`, garantizamos que cada instancia
        del objeto `Curso` tenga su propio conjunto de objetos independientes.
        Esto asegura la independencia entre el objeto copiado y el original.*/
        ~Curso();
        void inscribir(Estudiante* estudiante);
        void desinscribir(int legajo);
        bool estaInscripto(int legajo);
        bool estaCompleto();
        void imprimirEstudiantes();
        Estudiante* buscarEstudiante(int legajo);

};