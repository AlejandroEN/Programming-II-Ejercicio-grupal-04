#include "../include/game.hpp"

void runGame(Player *jugador1, Player *jugador2)
{
    int turn = 1;
    Player *attackPlayer;
    Player *defendPlayer;

    while (jugador1->getCoins() > 0 && jugador2->getCoins() > 0)
    {
        attackPlayer = turn % 2 == 0 ? jugador1 : jugador2;
        defendPlayer = turn % 2 == 0 ? jugador2 : jugador1;

        cout << "-----" << endl;
        auto dicesAttackAmount = input<int>(format("{}, ¿con cuántos dados ataca?", attackPlayer->getNombre()));
        vector<int> attackDiceNumbers = Player::getDiceNumbers(dicesAttackAmount);

        auto dicesDefendAmount = input<int>(format("{}, ¿con cuántos dados defiende?", defendPlayer->getNombre()));
        vector<int> defendDiceNumbers = Player::getDiceNumbers(dicesDefendAmount);
        
        turn ++;
    }
}