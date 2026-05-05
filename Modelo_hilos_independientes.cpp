#include <iostream>
#include <thread>
using namespace std;

// Función que simula una alarma silenciosa (tarea de fondo)
void activar_alarma_silenciosa() {
    for(int i = 1; i <= 5; i++) {
        cout << "[FONDO] Enviando alerta a central remota... intento " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    cout << "[FONDO] Alerta enviada exitosamente al servidor." << endl;
}

int main() {
    cout << "=== SISTEMA CON HILOS INDEPENDIENTES ===" << endl;
    
    // Se crea el hilo de fondo
    thread hilo_fondo(activar_alarma_silenciosa);
    
    // Desvincula el hilo: ya no lo controlamos desde el main
    // El hilo sigue ejecutándose solo en segundo plano
    hilo_fondo.detach();
    
    cout << "[SISTEMA] Alarma silenciosa activada en segundo plano." << endl;
    cout << "[SISTEMA] El panel principal sigue funcionando normalmente..." << endl;
    
    // El sistema principal sigue haciendo otras tareas
    for(int i = 1; i <= 3; i++) {
        cout << "[SISTEMA] Monitoreando sensores... " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(600));
    }
    
    // Damos tiempo a que el hilo de fondo termine antes de cerrar
    // Si el main termina primero, el hilo detach se mata automáticamente
    cout << "[SISTEMA] Esperando confirmación de alarma..." << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    
    cout << "=== Sistema en modo normal ===" << endl;
    return 0;
}