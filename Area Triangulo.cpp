#include <iostream>
/*
Nombre: Angel Guadalupe Arroyo Cruz
Funcion del codigo: El codigo pide al usuario ingresar base y altura de un triangulo y cuando le das los valores te da el 
resultado del area, tambien pide que si quieres volver a calcular un area o no
*/
using namespace std;

main(){
	float base, altura, area;
	char opcion;
	
	while(opcion != 'n'){
		cout << "Ingresa la base del triangulo: ";
		cin >> base;
	
		cout << "Ingresa la altura del triangulo: ";
		cin >> altura;
		
		area = base * altura / 2;
		cout << "El area del triangulo es: " << area << endl;
		
		cout << "Quieres volver a calcular el area de un triangulo? (y)yes (n)no: ";
		cin >> opcion;
	}	
}



