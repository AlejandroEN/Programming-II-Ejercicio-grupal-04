#include "include/menu.hpp"
#include "include/player.hpp"

int main()
{
    auto *jugador1 = new Player("Jugador 1");
    auto *jugador2 = new Player("Jugador 2");

    while (true)
    {
        auto option = getMenuOption({"Cambiar el nombre de los jugadores",
                                                "Comenzar el juego",
                                                "Salir"});

        switch (option)
        {
            case 1: setPlayersNames(jugador1, jugador2); break;
            case 2: runGame(jugador1, jugador2); break;
            case 3: return 0;
            default: break;
        }
    }
}