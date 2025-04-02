#include "Curso.h"

int main(){
    Curso miCurso; 
    int opcion; 

    //menu de opciones que puede elegir el usuario
    while (opcion != 7){
    cout << endl;
    cout<< "\n------Opciones------\n";
    cout<< "1) Inscribir estudiante " << endl;
    cout<< "2) Desincribir estudiante" <<endl;
    cout<< "3) Ver si un estudiante esta inscripto" << endl;
    cout<< "4) Ver si el curso esta complejo" << endl; 
    cout<< "5) Imprimir lista de estudiantes" << endl;
    cout<< "6) Ingresar las notas de un alumno" << endl;
    cout<< "7) Salir \n" <<endl;
    cout<< "Ingrese su opcion: ";
    cin >> opcion; 
    cout << endl;

    //manejo de parametros mal ingresados
    while(opcion > 7 || opcion < 1 || cin.fail()) {
        cout << "El parametro ingresado es incorrecto , vuele a itentar (1-7): ";
        cin.clear(); // limpia el cin
        cin.ignore(1000,'\n'); 
        cin >> opcion;
    } 

    switch (opcion){
        case 1: {
            string nombre; 
            int legajo; 
            cout << "Ingrese el nombre completo del estudiante: "; 
            cin.ignore(); 
            getline(cin,nombre);
            cout << "Ingrese el legajo del estudiante: "; 
            cin >> legajo; 
            auto* estudiante = new Estudiante(nombre,legajo);
            miCurso.inscribir(estudiante);
            break; 
        }

        case 2: {
            int legajo;
            cout << "Ingrese el legajo del estudiante que quiere desinscribir: " ; 
            cin >> legajo;
            miCurso.desinscribir(legajo);
            break;

        }

        case 3: {
            int legajo;
            cout << "Ingrese el legajo: ";
            cin >> legajo;
            if(miCurso.estaInscripto(legajo)){
                cout << "El estudiante esta inscripto en el curso. ";
            } else{ 
                cout << "El estudiante no esta inscripto en el curso.";
            }
            break;
        }

        case 4: {
            if(miCurso.estaCompleto()){
                cout<< "El curso esta completo. " << endl; 
            }else{ 
                cout << "El curso no esta completo. " << endl; 
            }
            break;
        }

        case 5: {
            miCurso.imprimirEstudiantes();
            break;
        }

        case 6:{
            int legajo;
            cout << "Ingrese el legajo del alumno al que quiere ingresar sus nota promedio: "; 
            cin >> legajo; 

            Estudiante* estudiante = miCurso.buscarEstudiante(legajo);
            if(estudiante != nullptr){
                double nota; 
                cout << "Ingrese la nota final del estudiante: " ; 
                cin >> nota; 
                estudiante->agregarNota(nota);
                cout << "Nota ingresada." << endl;
            } else {
                cout<< "El estudiante no fue encontrado." << endl;
            }
            break;

        }

        case 7: {
            cout << "Saliendo.." << endl;
            break; 
        }

        default: { 
            cout << "Opcion no valida, intente nuevamente. ";
            break;
        }
    } 
    }
    return 0; 

}