#include <iostream>
using namespace std;

// funcion que simula una tarea
void tarea1() {
    for(int i = 0; i < 5; i++) {
        cout << "tarea 1: " << i << endl;
    }
}

// segunda tarea
void tarea2() {
    for(int i = 0; i < 5; i++) {
        cout << "tarea 2: " << i << endl;
    }
}

int main() {
    // Ejecucion secuencial
    tarea1();
    tarea2();
    return 0;
}