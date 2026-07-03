#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    queue<string> personas;
    string nombre;

    cout << "Registro de personas" << endl;

    for (int i = 1; i <= 10; i++)
    {
        cout << "Ingrese el nombre de la persona " << i << ": ";
        cin >> nombre;
        personas.push(nombre);
    }

    cout << endl;
    cout << "Atencion de personas" << endl;

    while (!personas.empty())
    {
        cout << "Atendiendo a: " << personas.front() << endl;
        personas.pop();
    }

    return 0;
}