#include <iostream>
#include <string> 
#include <iomanip>

#include "tiempo.h"
using namespace std;

// funcion que maneja si un valor ingresado es valido o no, si las horas / minutos / segundos no estan dentro del rango horario salta un aviso.
bool Tiempo::tiempoEsValido(int h, int m, int s, string abrev){ 
    if (h < 0 || h > 12 ){
        while (h < 0 || h > 12){
            cout << "La hora ingresada es invalida" << endl;
            cout << "ingrese la hora devuelta: ";
            cin >> h;
        }
    } 

    if (m < 0 || m > 59 ){
        while (m < 0 || m > 59){
            cout << "Los minutos ingresados son invalidos" << endl;
            cout << "ingrese los minutos devuelta: ";
            cin >> m;
        }
    } 

    if (s < 0 || s > 59 ){
        while (s < 0 || s > 59){
            cout << "Los segundos ingresados son invalidos" << endl;
            cout << "ingrese los segundos devuelta: ";
            cin >> s;
        }
    } 

    if (abrev != "a.m." && abrev != "p.m.")
        while (abrev != "a.m." && abrev != "p.m."){
            cout << "Los parametros ingresados son invalidos" << endl;
            cout << "Ingrese los parametros devuelta: ";
            cin >> abrev;
        }
         

    horas = h; 
    minutos = m;
    segundos = s; 
    abreviatura = abrev;
    return true; 
}


Tiempo::Tiempo(){
    horas = 0;
    minutos = 0;
    segundos = 0;
    string periodo ="a.m.";
}

Tiempo::Tiempo(int h){
    tiempoEsValido(h,0,0,"a.m.");
} 

Tiempo::Tiempo(int h, int m) {
    tiempoEsValido(h,m,0,"a.m.");
}

Tiempo::Tiempo(int h , int m, int s) {
    tiempoEsValido(h,m,s,"a.m.");
    
}

Tiempo::Tiempo(int h , int m  , int s, string a ) {
    tiempoEsValido(h,m,s,a);
} 

    //funciones que nos permiten ingresar los parametros 

    void Tiempo::sethoras(int h){ 
        if (h >= 0 && h <= 12)
            horas = h;
        else
            cout << "La hora ingresada es invalida, intente nuevamente. " << endl; 
    } 

    void Tiempo::setmintuos(int m){ 
        if (m >= 0 && m < 60)
            minutos = m;
        else 
            cout << "Los minutos ingresados son invalidos, intente nuevamente. " << endl; 
    }

    void Tiempo::setsegundos(int s){
        if(s >= 0 && s < 60)
            segundos = s; 
        else 
            cout << "Los segundos ingresados son invalidos, intente nuevamente.  " << endl;
    }

    void Tiempo::setabreviatura(const string& a){
        if( a == "a.m." || a == "p.m.")
            abreviatura = a;
        else 
            cout << "El periodo ingresado es invalido, utilice 'a.m.' o 'p.m.' " << endl; 
    }

    int Tiempo::gethoras() {return horas;}
    int Tiempo::getminutos() {return minutos;}
    int Tiempo::getsegundos() {return segundos;}
    string Tiempo::getabreviaturas() {return abreviatura;}

    void Tiempo::mostrarTiempo() { //el uso de la libreria iomanip
        cout << setw(2) << setfill('0') << horas << "h, "
             << setw(2) << setfill('0') << minutos << "m, "
             << setw(2) << setfill('0') << segundos << "s, "
             << abreviatura << endl;
    } 

    void Tiempo::mostrarTodoElTiempo() {
        int horasajustadas = horas; // maneja las horas para que aparezca en formato 24hs
        if (abreviatura == "p.m." && horas != 12) {
            horasajustadas = horas + 12;
        }else if (abreviatura == "a.m." && horas == 12){
            horasajustadas = 0;
        }
        cout << setw(2) << setfill('0') << horasajustadas << ":"  
             << setw(2) << setfill('0') << minutos << ":"
             << setw(2) << setfill('0') << segundos << "" << endl;

    }
