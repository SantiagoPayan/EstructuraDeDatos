/**
 * @file main.cpp
 * @brief Interfaz interactiva de usuario para manipular la clase Matriz.
 */
// Santiago Payan Ibarra y Jose Maria Nuñez Saille

#include <iostream>
#include <limits>   // Para limpiar el buffer de entrada
#include <cstdlib>  // Para system("clear")
#include "Matriz.hpp"

using namespace std;

// Función para pausar la ejecución en Linux/Ubuntu
void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Función para limpiar la pantalla en Linux/Ubuntu
void limpiarPantalla() {
    system("clear");
}

void mostrarMenu() {
    limpiarPantalla();
    cout << "========================================" << endl;
    cout << "   CALCULADORA DE MATRICES (C++)" << endl;
    cout << "========================================" << endl;
    cout << "1. Definir/Editar Matriz A" << endl;
    cout << "2. Definir/Editar Matriz B" << endl;
    cout << "3. Ver Matrices A y B" << endl;
    cout << "----------------------------------------" << endl;
    cout << "4. Sumar (A + B)" << endl;
    cout << "5. Restar (A - B)" << endl;
    cout << "6. Multiplicar (A * B)" << endl;
    cout << "7. Multiplicar A por Escalar (k * A)" << endl;
    cout << "----------------------------------------" << endl;
    cout << "8. Transpuesta de A" << endl;
    cout << "9. Inversa de A" << endl;
    cout << "10. Redimensionar A" << endl;
    cout << "----------------------------------------" << endl;
    cout << "0. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Seleccione una opcion: ";
}

// Función auxiliar para crear una matriz desde cero
void crearMatrizUsuario(Matriz& m, string nombre) {
    unsigned int r, c;
    cout << "\n--- Definiendo Matriz " << nombre << " ---" << endl;
    cout << "Ingrese numero de renglones: ";
    cin >> r;
    cout << "Ingrese numero de columnas: ";
    cin >> c;

    // Usamos redimensionar para ajustar la matriz existente
    try {
        m.redimensionar(r, c);
        // Usamos la sobrecarga del operador >>
        cin >> m;
        cout << "Matriz " << nombre << " guardada correctamente." << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    // Instancias iniciales (1x1 por defecto)
    Matriz A(2, 2);
    Matriz B(2, 2);
    
    // Inicializamos con algunos valores para que no esten vacias al inicio
    A[0][0]=1; A[0][1]=2; A[1][0]=3; A[1][1]=4;
    B[0][0]=5; B[0][1]=6; B[1][0]=7; B[1][1]=8;

    int opcion;

    do {
        mostrarMenu();
        if (!(cin >> opcion)) {
            // Validación de entrada numérica
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
        }

        try {
            switch (opcion) {
                case 1:
                    crearMatrizUsuario(A, "A");
                    break;
                case 2:
                    crearMatrizUsuario(B, "B");
                    break;
                case 3:
                    cout << "\n--- Matriz A ---" << endl << A << endl;
                    cout << "\n--- Matriz B ---" << endl << B << endl;
                    break;
                case 4: {
                    cout << "\nCalculando A + B..." << endl;
                    Matriz R = A + B;
                    cout << "Resultado:" << endl << R << endl;
                    break;
                }
                case 5: {
                    cout << "\nCalculando A - B..." << endl;
                    Matriz R = A - B;
                    cout << "Resultado:" << endl << R << endl;
                    break;
                }
                case 6: {
                    cout << "\nCalculando A * B..." << endl;
                    Matriz R = A * B;
                    cout << "Resultado:" << endl << R << endl;
                    break;
                }
                case 7: {
                    double k;
                    cout << "\nIngrese el escalar (k): ";
                    cin >> k;
                    Matriz R = A * k; // Prueba operador miembro
                    // Matriz R2 = k * A; // Prueba operador no miembro (da lo mismo)
                    cout << "Resultado:" << endl << R << endl;
                    break;
                }
                case 8:
                    cout << "\nTranspuesta de A:" << endl;
                    cout << A.transpuesta() << endl;
                    break;
                case 9:
                    cout << "\nInversa de A:" << endl;
                    cout << A.inversa() << endl;
                    break;
                case 10: {
                    unsigned int r, c;
                    cout << "\n--- Redimensionar A ---" << endl;
                    cout << "Nuevos renglones: "; cin >> r;
                    cout << "Nuevas columnas: "; cin >> c;
                    A.redimensionar(r, c);
                    cout << "Matriz redimensionada:" << endl << A << endl;
                    break;
                }
                case 0:
                    cout << "\nSaliendo del programa..." << endl;
                    break;
                default:
                    cout << "\nOpcion invalida." << endl;
            }
        } catch (const exception& e) {
            // Capturamos cualquier error de lógica (dimensiones, singularidad, etc.)
            cout << "\nERROR: " << e.what() << endl;
        }

        if (opcion != 0) pausar();

    } while (opcion != 0);

    return 0;
}
