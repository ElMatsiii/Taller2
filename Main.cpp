#include "JuegoGato.cpp"

int minimaxOptimo(std::vector<std::vector<int>>& tablero, int profundidad, bool esMaximizar, int alfa, int beta) {
    JuegoGato evaluador;
    int resultadoEvaluacion = evaluador.evaluarEstado();

    if (resultadoEvaluacion == 1 || resultadoEvaluacion == -1 || !evaluador.hayEspaciosLibres()) {
        return resultadoEvaluacion;
    }

    if (esMaximizar) {
        int mejorValor = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == 0) {
                    tablero[i][j] = 1;
                    mejorValor = std::max(mejorValor, minimaxOptimo(tablero, profundidad + 1, false, alfa, beta));
                    tablero[i][j] = 0;
                    alfa = std::max(alfa, mejorValor);
                    if (beta <= alfa) {
                        break;
                    }
                }
            }
        }
        return mejorValor;
    } else {
        int mejorValor = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == 0) {
                    tablero[i][j] = -1;
                    mejorValor = std::min(mejorValor, minimaxOptimo(tablero, profundidad + 1, true, alfa, beta));
                    tablero[i][j] = 0;
                    beta = std::min(beta, mejorValor);
                    if (beta <= alfa) {
                        break;
                    }
                }
            }
        }
        return mejorValor;
    }
}

int main() {
    JuegoGato partida;
    int turnoJugador = 1; // 1 para IA, -1 para humano

    while (partida.hayEspaciosLibres() && partida.evaluarEstado() == 0) {
        partida.mostrarTablero();
        if (turnoJugador == -1) {
            int fila, columna;
            std::cout << "Ingresa fila y columna: ";
            std::cin >> fila >> columna;
            if (!partida.registrarMovimiento(fila, columna, turnoJugador)) {
                std::cout << "Movimiento invalido. Intentalo nuevamente.\n";
                continue;
            }
        } else {
            int mejorPuntaje = std::numeric_limits<int>::min();
            int filaOptima = -1, columnaOptima = -1;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (partida.obtenerEstadoTablero()[i][j] == 0) {
                        partida.obtenerEstadoTablero()[i][j] = 1;
                        int puntaje = minimaxOptimo(partida.obtenerEstadoTablero(), 0, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                        partida.obtenerEstadoTablero()[i][j] = 0;
                        if (puntaje > mejorPuntaje) {
                            mejorPuntaje = puntaje;
                            filaOptima = i;
                            columnaOptima = j;
                        }
                    }
                }
            }
            partida.registrarMovimiento(filaOptima, columnaOptima, turnoJugador);
        }
        turnoJugador *= -1;
    }

    partida.mostrarTablero();
    int resultadoFinal = partida.evaluarEstado();
    if (resultadoFinal == 1) {
        std::cout << "La IA gana!\n";
    } else if (resultadoFinal == -1) {
        std::cout << "Ganaste!\n";
    } else {
        std::cout << "Es un empate!\n";
    }

    return 0;
}