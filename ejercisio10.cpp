#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contacto
{
private:
    string nombre;
    string telefono;
    string correo;

public:
    Contacto() {}

    Contacto(string _nombre, string _telefono, string _correo)
    {
        nombre = _nombre;
        telefono = _telefono;
        correo = _correo;
    }

    string getNombre()
    {
        return nombre;
    }

    string getTelefono()
    {
        return telefono;
    }

    string getCorreo()
    {
        return correo;
    }
};
int main()
{
    vector<Contacto> contactos;

    int opcion;
    string nombre;
    string telefono;
    string correo;
    bool encontrado;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Buscar contacto" << endl;
        cout << "3. Eliminar contacto" << endl;
        cout << "4. Mostrar contactos" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            cout << "Nombre: ";
            cin >> nombre;

            cout << "Telefono: ";
            cin >> telefono;

            cout << "Correo: ";
            cin >> correo;

            contactos.push_back(Contacto(nombre, telefono, correo));

            cout << "Contacto registrado correctamente." << endl;
            break;

        case 2:
              encontrado = false;

            cout << "Ingrese el nombre: ";
            cin >> nombre;

            for (int i = 0; i < contactos.size(); i++)
            {
                if (contactos[i].getNombre() == nombre)
                {
                    cout << "\nNombre: " << contactos[i].getNombre() << endl;
                    cout << "Telefono: " << contactos[i].getTelefono() << endl;
                    cout << "Correo: " << contactos[i].getCorreo() << endl;

                    encontrado = true; }
            }
            if (!encontrado) {
                cout << "Contacto no encontrado." << endl; }
            break;

        case 3:

            encontrado = false;

            cout << "Ingrese el nombre del contacto a eliminar: ";
            cin >> nombre;

            for (int i = 0; i < contactos.size(); i++)
            {
                if (contactos[i].getNombre() == nombre)
                {
                    contactos.erase(contactos.begin() + i);

                    cout << "Contacto eliminado correctamente." << endl;

                    encontrado = true;

                    break;
                }
            }
        if (!encontrado)
            {
                cout << "Contacto no encontrado." << endl;
            }

            break;

        case 4:

            if (contactos.empty())
            {
                cout << "No existen contactos registrados." << endl;
            }
            else
            {
                for (int i = 0; i < contactos.size(); i++)
                {
                    cout << "\nNombre: " << contactos[i].getNombre() << endl;
                    cout << "Telefono: " << contactos[i].getTelefono() << endl;
                    cout << "Correo: " << contactos[i].getCorreo() << endl;
                }
            }

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