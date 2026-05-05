#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// Cada hilo procesa un rango especifico del vector
void procesar(vector<int>& datos, int inicio, int fin, string nombre) {
    for(int i = inicio; i < fin; i++) {
        datos[i] = datos[i] * 2; // Operacion simple de ejemplo
        cout << nombre << " proceso indice " << i << " = " << datos[i] << endl;
    }
}

int main() {
    vector<int> datos = {1,2,3,4,5,6,7,8,9,10};
    int mitad = datos.size() / 2; // Punto de division del trabajo
    
    // Hilo 1 procesa la primera mitad (indices 0 al 4)
    thread h1(procesar, ref(datos), 0, mitad, "Nucleo 1");
    
    // Hilo 2 procesa la segunda mitad (indices 5 al 9)
    thread h2(procesar, ref(datos), mitad, datos.size(), "Nucleo 2");
    
    h1.join();
    h2.join();
    
    return 0;
}