#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Ticket
{
private:
    int codigo;
    string cliente;
    string prioridad;

public:
    Ticket() {}

    Ticket(int _codigo, string _cliente, string _prioridad)
    {
        codigo = _codigo;
        cliente = _cliente;
        prioridad = _prioridad;
    }

    int getCodigo()
    {
        return codigo;
    }

    string getCliente()
    {
        return cliente;
    }

    string getPrioridad()
    {
        return prioridad;
    }
};

int main()
{
    queue<Ticket> tickets;

    int cantidad;
    int codigo;
    string cliente;
    string prioridad;

    cout << "Ingrese la cantidad de tickets: ";
    cin >> cantidad;

    for (int i = 1; i <= cantidad; i++)
    {
        cout << "\nTicket " << i << endl;

        cout << "Codigo: ";
        cin >> codigo;

        cout << "Cliente: ";
        cin >> cliente;

        cout << "Prioridad: ";
        cin >> prioridad;

        Ticket t(codigo, cliente, prioridad);
        tickets.push(t);
    }

    cout << "\nOrden de atencion" << endl;

    while (!tickets.empty())
    {
        Ticket t = tickets.front();

        cout << "Codigo: " << t.getCodigo() << endl;
        cout << "Cliente: " << t.getCliente() << endl;
        cout << "Prioridad: " << t.getPrioridad() << endl;
        cout << "------------------------" << endl;

        tickets.pop();
    }

    return 0;
}