#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex candado_consola;

// Función que ejecuta cada trabajador
void trabajador(int id, string zona) {
    for(int i = 1; i <= 3; i++) {
        candado_consola.lock();  // Bloquea la consola para que no se mezclen mensajes
        cout << "Trabajador " << id << " escaneando zona " << zona << " - paso " << i << endl;
        candado_consola.unlock(); // Libera la consola
        
        this_thread::sleep_for(chrono::milliseconds(400)); // Simula tiempo de escaneo
    }
    // Reporte final del trabajador
    candado_consola.lock();
    cout << "Trabajador " << id << " terminó zona " << zona << " (TODO OK)" << endl;
    candado_consola.unlock();
}

int main() {
    cout << "=== SISTEMA MAESTRO-TRABAJADOR ===" << endl;
    cout << "[MAESTRO] Iniciando panel de control..." << endl;
    
    // Vector para guardar los hilos trabajadores
    vector<thread> equipo;
    
    // El maestro crea y asigna tareas a los trabajadores
    equipo.push_back(thread(trabajador, 1, "101 (Entrada principal)"));
    equipo.push_back(thread(trabajador, 2, "102 (Oficinas)"));
    equipo.push_back(thread(trabajador, 3, "103 (Almacén)"));
    
    // El maestro espera a que TODOS los trabajadores terminen
    for(auto& h : equipo) {
        h.join();
    }
    cout << "\n[MAESTRO] Todos los trabajadores reportaron. Sistema operativo OK." << endl;
    return 0;
}