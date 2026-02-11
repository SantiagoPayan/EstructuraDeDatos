/**
 * @file Matriz.cpp
 * @brief Implementación de la clase Matriz.
 */

#include "Matriz.hpp"
#include <iomanip> // Para formato de salida
#include <cmath>   // Para std::abs

// --- Utilería Privada ---

void Matriz::reservarMemoria(unsigned int r, unsigned int c) {
    renglones = r;
    columnas = c;
    datos = new double*[renglones];
    for (unsigned int i = 0; i < renglones; ++i) {
        datos[i] = new double[columnas](); // () inicializa en 0.0
    }
}

void Matriz::liberarMemoria() {
    if (datos) {
        for (unsigned int i = 0; i < renglones; ++i) {
            delete[] datos[i];
        }
        delete[] datos;
        datos = nullptr;
    }
}

// --- Constructores y Destructor ---

Matriz::Matriz(unsigned int r, unsigned int c) {
    if (r == 0 || c == 0) throw std::invalid_argument("Las dimensiones deben ser positivas.");
    reservarMemoria(r, c);
}

Matriz::~Matriz() {
    liberarMemoria();
}

Matriz::Matriz(const Matriz& otra) {
    reservarMemoria(otra.renglones, otra.columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            datos[i][j] = otra.datos[i][j];
        }
    }
}

Matriz& Matriz::operator=(const Matriz& otra) {
    if (this != &otra) { // Evitar auto-asignación
        liberarMemoria();
        reservarMemoria(otra.renglones, otra.columnas);
        for (unsigned int i = 0; i < renglones; ++i) {
            for (unsigned int j = 0; j < columnas; ++j) {
                datos[i][j] = otra.datos[i][j];
            }
        }
    }
    return *this;
}

// --- Operadores Aritméticos ---

Matriz Matriz::operator+(const Matriz& rhs) const {
    if (renglones != rhs.renglones || columnas != rhs.columnas) {
        throw std::invalid_argument("Dimensiones incompatibles para suma.");
    }
    Matriz resultado(renglones, columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado[i][j] = datos[i][j] + rhs.datos[i][j];
        }
    }
    return resultado;
}

Matriz Matriz::operator-(const Matriz& rhs) const {
    if (renglones != rhs.renglones || columnas != rhs.columnas) {
        throw std::invalid_argument("Dimensiones incompatibles para resta.");
    }
    Matriz resultado(renglones, columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado[i][j] = datos[i][j] - rhs.datos[i][j];
        }
    }
    return resultado;
}

Matriz Matriz::operator*(const Matriz& rhs) const {
    if (columnas != rhs.renglones) {
        throw std::invalid_argument("Columnas de A deben igualar Renglones de B para multiplicar.");
    }
    Matriz resultado(renglones, rhs.columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < rhs.columnas; ++j) {
            double suma = 0;
            for (unsigned int k = 0; k < columnas; ++k) {
                suma += datos[i][k] * rhs.datos[k][j];
            }
            resultado[i][j] = suma;
        }
    }
    return resultado;
}

Matriz Matriz::operator*(double escalar) const {
    Matriz resultado(renglones, columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado[i][j] = datos[i][j] * escalar;
        }
    }
    return resultado;
}

// --- Acceso ---

double* Matriz::operator[](unsigned int index) {
    if (index >= renglones) throw std::out_of_range("Indice de renglon fuera de rango.");
    return datos[index];
}

const double* Matriz::operator[](unsigned int index) const {
    if (index >= renglones) throw std::out_of_range("Indice de renglon fuera de rango.");
    return datos[index];
}

// --- Métodos de Álgebra ---

Matriz Matriz::transpuesta() const {
    Matriz t(columnas, renglones); // Dimensiones invertidas
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            t[j][i] = datos[i][j];
        }
    }
    return t;
}

Matriz Matriz::inversa() const {
    if (renglones != columnas) {
        throw std::domain_error("Solo las matrices cuadradas tienen inversa.");
    }
    
    unsigned int n = renglones;
    Matriz original = *this; // Copia para no modificar el objeto actual (pivoteo)
    Matriz identidad(n, n);
    
    // Inicializar identidad
    for(unsigned int i=0; i<n; ++i) identidad[i][i] = 1.0;

    // Método Gauss-Jordan
    for (unsigned int i = 0; i < n; ++i) {
        // Buscar pivote
        double pivote = original[i][i];
        if (std::abs(pivote) < 1e-9) {
            throw std::runtime_error("Matriz singular o cercana a singular.");
        }

        // Normalizar renglón i
        for (unsigned int j = 0; j < n; ++j) {
            original[i][j] /= pivote;
            identidad[i][j] /= pivote;
        }

        // Hacer ceros en la columna i para los demás renglones
        for (unsigned int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = original[k][i];
                for (unsigned int j = 0; j < n; ++j) {
                    original[k][j] -= factor * original[i][j];
                    identidad[k][j] -= factor * identidad[i][j];
                }
            }
        }
    }
    return identidad;
}

void Matriz::redimensionar(unsigned int nuevoR, unsigned int nuevoC) {
    if (nuevoR == 0 || nuevoC == 0) throw std::invalid_argument("Dimensiones deben ser positivas.");

    // Crear nuevo arreglo temporal
    double** nuevosDatos = new double*[nuevoR];
    for (unsigned int i = 0; i < nuevoR; ++i) {
        nuevosDatos[i] = new double[nuevoC](); // Inicializa en 0
    }

    // Determinar límites de copiado
    unsigned int minR = (nuevoR < renglones) ? nuevoR : renglones;
    unsigned int minC = (nuevoC < columnas) ? nuevoC : columnas;

    // Copiar datos existentes
    for (unsigned int i = 0; i < minR; ++i) {
        for (unsigned int j = 0; j < minC; ++j) {
            nuevosDatos[i][j] = datos[i][j];
        }
    }

    // Liberar memoria vieja
    liberarMemoria();

    // Asignar nuevos punteros y dimensiones
    datos = nuevosDatos;
    renglones = nuevoR;
    columnas = nuevoC;
}

// --- Operadores Externos ---

std::ostream& operator<<(std::ostream& os, const Matriz& m) {
    for (unsigned int i = 0; i < m.renglones; ++i) {
        os << "| ";
        for (unsigned int j = 0; j < m.columnas; ++j) {
            os << std::setw(8) << std::setprecision(3) << m.datos[i][j] << " ";
        }
        os << "|" << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matriz& m) {
    std::cout << "Ingrese " << m.renglones * m.columnas << " valores:" << std::endl;
    for (unsigned int i = 0; i < m.renglones; ++i) {
        for (unsigned int j = 0; j < m.columnas; ++j) {
            std::cout << "[" << i << "," << j << "]: ";
            is >> m.datos[i][j];
        }
    }
    return is;
}

Matriz operator*(double escalar, const Matriz& m) {
    return m * escalar; // Reutiliza el operador miembro (conmutatividad)
}
