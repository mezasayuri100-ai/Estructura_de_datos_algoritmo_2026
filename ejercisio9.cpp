#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Estudiante
{
private:
    int codigo;
    string nombre;
    int edad;
    string carrera;

public:
    Estudiante() {}

    Estudiante(int _codigo, string _nombre, int _edad, string _carrera)
    {
        codigo = _codigo;
        nombre = _nombre;
        edad = _edad;
        carrera = _carrera;
    }

    int getCodigo()
    {
        return codigo;
    }

    string getNombre()
    {
        return nombre;
    }

    int getEdad()
    {
        return edad;
    }

    string getCarrera()
    {
        return carrera;
    }
};

int main()
{
    vector<Estudiante> estudiantes;

    int opcion;
    int codigo;
    int edad;
    string nombre;
    string carrera;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Buscar por codigo" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Codigo: ";
            cin >> codigo;

            cout << "Nombre: ";
            cin >> nombre;

            cout << "Edad: ";
            cin >> edad;

            cout << "Carrera: ";
            cin >> carrera;

            estudiantes.push_back(Estudiante(codigo, nombre, edad, carrera));

            cout << "Estudiante registrado." << endl;
            break;

        case 2:

            if (estudiantes.empty())
            {
                cout << "No existen estudiantes registrados." << endl;
            }
            else
            {
                for (int i = 0; i < estudiantes.size(); i++)
                {
                    cout << "\nCodigo: " << estudiantes[i].getCodigo() << endl;
                    cout << "Nombre: " << estudiantes[i].getNombre() << endl;
                    cout << "Edad: " << estudiantes[i].getEdad() << endl;
                    cout << "Carrera: " << estudiantes[i].getCarrera() << endl;
                }
            }

            break;

        case 3:

            cout << "Ingrese el codigo: ";
            cin >> codigo;

            for (int i = 0; i < estudiantes.size(); i++)
            {
                if (estudiantes[i].getCodigo() == codigo)
                {
                    cout << "\nEstudiante encontrado" << endl;
                    cout << "Nombre: " << estudiantes[i].getNombre() << endl;
                    cout << "Edad: " << estudiantes[i].getEdad() << endl;
                    cout << "Carrera: " << estudiantes[i].getCarrera() << endl;
                }
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