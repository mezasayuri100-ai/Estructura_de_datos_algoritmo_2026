/*
--------------------------------------------------
CURSO : Estructura de Datos y Algoritmos
ALUMNA: Meza Riveros Shayury Minerva

Descripción:
Este programa permite calcular el salario de un
empleado mediante un menú de opciones. El usuario
podrá registrar las horas trabajadas, aplicar
descuentos, agregar bonificaciones e imprimir una
boleta con el salario neto obtenido.
--------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    /*
        Declaración de variables que almacenarán
        la información necesaria para realizar
        los cálculos del salario del empleado.
    */
    int opcion;
    int tipoDescuento;
    int tipoBonificacion;

    float horasTrabajadas = 0;
    float pagoHora = 120;
    float salarioBruto = 0;
    float descuento = 0;
    float bonificacion = 0;
    float salarioNeto = 0;

        /*
            El ciclo do-while permite mostrar el menú
            de manera repetitiva hasta que el usuario
            seleccione la opción de salir.
        */
    do
    {
        cout << "\n===================================";
        cout << "\n   GESTION DE SALARIO EMPLEADO";
        cout << "\n===================================";
        cout << "\n1. Ingresar horas trabajadas";
        cout << "\n2. Mostrar salario";
        cout << "\n3. Ingresar descuento";
        cout << "\n4. Ingresar bonificacion";
        cout << "\n5. Imprimir boleta";
        cout << "\n6. Salir";
        cout << "\n===================================";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        /*
            La estructura switch permite ejecutar
            diferentes acciones dependiendo de la
            opción elegida por el usuario.
        */
    switch(opcion) {

        case 1:
        /*
            Se solicita el número de horas
            trabajadas para posteriormente
            calcular el salario bruto.
        */
            cout << "\nIngrese las horas trabajadas: ";
            cin >> horasTrabajadas;

        /*
            El salario bruto se obtiene
            multiplicando las horas trabajadas
            por el pago correspondiente a cada hora.
        */
            salarioBruto = horasTrabajadas * pagoHora;

            cout << "Horas registradas correctamente.\n";
            break;

        case 2:

        /*
            Esta opción permite visualizar
            el salario bruto calculado hasta
            el momento.
        */
            cout << "\nSalario bruto: S/ "
            << salarioBruto << endl;
            break;

        case 3:

        /*
            El usuario selecciona el tipo
            de descuento que será aplicado
            al salario del empleado.
        */
            cout << "\nTIPO DE DESCUENTO";
            cout << "\n1. SNP (S/120)";
            cout << "\n2. AFP (S/150)";
            cout << "\nSeleccione: ";
            cin >> tipoDescuento;

            if(tipoDescuento == 1) {

                descuento = 120;
                cout << "Descuento SNP aplicado.\n";

            }

            else if(tipoDescuento == 2) {

                descuento = 150;
                cout << "Descuento AFP aplicado.\n";

            }

            else {
                
                cout << "Opcion no valida.\n";
            
            }

            break;

        case 4:

        /*
            Permite registrar una bonificación
            que será sumada al salario del
            empleado durante el cálculo final.
        */
            cout << "\nTIPO DE BONIFICACION";
            cout << "\n1. S/500";
            cout << "\n2. S/1000";
            cout << "\nSeleccione: ";
            cin >> tipoBonificacion;

            if(tipoBonificacion == 1) {

                bonificacion = 500;
                cout << "Bonificacion registrada.\n";

            }

            else if(tipoBonificacion == 2) {

                bonificacion = 1000;
                cout << "Bonificacion registrada.\n";
            
            }
               
            else {
                
                cout << "Opcion no valida.\n";
                
            }

            break;

        case 5:

        /*
            El salario neto se calcula
            restando el descuento y sumando
            la bonificación al salario bruto.
        */
            salarioNeto = salarioBruto - descuento + bonificacion;

        /*
            Finalmente se imprime una boleta
            con toda la información registrada
            y el resultado final obtenido.
        */
            cout << "\n===================================";
            cout << "\n          BOLETA DE PAGO";
            cout << "\n===================================";
            cout << "\nHoras trabajadas : " << horasTrabajadas;
            cout << "\nPago por hora    : S/ " << pagoHora;
            cout << "\nSalario bruto    : S/ " << salarioBruto;
            cout << "\nDescuento        : S/ " << descuento;
            cout << "\nBonificacion     : S/ " << bonificacion;
            cout << "\n-----------------------------------";
            cout << "\nSalario neto     : S/ " << salarioNeto;
            cout << "\n===================================\n";

            break;

        case 6:

        /*
            Esta opción finaliza la ejecución
            del programa y termina el ciclo
            principal del menú.
        */
            cout << "\nPrograma finalizado.\n";
            
            break;

            default:

         /*
            Se muestra este mensaje cuando
            el usuario ingresa una opción
            que no existe en el menú.
        */
            cout << "\nOpcion no valida.\n";
        
    }

    } while(opcion != 6);

        /*
            return 0 indica que el programa terminó
            correctamente sin errores de ejecución.
        */
        
    return 0;
}