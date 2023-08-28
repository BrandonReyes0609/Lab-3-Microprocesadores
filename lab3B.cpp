/* Es el inicio Factorial openMP
*  @Autores:
*   - Carlos Valladares, 221164
*   - Brandon Reyes, 22992
*  Fecha: 22/08/2023
*  Archivo: lab3.cpp
*/
#include <iostream>
#include <omp.h>
using namespace std;

// (1) Hemos seleccionado la Opción 1: Versión recursiva para calcular el factorial.

// (2) Esta función realiza el cálculo del factorial de manera recursiva.
unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int numero;
    bool echaEntrada = false; // Variable para verificar si la entrada ha sido completada

    // (3) Uso de directivas y constructores de OpenMP.
    // La directiva 'parallel sections' permite dividir el código en secciones que pueden ejecutarse en paralelo.
    #pragma omp parallel sections
    {
        // (3) La directiva 'section' define una sección individual que se ejecutará en paralelo.
        #pragma omp section
        {
            cout << "Ingrese un número: ";
            cin >> numero;
            
            // (4) Uso del método de sincronización 'critical'.
            // La directiva 'critical' asegura que solo un hilo acceda a la sección crítica a la vez.
            #pragma omp critical
            {
                echaEntrada = true; // Marcar la entrada como completada
            }
        }

        // (3) Otra sección que se ejecutará en paralelo.
        #pragma omp section
        {
            // Esperar hasta que la entrada esté completa
            while(!echaEntrada) {}

            cout << "Factorial de " << numero << " es " << factorial(numero) << endl;
        }
    }

    return 0;
}
