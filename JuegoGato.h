#include <vector>

class JuegoGato {
private:
    std::vector<std::vector<int>> tableroEstado;

public:
    // Constructor
    JuegoGato();

    // Muestra el estado actual del tablero
    void mostrarTablero();

    // Verifica si hay espacios libres en el tablero
    bool hayEspaciosLibres();

    // Registra el movimiento de un jugador en una posición del tablero
    bool registrarMovimiento(int fila, int columna, int jugador);

    // Evalúa el estado actual del juego
    int evaluarEstado();

    // Obtiene el estado del tablero
    std::vector<std::vector<int>>& obtenerEstadoTablero();
};
