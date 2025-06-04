#include <iostream>
#include <fstream>
#include <string>
/* 
Nombre: Angel Guadalupe Arroyo Cruz
Funcion del codigo: Busca un archivo llamado archivo.txt y al encontrarlo
imprime en la consola el contenido de dicho archivo.
*/
using namespace std;

main(){
    ifstream archivo("archivo.txt");

    if (archivo.is_open()) {
        cout << "Archivo abierto correctamente.\nContenido:\n";

        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo." << endl;
    }
}

