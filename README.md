# Taller 2 Estructura De Datos

## Integrantes:

* Daniela Alejandra Infante Soto, 21.446.602-3, daniela.infante@alumnos.ucn.cl, Paralelo C2
* Máximo Andrés Sazo Troncoso, 21.654.236-3, maximo.sazo@alumnos.ucn.cl, Paralelo C2

# Juego de Gato con IA
## Instrucciones para ejecutar el programa
### Requisitos previos:

Tener un compilador de C++ instalado, como GCC o Clang.
Asegúrate de tener los archivos Main.cpp y JuegoGato.cpp en el mismo directorio.
Compilación: Para compilar el programa, abre una terminal o consola en el directorio donde se encuentran los archivos y ejecuta el siguiente comando:
* Linea de compilacion: ``` g++ -o gato Main.cpp ```
* Linea de ejecucion: `` .\gato.exe ``
<br />
El juego se ejecutará en la terminal, alternando entre la IA (jugador 1) y el jugador humano (jugador 2). El jugador humano deberá ingresar las coordenadas de la fila y la columna donde desea colocar su ficha, (fila, espacio, columna).

## Explicaciones sobre el algoritmo utilizado
El programa utiliza el algoritmo Minimax con poda alfa-beta para permitir que la IA juegue de manera óptima en un juego de Tic-Tac-Toe (Juego de Gato). El algoritmo Minimax evalúa todas las posibles jugadas del juego y elige la mejor jugada en función de los resultados de las jugadas futuras.

La poda alfa-beta es una técnica que mejora la eficiencia del algoritmo Minimax, eliminando ciertas ramas del árbol de decisiones que no necesitan ser exploradas, lo que permite que el programa ejecute el algoritmo mucho más rápido.

Flujo de ejecución:
<br />
La IA juega como jugador 1 y toma su turno primero.
El jugador humano juega como jugador -1 y alterna los turnos con la IA.
El juego termina cuando hay un ganador o si el tablero está lleno (empate).
Explicación teórica del algoritmo Minimax y la poda alfa-beta
## Algoritmo Minimax 
El algoritmo Minimax es un algoritmo de toma de decisiones utilizado en juegos de dos jugadores, en los que cada jugador trata de maximizar su ganancia y minimizar la ganancia del oponente. La idea es construir un árbol de decisiones donde cada nodo representa un estado del juego, y las ramas representan los posibles movimientos de cada jugador.

* ``Maximización``: En el caso de la IA, el objetivo es maximizar su puntuación (es decir, ganar).
* ``Minimización``: En el caso del jugador humano, el objetivo es minimizar la puntuación de la IA (es decir, evitar que gane).
## Poda Alfa-Beta
La poda alfa-beta es una mejora del algoritmo Minimax que permite reducir el número de nodos que se exploran en el árbol de decisiones. Funciona utilizando dos parámetros: alfa y beta.
* ``Alfa``: La mejor puntuación que el jugador maximizador puede asegurar hasta ese momento.
* ``Beta``: La mejor puntuación que el jugador minimizador puede asegurar hasta ese momento.
Si en cualquier momento, el valor de alfa es mayor o igual que el valor de beta, se puede podar (es decir, detener) la exploración de esa rama del árbol, ya que no conducirá a una mejor solución.

## Diagrama del árbol de juego para un caso simple
Para ilustrar cómo funciona el algoritmo Minimax, consideremos el siguiente caso simple con los primeros tres movimientos del juego. Supongamos que la IA (X) juega primero y el jugador humano (O) responde.
 
![image](https://github.com/user-attachments/assets/c0d79647-fd3c-4af7-a4bd-383aa2206abe)

En cada nivel, los nodos representan los posibles movimientos del jugador correspondiente.
La IA (X) intenta maximizar su puntaje, mientras que el jugador humano (O) intenta minimizarlo.
A medida que el árbol crece, el algoritmo explora todas las jugadas posibles, eligiendo siempre las mejores opciones.
Árbol de decisión con poda alfa-beta
Al aplicar la poda alfa-beta, el árbol se recorta eliminando ramas innecesarias, lo que optimiza el proceso de búsqueda.

## Análisis de complejidad temporal
* ### Antes de aplicar poda alfa-beta:
El algoritmo Minimax explora todas las posibles jugadas del juego. En un tablero de Tic-Tac-Toe, el árbol tiene una profundidad máxima de 9 (el número máximo de movimientos en el juego) y en cada nodo se evalúan 3 posibles movimientos en el peor de los casos.

La complejidad temporal del algoritmo Minimax sin poda es:
<br />
O(3^9) = O(19,683)
<br />
Esto implica que sin poda, el algoritmo necesita explorar casi 20,000 nodos para determinar la mejor jugada.

* ### Después de aplicar poda alfa-beta:
Con la poda alfa-beta, la complejidad temporal se reduce drásticamente porque no se exploran todas las ramas del árbol. En el mejor de los casos, la poda alfa-beta puede reducir la complejidad a:
<br />
O(√(3^9)) ≈ O(250)
<br />
Esto significa que el algoritmo optimizado con poda alfa-beta puede explorar un número significativamente menor de nodos, mejorando la eficiencia.

