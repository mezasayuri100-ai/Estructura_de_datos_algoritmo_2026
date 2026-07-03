#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> pila;
    int numero;

    cout << "Ingrese numeros (-1 para terminar): " << endl;
    cin >> numero;

    while (numero != -1)
    {
        pila.push(numero);
        cin >> numero;
    }

    cout << "Cantidad de elementos: " << pila.size() << endl;

    if (!pila.empty())
    {
        cout << "Ultimo elemento ingresado: " << pila.top() << endl;
    }
    else
    {
        cout << "La pila esta vacia." << endl;
    }

    return 0;
}