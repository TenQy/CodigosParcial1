#include <iostream>
#include <string>
/*
Nombre: Angel Guadalupe Arroyo Cruz
Funcion del codigo: Se crea una clase Deporte con dos clases derivadas dependiendo de 
con que parte del cuerpo se juegue ese deporte, luego se crea un objeto por cada clase
derivada a la cual se le asignan sus correspondientes propiedades tanto de la clase
deporte como las propiedades especificas de la clase derivada a la que pertenecen.
*/
using namespace std;

class Deporte {
public:
    string nombre, tipoPelota;
    int jugadores, duracion;

    void ImprimirDatos() {
        cout << "Deporte: " << nombre << endl;
        cout << "Tipo de pelota: " << tipoPelota << endl;
        cout << "Cantidad de jugadores: " << jugadores << endl;
        cout << "Duracion del juego: " << duracion << " minutos" << endl;
    }
};

class Pierna : public Deporte {
public:
    void ParteDelCuerpo() {
        cout << nombre << " se juega principalmente con los pies." << endl;
    }

    void Equipamiento() {
        cout << "Equipamiento necesario: zapatillas deportivas, canilleras." << endl;
    }

    void Superficie() {
        cout << "Se juega generalmente en superficies como cesped artificial o madera." << endl;
    }

    void ImprimirMetodosEspecificos() {
        ParteDelCuerpo();
        Equipamiento();
        Superficie();
    }
};

class Brazo : public Deporte {
public:
    void ParteDelCuerpo() {
        cout << nombre << " se juega principalmente con los brazos." << endl;
    }

    void Equipamiento() {
        cout << "Equipamiento necesario: rodilleras, camiseta deportiva." << endl;
    }

    void Superficie() {
        cout << "Se juega comunmente en canchas de madera o arena." << endl;
    }

    void ImprimirMetodosEspecificos() {
        ParteDelCuerpo();
        Equipamiento();
        Superficie();
    }
};

int main() {
    Pierna futbolSala;
    Brazo voleibol;

    futbolSala.nombre = "Futbol Sala";
    futbolSala.tipoPelota = "Pelota de futbol tamaño reducido";
    futbolSala.jugadores = 5;
    futbolSala.duracion = 40;

    voleibol.nombre = "Voleibol";
    voleibol.tipoPelota = "Balon de voleibol";
    voleibol.jugadores = 6;
    voleibol.duracion = 60;

    futbolSala.ImprimirDatos();
    futbolSala.ImprimirMetodosEspecificos();

    cout << endl;

    voleibol.ImprimirDatos();
    voleibol.ImprimirMetodosEspecificos();
}
