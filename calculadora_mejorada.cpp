#include <iostream>
using namespace std;

float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b == 0) {
        cout << "Error: no se puede dividir entre cero" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    int opcion;
    float a, b;

    cout << "=== CALCULADORA ===" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;

    cout << "Elige una opcion: ";
    cin >> opcion;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    switch(opcion) {
        case 1:
            cout << "Resultado: " << suma(a, b) << endl;
            break;
        case 2:
            cout << "Resultado: " << resta(a, b) << endl;
            break;
        case 3:
            cout << "Resultado: " << multiplicacion(a, b) << endl;
            break;
        case 4:
            cout << "Resultado: " << division(a, b) << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
    }

    return 0;
}