#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    queue<string> clientes;
    int opcion;
    string nombre;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Agregar cliente" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Mostrar siguiente cliente" << endl;
        cout << "4. Mostrar cantidad de clientes" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el nombre del cliente: ";
            cin >> nombre;
            clientes.push(nombre);
            cout << "Cliente agregado correctamente." << endl;
            break;

        case 2:
            if (!clientes.empty())
            {
                cout << "Cliente atendido: " << clientes.front() << endl;
                clientes.pop();
            }
            else
            {
                cout << "No hay clientes en espera." << endl;
            }
            break;

        case 3:
            if (!clientes.empty())
            {
                cout << "Siguiente cliente: " << clientes.front() << endl;
            }
            else
            {
                cout << "No hay clientes registrados." << endl;
            }
            break;

        case 4:
            cout << "Cantidad de clientes: " << clientes.size() << endl;
            break;

        case 5:
            cout << "Fin del programa." << endl;
            break;

        default:
            cout << "Opcion incorrecta." << endl;
        }

    } while (opcion != 5);

    return 0;
}