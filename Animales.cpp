#include <iostream>
#include <string>
/*
Nombre: Angel Guadalupe Arroyo Cruz
Funcion del codigo: El codigo crea dos clases derivadas de la clase animal, luego un objeto por cada clase derivada
y le agrega atributos generales de la clase animal y atributos especificos dependiendo de su clase derivada.
*/
using namespace std;

class Animal{
	public:
		string animal, color;
		int ojos, colas, patas;
		
		void ImprimirDatos(){
			cout << "El " << animal << " es de color " << color << endl;
			cout << "El " << animal << " tiene " << ojos << " ojos" << endl;
			cout << "El " << animal << " tiene " << colas << " cola" << endl;
			cout << "El " << animal << " tiene " << patas << " patas" << endl;
		}
};

class Mamifero : public Animal{
	public: 
	
		Crianza(){
			cout << "El " << animal << " nace de su madre" << endl;
		}
		
		AlimentacionCrias(){
			cout << "El " << animal << " alimenta a sus crias con leche materna" << endl;
		}
		
		Pelaje(){
			cout << "El " << animal << " tiene pelaje" << endl;
		}
		
		ImprimirMetodosEspecificos(){
			Crianza();
			AlimentacionCrias();
			Pelaje();
		}
};

class Oviparo : public Animal{
	public: 
		Crianza(){
			cout << "El " << animal << " nace de un huevo" << endl;
		}
		
		AlimentacionCrias(){
			cout << "El " << animal << " se alimenta por su cuenta al nacer" << endl;
		}
		
		Pelaje(){
			cout << "El " << animal << " no tiene pelaje" << endl;
		}
		
		ImprimirMetodosEspecificos(){
			Crianza();
			AlimentacionCrias();
			Pelaje();
		}
};

main(){
	Mamifero perro;
	Oviparo pinguino;

	perro.animal = "perro", perro.color = "Cafe", perro.ojos = 2, perro.colas = 1, perro.patas = 4;
	perro.ImprimirDatos();
	perro.ImprimirMetodosEspecificos();
	
	cout << endl;
	
	pinguino.animal = "pinguino", pinguino.color = "Blanco y Negro", pinguino.ojos = 2, pinguino.colas = 1, pinguino.patas = 2;
	pinguino.ImprimirDatos();
	pinguino.ImprimirMetodosEspecificos();
}
