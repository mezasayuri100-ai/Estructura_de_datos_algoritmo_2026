#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> pila;
    string palabra;
    bool palindromo = true;

    cout << "Ingrese una palabra: ";
    cin >> palabra;

    for (int i = 0; i < palabra.length(); i++)
    {
        pila.push(palabra[i]);
    }

    for (int i = 0; i < palabra.length(); i++)
    {
        if (palabra[i] != pila.top())
        {
            palindromo = false;
            break;
        }

        pila.pop();
    }

    if (palindromo)
    {
        cout << "La palabra es un palindromo." << endl;
    }
    else
    {
        cout << "La palabra no es un palindromo." << endl;
    }

    return 0;
}