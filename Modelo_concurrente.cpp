#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;          // Candado para proteger la variable compartida
int contador = 0; // Variable compartida entre los dos hilos

// Función que ejecuta cada hilo
void tarea(string nombre) {
    for(int i = 0; i < 5; i++) {
        m.lock();                     // Inicia la sección crítica
        contador++;                   // Modifica la variable compartida
        cout << nombre << " -> " << contador << endl;
        m.unlock();                   // Termina la sección crítica
    }
}

int main() {
    // Se crean dos hilos que ejecutan la misma función
    thread h1(tarea, "Hilo 1");
    thread h2(tarea, "Hilo 2");
    
    // El programa espera a que ambos hilos terminen
    h1.join();
    h2.join();
    
    // Resultado final
    cout << "Total: " << contador << endl;
    return 0;
}