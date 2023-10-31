#include "include/game.hpp"

int main()
{
    auto jugador1Name = input<string>("Ingrese el nombre del jugador 1: ");
    auto jugador2Name = input<string>("Ingrese el nombre del jugador 2: ");

    auto *jugador1 = new Player(jugador1Name);
    auto *jugador2 = new Player(jugador2Name);
    runGame(jugador1, jugador2);
}