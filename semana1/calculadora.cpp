#include <iostream>
using namespace std;

int main() {
    int a, b, opcion;
    cout << "=== CALCULADORA ===" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;

    cout << "Elige una opcion: ";
    cin >> opcion;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    if(opcion == 1) {
        cout << "Resultado: " << a + b << endl;
    }
    else if(opcion == 2) {
        cout << "Resultado: " << a - b << endl;
    }
    else if(opcion == 3) {
        cout << "Resultado: " << a * b << endl;
    }
    else if(opcion == 4) {
        if(b == 0) {
            cout << "Error: no se puede dividir entre cero" << endl;
        } else {
            cout << "Resultado: " << a / b << endl;
        }
    }
    else {
        cout << "opcion no valida" << endl;
    }
    return 0;
}