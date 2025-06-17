/*
Nombre: Angel Guadalupe Arroyo Cruz

Este programa resuelve autom�ticamente un laberinto cargado desde un archivo
de texto usando el algoritmo DFS (Depth-First Search) con backtracking.

Funcionamiento
Carga un laberinto desde "laberinto.txt"
Encuentra autom�ticamente el punto de inicio y final
Usa DFS para explorar todos los caminos posibles
Cuando encuentra un callej�n sin salida, retrocede (backtracking)
Muestra la soluci�n encontrada y opcionalmente una animaci�n
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class LaberintoAutomatico {
private:
    vector<string> mapa;
    vector<vector<bool> > visitado;
    vector<pair<int, int> > solucion;
    int filas, columnas;
    int inicioX, inicioY;
    int finX, finY;
    
public:
    // Inicializa el laberinto cargando el archivo y configurando los puntos de inicio y fin
    LaberintoAutomatico(string archivo) {
        cargarLaberinto(archivo);
        encontrarInicio();
        encontrarFin();
        inicializarVisitado();
    }
    
    // Funci�n para cargar el laberinto desde un archivo de texto
    void cargarLaberinto(string archivo) {
        ifstream file(archivo.c_str());
        string linea;
        
        if (!file.is_open()) {
            cout << "Error: No se pudo abrir el archivo " << archivo << endl;
            return;
        }
        
        while (getline(file, linea)) {
            mapa.push_back(linea);
        }
        
        file.close();
        filas = mapa.size();
        columnas = mapa[0].length();
    }
    
    // Funci�n para encontrar el punto de inicio (primer espacio disponible desde arriba-izquierda)
    void encontrarInicio() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (mapa[i][j] == ' ') {
                    inicioX = j;
                    inicioY = i;
                    return;
                }
            }
        }
    }
    
    // Funci�n para encontrar el punto final (�ltimo espacio disponible desde abajo-derecha)
    void encontrarFin() {
        for (int i = filas - 1; i >= 0; i--) {
            for (int j = columnas - 1; j >= 0; j--) {
                if (mapa[i][j] == ' ') {
                    finX = j;
                    finY = i;
                    return;
                }
            }
        }
    }
    
    // Funci�n para inicializar la matriz de posiciones visitadas (todas en false al inicio)
    void inicializarVisitado() {
        visitado.resize(filas);
        for (int i = 0; i < filas; i++) {
            visitado[i].resize(columnas, false);
        }
    }
    
    // Funci�n para verificar si una posici�n es v�lida para moverse
    // Verifica l�mites, que sea espacio libre y que no haya sido visitada
    bool esValido(int x, int y) {
        return (x >= 0 && x < columnas && y >= 0 && y < filas && 
                mapa[y][x] == ' ' && !visitado[y][x]);
    }
    
    bool resolverDFS(int x, int y) {
        // Si llegamos al destino
        if (x == finX && y == finY) {
            solucion.push_back(make_pair(x, y));
            return true;
        }
        
        // Marcar como visitado
        visitado[y][x] = true;
        solucion.push_back(make_pair(x, y));
        
        // Direcciones: derecha, abajo, izquierda, arriba
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        // Probar cada direcci�n
        for (int i = 0; i < 4; i++) {
            int nuevoX = x + dx[i];
            int nuevoY = y + dy[i];
            
            if (esValido(nuevoX, nuevoY)) {
                if (resolverDFS(nuevoX, nuevoY)) {
                    return true;
                }
            }
        }
        
        // Backtrack: quitar de la soluci�n si no lleva al destino
        solucion.pop_back();
        return false;
    }
    
    void mostrarLaberintoConSolucion() {
        // Crear una copia del mapa para mostrar la soluci�n
        vector<string> mapaConSolucion = mapa;
        
        // Marcar el camino de la soluci�n
        for (int i = 0; i < solucion.size(); i++) {
            int x = solucion[i].first;
            int y = solucion[i].second;
            
            if (x == inicioX && y == inicioY) {
                mapaConSolucion[y][x] = 'S'; // Start
            } else if (x == finX && y == finY) {
                mapaConSolucion[y][x] = 'F'; // Finish
            } else {
                mapaConSolucion[y][x] = '*'; // Camino de soluci�n
            }
        }
        
        // Mostrar el laberinto con la soluci�n
        for (int i = 0; i < filas; i++) {
            cout << mapaConSolucion[i] << endl;
        }
    }
      
    // Funci�n para mostrar una animaci�n paso a paso de c�mo se resuelve el laberinto
    void animarSolucion() {
        cout << "\n=== ANIMACION DE LA SOLUCION ===" << endl;
        cout << "Presiona Enter para ver la animacion..." << endl;
        cin.get();
        
        for (int paso = 0; paso <= solucion.size(); paso++) {
            system("cls");
            
            vector<string> mapaTemp = mapa;
            
            // Mostrar el camino recorrido hasta ahora
            for (int i = 0; i < paso && i < solucion.size(); i++) {
                int x = solucion[i].first;
                int y = solucion[i].second;
                
                if (i == 0) {
                    mapaTemp[y][x] = 'S';
                } else if (i == solucion.size() - 1 && paso == solucion.size()) {
                    mapaTemp[y][x] = 'F';
                } else {
                    mapaTemp[y][x] = '*';
                }
            }
            
            // Mostrar posici�n actual
            if (paso < solucion.size()) {
                int x = solucion[paso].first;
                int y = solucion[paso].second;
                if (paso > 0) {
                    mapaTemp[y][x] = 'X'; // Posici�n actual
                }
            }
            
            // Mostrar el mapa
            for (int i = 0; i < filas; i++) {
                cout << mapaTemp[i] << endl;
            }
            
            // Mostramos informaci�n del paso actual
            cout << "\nPaso: " << paso << "/" << solucion.size() << endl;
            if (paso < solucion.size()) {
                cout << "Posicion actual: (" << solucion[paso].first 
                     << ", " << solucion[paso].second << ")" << endl;
            }
            
            Sleep(100); 
        }
        
        cout << "\nLaberinto resuelto" << endl;
    }
    
    void resolver() {
        cout << "Resolviendo laberinto..." << endl;

        if (resolverDFS(inicioX, inicioY)) {
            cout << "\nSOLUCION ENCONTRADA" << endl;
            mostrarLaberintoConSolucion();
            cout << "\nQuieres ver la animacion? (s/n): ";
            char respuesta;
            cin >> respuesta;
            
            if (respuesta == 's' || respuesta == 'S') {
                animarSolucion();
            }
        } else {
            cout << "\nNo se encontro solucion para este laberinto." << endl;
        }
    }
};

int main() {
    LaberintoAutomatico resolvedor("laberinto.txt");
    resolvedor.resolver();
    
    cout << "\nPresiona Enter para salir...";
    cin.get();
    
    return 0;
}
