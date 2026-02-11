/**
 * @file main.cpp
 * @brief Programa de prueba para la clase Matriz.
 */

#include <iostream>
#include "Matriz.hpp"

using namespace std;

int main() {
    try {
        cout << "=== PRUEBA DE LA CLASE MATRIZ ===\n" << endl;

        // 1. Constructor
        cout << "1. Creando Matriz A (2x2) y Matriz B (2x2)..." << endl;
        Matriz A(2, 2);
        Matriz B(2, 2);

        // 2. Operador [] (Escritura)
        A[0][0] = 4; A[0][1] = 7;
        A[1][0] = 2; A[1][1] = 6;

        B[0][0] = 1; B[0][1] = 2;
        B[1][0] = 3; B[1][1] = 4;

        // 3. Salida (<<)
        cout << "Matriz A:" << endl << A << endl;
        cout << "Matriz B:" << endl << B << endl;

        // 4. Suma
        cout << "2. Suma (A + B):" << endl;
        Matriz C = A + B;
        cout << C << endl;

        // 5. Resta
        cout << "3. Resta (A - B):" << endl;
        Matriz D = A - B;
        cout << D << endl;

        // 6. Producto Matricial
        cout << "4. Multiplicacion (A * B):" << endl;
        Matriz E = A * B;
        cout << E << endl;

        // 7. Producto por Escalar (Miembro y No Miembro)
        cout << "5. Escalar (A * 2.0) y (3.0 * A):" << endl;
        cout << (A * 2.0) << endl;
        cout << (3.0 * A) << endl;

        // 8. Transpuesta
        cout << "6. Transpuesta de A:" << endl;
        cout << A.transpuesta() << endl;

        // 9. Inversa
        cout << "7. Inversa de A:" << endl;
        try {
            Matriz InvA = A.inversa();
            cout << InvA << endl;
            cout << "Verificacion (A * InvA) = Identidad:" << endl;
            cout << (A * InvA) << endl;
        } catch (const exception& e) {
            cout << "Error calculando inversa: " << e.what() << endl;
        }

        // 10. Redimensionamiento
        cout << "8. Redimensionar B a (3x3) (Crecimiento con ceros):" << endl;
        B.redimensionar(3, 3);
        cout << B << endl;

        cout << "Redimensionar B a (1x1) (Truncamiento):" << endl;
        B.redimensionar(1, 1);
        cout << B << endl;

        // 11. Constructor de Copia
        cout << "9. Constructor de Copia (Copia de A):" << endl;
        Matriz CopiaA(A);
        cout << CopiaA << endl;

        // 12. Entrada (>>)
        cout << "10. Prueba de entrada manual. Creando Matriz F(2,2)." << endl;
        Matriz F(2, 2);
        // Descomenta la siguiente linea para probar la entrada interactiva:
        // cin >> F;
        // cout << "Matriz ingresada:" << endl << F << endl;
        cout << "(Entrada manual saltada para ejecucion rapida, descomentar en codigo)" << endl;

    } catch (const exception& e) {
        cerr << "Excepcion general capturada: " << e.what() << endl;
    }

    return 0;
}
