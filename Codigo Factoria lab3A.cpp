/*
*  @Autores:
*   - Carlos Valladares, 221164
*   - Brandon Reyes, 22992
*  Fecha: 22/08/2023
*  Archivo: lab3.cpp
*/
#include <iostream>

// Función recursiva para calcular el factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int numero;

    std::cout << "Ingrese un número: ";
    std::cin >> numero;

    if (numero < 0) {
        std::cout << "El factorial no está definido para números negativos." << std::endl;
    } else {
        int resultado = factorial(numero);
        std::cout << "El factorial de " << numero << " es: " << resultado << std::endl;
    }

    return 0;
}
