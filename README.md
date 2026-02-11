# Equipo #
* Santiago Payan Ibarra
* Jose Maria Nuñez Saille

---

# Proyecto: Clase Matriz en C++

## Descripción

Este proyecto implementa una clase `Matriz` en C++ diseñada para realizar operaciones de álgebra lineal básica. La implementación se centra en el manejo eficiente de **memoria dinámica** (punteros dobles), la **sobrecarga de operadores** y el cumplimiento de principios de diseño orientado a objetos (encapsulamiento y abstracción).

## Características

La clase `Matriz` ofrece las siguientes funcionalidades:

* **Gestión de Memoria:** Constructores, destructor y constructor de copias (Regla de los Tres) para manejo seguro de memoria dinámica.
* **Aritmética:** Suma (`+`), Resta (`-`), Multiplicación matricial (`*`) y Escalar (`*`).
* **Acceso:** Operador de indexación `[]` para lectura y escritura.
* **Álgebra:** Cálculo de la **Transpuesta** y la **Inversa** (método Gauss-Jordan).
* **Utilidad:** Redimensionamiento dinámico (truncado o relleno con ceros).
* **E/S:** Sobrecarga de operadores `<<` y `>>` para flujos de entrada y salida.

## Estructura de Archivos

El proyecto consta de tres archivos principales:

1. **`Matriz.hpp`**: Archivo de cabecera. Contiene la declaración de la clase y prototipos.
2. **`Matriz.cpp`**: Archivo de implementación. Contiene la lógica de los métodos.
3. **`main.cpp`**: Código cliente. Contiene las pruebas de todas las funcionalidades.

---

## Instrucciones de Compilación y Ejecución

### Opción 1: Terminal (Linux / Ubuntu)

Si estás utilizando un entorno Linux (como Ubuntu), sigue estos pasos:

1. Abre tu terminal (`Ctrl + Alt + T`).
2. Navega al directorio donde guardaste los tres archivos (`cd /ruta/a/tu/carpeta`).
3. Compila el proyecto utilizando `g++`. Debes incluir tanto el `main` como la implementación de la matriz:
```bash
g++ main.cpp Matriz.cpp -o app_matriz

```


4. Ejecuta el programa resultante:
```bash
./app_matriz

```



### Opción 2: Code::Blocks (IDE)

Si prefieres utilizar un entorno de desarrollo integrado como Code::Blocks:

1. Abre Code::Blocks.
2. Ve a **File > New > Project**.
3. Selecciona **Console Application** y haz clic en **Go**.
4. Elige **C++** como lenguaje y da clic en **Next**.
5. Ponle un nombre a tu proyecto (ej. `ProyectoMatriz`) y selecciona la carpeta donde guardarlo.
6. **Agregar los archivos:**
* En el panel izquierdo ("Management"), verás la carpeta `Sources` con un `main.cpp` por defecto.
* Ve a **File > New > Empty File**.
* Te preguntará: *"Do you want to add this new file to the active project?"*. Responde **Sí**.
* Nombra al archivo **`Matriz.hpp`** y guarda. Asegúrate de marcar las casillas "Debug" y "Release".
* Repite el paso anterior para crear **`Matriz.cpp`**.


7. **Copiar el código:**
* Copia el contenido de los códigos proporcionados y pégalos en sus respectivos archivos dentro del IDE (`main.cpp`, `Matriz.hpp`, `Matriz.cpp`).


8. **Compilar y Correr:**
* Presiona la tecla **F9** (o el botón de engranaje con play "Build and run").



---

## Notas Importantes

* **Inversa:** El cálculo de la inversa lanza una excepción si la matriz es singular (determinante cero).
* **Validaciones:** Las dimensiones de la matriz deben ser siempre positivas.
* **Compilador:** Asegúrate de usar un compilador compatible con C++11 o superior.

---
