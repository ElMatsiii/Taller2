#include <iostream>
#include <vector>
#include <limits>

class JuegoGato {
private:
    std::vector<std::vector<int>> tableroEstado;

public:
    JuegoGato() : tableroEstado(3, std::vector<int>(3, 0)) {}

    void mostrarTablero() {
        for (const auto& fila : tableroEstado) {
            for (int celda : fila) {
                if (celda == 1) std::cout << " X ";
                else if (celda == -1) std::cout << " O ";
                else std::cout << " . ";
            }
            std::cout << std::endl;
        }std::cout <<"----------"<< std::endl;
    }

    bool hayEspaciosLibres() {
        for (const auto& fila : tableroEstado) {
            for (int celda : fila) {
                if (celda == 0) return true;
            }
        }
        return false;
    }

    bool registrarMovimiento(int fila, int columna, int jugador) {
        if (tableroEstado[fila][columna] == 0) {
            tableroEstado[fila][columna] = jugador;
            return true;
        }
        return false;
    }

    int evaluarEstado() {
        for (int i = 0; i < 3; i++) {
            if (tableroEstado[i][0] == tableroEstado[i][1] && tableroEstado[i][1] == tableroEstado[i][2] && tableroEstado[i][0] != 0)
                return tableroEstado[i][0];
            if (tableroEstado[0][i] == tableroEstado[1][i] && tableroEstado[1][i] == tableroEstado[2][i] && tableroEstado[0][i] != 0)
                return tableroEstado[0][i];
        }
        if (tableroEstado[0][0] == tableroEstado[1][1] && tableroEstado[1][1] == tableroEstado[2][2] && tableroEstado[0][0] != 0)
            return tableroEstado[0][0];
        if (tableroEstado[0][2] == tableroEstado[1][1] && tableroEstado[1][1] == tableroEstado[2][0] && tableroEstado[0][2] != 0)
            return tableroEstado[0][2];
        return 0;
    }

    std::vector<std::vector<int>>& obtenerEstadoTablero() {
        return tableroEstado;
    }
};