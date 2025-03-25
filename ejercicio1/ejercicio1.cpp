#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;
//holaaa 

class tiempo //clase que definimos 
{
private:
    int horas;
    int minutos;
    int segundos;
    string abreviatura; 

    bool tiempoEsValido(int h, int m, int s, const string& abrev){ //manejo de valores ingresados 
        if (h < 0 || h > 12 || m < 0 || m >= 60 || s < 0 || s >= 60)
            return false; 
        if (abrev != "a.m." && abrev != "p.m.")
            return false; 
        return true; 
    }

public:
    //los constructores 
    tiempo() : horas(0), minutos(0), segundos(0), abreviatura("a.m"){} //constructor por defecto 

    tiempo(int h): tiempo(){
        if(tiempoEsValido(h,0,0,"a.m."))
            horas = h;
    } 

    tiempo(int h, int m): tiempo(){
        if(tiempoEsValido(h,m,0,"a.m.")){
            horas = h;
            minutos = m; 
        }
    }

    tiempo(int h , int m, int s): tiempo(){
        if(tiempoEsValido(h,m,s,"a.m.")){
            horas = h; 
            minutos = m;
            segundos = s; 
        }
    }

    tiempo(int h , int m  , int s, const string& a ): tiempo(){
        if(tiempoEsValido(h,m,s,a)){
            horas = h;
            minutos = m;
            segundos = s; 
            abreviatura = a;
        }
    } 

    //funciones que nos permiten ingresar los parametros 

    void Mhoras(int h){ //manejo de horas 
        if (h >= 0 && h <= 12)
            horas = h;
        else
            cout << "La hora ingresada es invalida, intente nuevamente. " << endl; 
    } 

    void Mmintuos(int m){
        if (m >= 0 && m < 60)
            minutos = m;
        else 
            cout << "Los minutos ingresados son invalidos, intente nuevamente. " << endl; 
    }

    void Msegundos(int s){
        if(s >= 0 && s < 60)
            segundos = s; 
        else 
            cout << "Los segundos ingresados son invalidos, intente nuevamente.  " << endl;
    }

    void Mabreviatura(const string& a){
        if( a == "a.m." || a == "p.m.")
            abreviatura = a;
        else 
            cout << "El periodo ingresado es invalido, utilice 'a.m.' o 'p.m.' " << endl; 
    }

    int gethoras() const{return horas;}
    int getminutos() const{return minutos;}
    int getsegundos() const{return segundos;}
    string getabreviaturas() const{return abreviatura;}

    void mostrarTiempo() const{ //el uso de la libreria iomanip
        cout << setw(2) << setfill('0') << horas << "h, "
             << setw(2) << setfill('0') << minutos << "m, "
             << setw(2) << setfill('0') << segundos << "s, "
             << abreviatura << endl;
    } 

    void mostrarTodoElTiempo() const{
        int horasajustadas = horas; // maneja las horas para que aparezca 20hs o si son las 12 de la noche 00hs
        if (abreviatura == "p.m." && horas != 12) {
            horasajustadas = horas + 12;
        }else if (abreviatura == "a.m." && horas == 12){
            horasajustadas = 0;
        }
        cout << setw(2) << setfill('0') << horasajustadas << ":"  // si el valor tiene menos de 2 digitos rellena con 0
             << setw(2) << setfill('0') << minutos << ":"
             << setw(2) << setfill('0') << segundos << "" << endl;

    }
};

int main(){
    int h,s,m; 
    string a; 
    tiempo t1; 
    cout << "Ingrese la hora (0-12): "; 
    cin >> h; 
    cout << "Ingrese los minutos (0-59): ";
    cin >> m;
    cout << "Ingrese los segundos (0-59): ";
    cin >> s; 
    cout << "Ingrese el momento del dia (a.m. / p.m.): ";
    cin >> a; 

    tiempo t2(h,m,s,a);
    cout <<"Formato 12 horas: ";
    t2.mostrarTiempo();
    cout << "Formato 24 horas: ";
    t2.mostrarTodoElTiempo();

    return 0;
}
