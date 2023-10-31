#include "../include/game.hpp"

void runGame(Player *jugador1, Player *jugador2)
{
    while (jugador1->getCoins() > 0 && jugador2->getCoins() > 0)
    {
        cout << "-----" << endl;
        auto dicesAttackAmount = input<int>(format("{}, ¿con cuántos dados ataca?", jugador1->getNombre()));
        vector<int> attackDiceNumbers = Player::getDiceNumbers(dicesAttackAmount);

        auto dicesDefendAmount = input<int>(format("{}, ¿con cuántos dados defiende?", jugador2->getNombre()));
        vector<int> defendDiceNumbers = Player::getDiceNumbers(dicesDefendAmount);


    }
}