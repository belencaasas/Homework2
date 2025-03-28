#include "tiempo.h"
#include <iostream>
using namespace std;


int main(){
    int opcion;
    Tiempo tiempo; 
    cout << "----OPCIONES-----"<< endl;
    cout << "1) Incializacion por default " << endl;
    cout << "2) Inicializacion con horas " << endl;
    cout << "3) Inicializacion con horas y minutos " << endl;
    cout << "4) Inicializacion con horas, minutos y segundos " << endl;
    cout << "5) Inicializacion con horas, minutos, segundos y periodo " << endl;
    cout << "Opcion =  ";
    cin >> opcion;

        
    while(opcion > 5 || opcion < 1 || cin.fail()) {
        cout << "El parametro ingresado es incorrecto , vuele a itentar (1-5): ";
        cin.clear(); // limpia el cin
        cin.ignore(10000,'\n'); //
        cin >> opcion;
    }  

    switch(opcion){
        case 1: {
            tiempo = Tiempo();
            tiempo.mostrarTiempo();
            break;
            }

        case 2: {
            int h;
            cout << " Elije la hora (0-12): " ; 
            cin >> h; 
            tiempo = Tiempo(h);
            tiempo.mostrarTiempo();
            break;
            }

        case 3: {
            int h;
            int m;
            cout << "Elije la hora (0-12): " ;
            cin >> h ; 
            cout << "Elije los minutos (0-59): ";
            cin >> m;
            tiempo = Tiempo(h,m);
            tiempo.mostrarTiempo();
            break; 
            }
        
        case 4: {
            int h;
            int m;
            int s;
            cout << "Elije la hora (0-12): " ;
            cin >> h ; 
            cout << "Elije los minutos (0-59): ";
            cin >> m;
            cout << "Elije los segundos (0-59): " ;
            cin >> s;
            tiempo = Tiempo (h,m,s);
            tiempo.mostrarTiempo();
            break;
            }
        
        case 5: {
            int h;
            int m;
            int s;
            string a;
            cout << "Elije la hora (0-12): " ;
            cin >> h ; 
            cout << "Elije los minutos (0-59): ";
            cin >> m;
            cout << "Elije los segundos (0-59): " ;
            cin >> s;
            cout << "Elije el periodo 'a.m.' o 'p.m.' : " ;
            cin >> a; 
            tiempo = Tiempo(h,m,s,a);
            tiempo.mostrarTiempo();
            break; 
            }
        
        default:
            cout << "Opcion no valida " << endl;   //deberia manejar este error??
            return 0;
            

    }
    int subOpciones=0;
    while (subOpciones != 11){
        cout << endl;
        cout << "1) Cambiar la hora: " << endl;
        cout << "2) Ver la hora: " << endl; //poner como queda 
        cout << "3) Cambiar los minutos: "<< endl;
        cout << "4) Ver los minutos: "<< endl;
        cout << "5) Cambiar los segundos: "<< endl;
        cout << "6) Ver los segundos: "<< endl;
        cout << "7) Cambiar el periodo: "<< endl;
        cout << "8) Ver el periodo: "<< endl;  //CON EL DE 12HS ESTA? 
        cout << "9) Ver hora en formato 24hs: " << endl;
        cout << "10) Ver la hora en formato 12hs: " << endl;
        cout << "11) salir"<< endl;
        cin >> subOpciones;
        cout << endl;

        if (subOpciones > 11 || subOpciones < 1 || cin.fail()){ //fail manejo de stirng 
            cout << "El parametro ingresado es incorrecto , vuele a itentar (1-10): ";
            continue;    
        }

        switch (subOpciones){
            case 1: {
                int h; 
                cout << "Ingrese la nueva hora (0-12): ";
                cin >> h ;   
                tiempo.sethoras(h);
                break;
            }

            case 2: {
                cout << "Las hora es: " << tiempo.gethoras() << endl;
                break; 
            }

            case 3: {
                int m; 
                cout << "Ingrese los nuevos minutos (0-59): " ;
                cin >> m; 
                tiempo.setmintuos(m);
                break;
            }

            case 4:{
                cout << "Los minutos son: " << tiempo.getminutos() << endl;
                break;
            }

            case 5: {
                int s; 
                cout << "Ingrese los nuevos segundos (0-59): " ;
                cin >> s; 
                tiempo.setsegundos(s);
                break;
            }

            case 6: {
                cout << "Los segundos son: " << tiempo.getsegundos() << endl;
                break; 
            } 

            case 7: {
                string a; 
                cout << "Ingrese el nuevo periodo (a.m.  o  p.m. ): " ;
                cin >> a;   
                tiempo.setabreviatura(a);
                break;
            }

            case 8: {
                cout << "El periodo es: " << tiempo.getabreviaturas() << endl; 
                break;
            }

            case 9: {
                tiempo.mostrarTodoElTiempo();
                break;
            }

            case 10: {
                tiempo.mostrarTiempo();
                break; 
            }

            case 11: {
                cout << "Saliendo. " << endl;
                break;
            }

            default:
                cout << "La opcion no es valida. " << endl;
        
        }
    }
    return 0; 
}