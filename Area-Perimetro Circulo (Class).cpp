#include <iostream>
#include <String>
/*
Nombre: Angel Guadalupe Arroyo Cruz
Funcion del codigo: Se crea un clase circulo con las funciones de calcular el area y el perimetro y luego pide al
usuario que ingrese el radio, este valor se guarda en la propiedad radio de un objeto de la clase circulo y calcula
su area o su perimetro dependiendo de lo que desee el usuario.
*/
using namespace std;

class Circulo{
	private:
		float pi = 3.1416;
	public: 
		float radio;
		
	float Area(){
		return pi * (radio * radio);
	}
	float Perimetro(){
		return 2 * pi * radio;
	}
};

main(){
	Circulo circulo;
	string opcion;
	float radio;
	
	cout << "Ingresa el radio del circulo: ";
	cin >> circulo.radio;
	
	while(opcion != "s" || opcion != "S"){
		cout << endl << "Selecciona que deseas calcular: " << endl << "(A)Area" << endl << "(P)Perimetro" << endl << "(S)Salir" << endl;
		cin >> opcion;
	
		if(opcion == "a" || opcion == "A"){
			cout << "El area del circulo es: " << circulo.Area() << endl;
		}
		else if(opcion == "p" || opcion == "P"){
			cout << "El perimetro del circulo es: " << circulo.Perimetro() << endl;
		}	
	}
}
