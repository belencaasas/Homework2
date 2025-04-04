#include "Estudiante.h"


class Curso{
    private: 
        vector<Estudiante*> estudiantes;
        size_t capacidadMaxEstu = 20;  //un curso como maximo puede haber 20 estudiantes
    
    public: 
        Curso() {}
        Curso(const Curso& otro);  
        /*Se realiza una copia profunda porque el vector "estudiantes" contiene punteros a objetos.
        Si se hiciera una copia superficial, el vector copiado y el original compartirían los mismos
        punteros, lo que podría generar problemas.*/
        ~Curso();
        void inscribir(Estudiante* estudiante);
        void desinscribir(int legajo);
        bool estaInscripto(int legajo);
        bool estaCompleto();
        void imprimirEstudiantes();
        Estudiante* buscarEstudiante(int legajo);

};

/*  c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?
        La relacion que existe entre ambas es de Agregacion ya que mantienen una relacion pero sin una dependencia tota. Si uno de los 
        dos no existiera a el otro no le afectaria, podria seguir existiendo sin problema*/