#pragma once

#include <string> 
using namespace std;

class Tiempo //clase que definimos 
{
private:
    int horas;
    int minutos;
    int segundos;
    string abreviatura; 

    bool tiempoEsValido(int h, int m, int s,string abrev);

public:
    //los constructores 
    Tiempo();//constructor por defecto 
    Tiempo(int h);
    Tiempo(int h, int m);
    Tiempo(int h , int m, int s);
    Tiempo(int h , int m  , int s, string a );

    void sethoras(int h);
    void setmintuos(int m);
    void setsegundos(int s);
    void setabreviatura(const string& a);

    int gethoras();
    int getminutos(); 
    int getsegundos(); 
    string getabreviaturas();

    void mostrarTiempo();
    void mostrarTodoElTiempo();

}; 