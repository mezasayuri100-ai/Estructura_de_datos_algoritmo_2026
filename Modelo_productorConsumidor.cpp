#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
using namespace std;

// Cola compartida que actúa como buffer
queue<int> buffer_teclas;

// Mutex para proteger la cola (exclusión mutua)
mutex candado;

// Productor: genera teclas y las coloca en el buffer
void productor() {
    for(int i = 1; i <= 10; i++) {
        candado.lock();                     // Bloquea el buffer
        buffer_teclas.push(i);              // Agrega la tecla
        cout << "[PRODUCTOR] Tecla: " << i << " | Buffer size: " << buffer_teclas.size() << endl;
        candado.unlock();                   // Libera el buffer
        
        this_thread::sleep_for(chrono::milliseconds(300)); // Simula tiempo entre teclas
    }
}

// Consumidor: toma teclas del buffer y las procesa
void consumidor() {
    for(int i = 1; i <= 10; i++) {
        candado.lock();                     // Bloquea el buffer
        
        if(!buffer_teclas.empty()) {
            int tecla = buffer_teclas.front();  // Saca la primera tecla
            buffer_teclas.pop();
            cout << "[CONSUMIDOR] Procesando: " << tecla << " | Buffer restante: " << buffer_teclas.size() << endl;
        }
        
        candado.unlock();                   // Libera el buffer
        
        this_thread::sleep_for(chrono::milliseconds(500)); // Simula tiempo de procesamiento
    }
}

int main() {
    // Crear los dos hilos
    thread prod(productor);
    thread cons(consumidor);
    
    // Esperar a que ambos terminen
    prod.join();
    cons.join();
    
    cout << "=== Todos los eventos procesados ===" << endl;
    return 0;
}