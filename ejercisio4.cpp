#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<string> paginas;
    int opcion;
    string pagina;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Visitar pagina" << endl;
        cout << "2. Retroceder" << endl;
        cout << "3. Mostrar pagina actual" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese la pagina: ";
            cin >> pagina;
            paginas.push(pagina);
            cout << "Pagina registrada." << endl;
            break;

        case 2:
            if (!paginas.empty())
            {
                cout << "Retrocediendo desde: " << paginas.top() << endl;
                paginas.pop();
            }
            else
            {
                cout << "No existen paginas registradas." << endl;
            }
            break;

        case 3:
            if (!paginas.empty())
            {
                cout << "Pagina actual: " << paginas.top() << endl;
            }
            else
            {
                cout << "No hay paginas visitadas." << endl;
            }
            break;

        case 4:
            cout << "Fin del programa." << endl;
            break;

        default:
            cout << "Opcion incorrecta." << endl;
        }

    } while (opcion != 4);

    return 0;
}