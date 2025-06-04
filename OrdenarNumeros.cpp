#include <iostream>
#include <algorithm>
/*
Nombre: Angel Guadalupe Arroyo Cruz
Funcion del codigo: Se crea un arreglo con una capacidad de 10 numeros, luego pide al usuario
que ingrese esos numeros hasta llenar el arreglo y despues de esto se utiliza la funcion sort
para ordenar de menor a mayor los numeros en el arreglo.
*/
using namespace std;

main(){
	int size = 10;
	int arreglo[size];
	
	cout << "Ingresa los datos del arreglo" << endl;
	
	for(int i = 0; i < size; i++){
		cin >> arreglo[i];
	}
	
	sort(arreglo, arreglo + size);
	
	for(int i = 0; i < size; i++){
		cout << arreglo[i] << " ";
	}
}
