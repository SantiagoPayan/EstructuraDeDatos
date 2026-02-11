/**
 * @file main.cpp
 * @brief Programa de prueba para la clase Matriz con entrada de usuario activa.
 */
//Payan Ibarra Santiago
//Nuñez Saille Jose
#include <iostream>
#include "Matriz.hpp"

using namespace std;

int main() {
    try {
        cout << "=== PRUEBA COMPLETA DE LA CLASE MATRIZ ===\n" << endl;

        // --- 1. Creación e Inicialización ---
        cout << "1. Creando Matriz A (2x2) y Matriz B (2x2)..." << endl;
        Matriz A(2, 2);
        Matriz B(2, 2);

        // Usamos el operador [] para llenar datos de prueba
        A[0][0] = 4; A[0][1] = 7;
        A[1][0] = 2; A[1][1] = 6;

        B[0][0] = 1; B[0][1] = 2;
        B[1][0] = 3; B[1][1] = 4;

        cout << "Matriz A:" << endl << A << endl;
        cout << "Matriz B:" << endl << B << endl;

        // --- 2. Operaciones Aritméticas ---
        cout << "2. Suma (A + B):" << endl << (A + B) << endl;
        cout << "3. Resta (A - B):" << endl << (A - B) << endl;
        cout << "4. Multiplicaci\xA2n (A * B):" << endl << (A * B) << endl;
        cout << "5. Escalar (A * 2.0):" << endl << (A * 2.0) << endl;

        // --- 3. Álgebra Lineal ---
        cout << "6. Transpuesta de A:" << endl << A.transpuesta() << endl;

        cout << "7. Inversa de A:" << endl;
        try {
            Matriz InvA = A.inversa();
            cout << InvA << endl;
            // Verificación
            cout << "Verificaci\xA2n (A * InvA) debe ser Identidad:" << endl;
            cout << (A * InvA) << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        // --- 4. Redimensionamiento ---
        cout << "8. Redimensionar A a (3x3) (Rellena con ceros):" << endl;
        A.redimensionar(3, 3);
        cout << A << endl;

        // --- 5. Entrada de Datos del Usuario (REQUERIDO) ---
        cout << "\n=== 9. PRUEBA DE ENTRADA DE DATOS (operator>>) ===" << endl;
        cout << "A continuaci\xA2n se crear\xA0 una nueva matriz de 2x2." << endl;
        Matriz Usuario(2, 2);

        // Aquí es donde se solicita la interacción
        cout << "Por favor, ingrese los 4 valores de la matriz:" << endl;
        cin >> Usuario; // Llama a la sobrecarga de operator>>

        cout << "\nExcelente! La matriz que usted ingres\xA2 es:" << endl;
        cout << Usuario << endl; //Regresa la matriz dada por el usuario de forma ordenada

        cout << "Probando multiplicaci\xA2n de su matriz por 10:" << endl;
        cout << (Usuario * 10.0) << endl; //Retorna la matriz dada por el usuario multiplicada por un escalar de 10

    } catch (const exception& e) {
        cerr << "\nExcepci\xA2n capturada: " << e.what() << endl;
    }

    return 0;
}
