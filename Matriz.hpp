/**
 * @file Matriz.hpp
 * @brief Definición de la clase Matriz para operaciones de álgebra lineal básica.
 */

#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>
#include <stdexcept> // Para manejo de excepciones

class Matriz {
private:
    unsigned int renglones;
    unsigned int columnas;
    double** datos; // Puntero a arreglo bidimensional dinámico

    // Métodos privados de utilería
    void reservarMemoria(unsigned int r, unsigned int c);
    void liberarMemoria();

public:
    /**
     * @brief Constructor con parámetros por defecto.
     * explicit: Evita conversión implícita de int a Matriz.
     * @param r Número de renglones (default 1).
     * @param c Número de columnas (default 1).
     */
    explicit Matriz(unsigned int r = 1, unsigned int c = 1);

    /**
     * @brief Destructor. Libera la memoria dinámica.
     */
    ~Matriz();

    /**
     * @brief Constructor de copias.
     * Crea una nueva matriz como copia profunda de otra.
     */
    Matriz(const Matriz& otra);

    /**
     * @brief Operador de asignación.
     * Permite a = b realizando copia profunda.
     */
    Matriz& operator=(const Matriz& otra);

    // --- Operadores Aritméticos ---
    Matriz operator+(const Matriz& rhs) const;
    Matriz operator-(const Matriz& rhs) const;
    Matriz operator*(const Matriz& rhs) const; // Producto matricial
    Matriz operator*(double escalar) const;    // Producto por escalar

    // --- Acceso ---
    // Versión para modificar (escritura/lectura)
    double* operator[](unsigned int index);
    // Versión const para solo lectura
    const double* operator[](unsigned int index) const;

    // --- Métodos de Álgebra ---
    /**
     * @brief Calcula la transpuesta de la matriz.
     * @return Una nueva matriz transpuesta.
     */
    Matriz transpuesta() const;

    /**
     * @brief Calcula la inversa mediante Gauss-Jordan.
     * @return Una nueva matriz que es la inversa de la actual.
     * @throws std::runtime_error si la matriz es singular (no tiene inversa).
     */
    Matriz inversa() const;

    /**
     * @brief Redimensiona la matriz actual.
     * Si crece, rellena con ceros. Si decrece, trunca los datos.
     */
    void redimensionar(unsigned int nuevoR, unsigned int nuevoC);

    // Getters para dimensiones (útiles para el cliente)
    unsigned int getRenglones() const { return renglones; }
    unsigned int getColumnas() const { return columnas; }

    // --- Operadores de Flujo (Friends) ---
    friend std::ostream& operator<<(std::ostream& os, const Matriz& m);
    friend std::istream& operator>>(std::istream& is, Matriz& m);
};

// --- Operador No Miembro ---
/**
 * @brief Permite la conmutatividad del producto escalar (escalar * Matriz).
 */
Matriz operator*(double escalar, const Matriz& m);

#endif // MATRIZ_HPP
