#include "Estudiante.h"
#include <memory>


class Curso{
    private: 
        vector<unique_ptr<Estudiante>> estudiantes;
        size_t capacidadMaxEstu = 20;  //un curso como maximo puede haber 20 estudiantes
    
    public: 
        Curso() {} //nuevo
        Curso(const Curso& otro);  
        /*Se realiza una copia profunda porque el vector "estudiantes" contiene punteros a objetos.
          El deep copy dara como resultado un nuevo objeto con la informacion allocada en una posicion distinte, esto evita que 
          al querer eliminar algo no se eliminen ambas cosas, se borrara unicamente la copia .*/
        ~Curso();
        string getNombreCurso(); //nuevo
        void inscribir(unique_ptr<Estudiante> estudiante);
        void desinscribir(int legajo);
        bool estaInscripto(int legajo);
        bool estaCompleto();
        void imprimirEstudiantes();
        Estudiante* buscarEstudiante(int legajo);

};

/*  c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?*/
       /* La relacion que existe entre ambas es de Agregacion ya que mantienen una relacion pero sin una dependencia tota. Si uno de los 
        dos no existiera a el otro no le afectaria, podria seguir existiendo sin problema*/