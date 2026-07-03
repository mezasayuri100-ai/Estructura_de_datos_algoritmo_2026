#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    queue<string> clientes;
    queue<string> copia;
    string nombre;
    int cantidad;

    cout << "Ingrese la cantidad de clientes: ";
    cin >> cantidad;

    for (int i = 1; i <= cantidad; i++)
    {
        cout << "Ingrese el nombre del cliente " << i << ": ";
        cin >> nombre;
        clientes.push(nombre);
    }

    if (!clientes.empty())
    {
        cout << "\nCliente atendido: " << clientes.front() << endl;
        clientes.pop();
    }
    else
    {
        cout << "No hay clientes registrados." << endl;
    }

    cout << "\nClientes pendientes:" << endl;

    copia = clientes;

    while (!copia.empty())
    {
        cout << copia.front() << endl;
        copia.pop();
    }

    return 0;
}