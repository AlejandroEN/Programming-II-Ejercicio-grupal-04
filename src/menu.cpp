#include "../include/menu.hpp"

void runGame(Player *jugador1, Player *jugador2)
{
    Player *attackPlayer, *defendPlayer;

    for (int turn = 0; jugador1->getChips() > 0 && jugador2->getChips() > 0; turn++)
    {
        int attackPlayerLosedCoins = 0, defendPlayerLosedCoins = 0;

        attackPlayer = turn % 2 == 0 ? jugador1 : jugador2;
        defendPlayer = turn % 2 == 0 ? jugador2 : jugador1;

        // Attack player
        cout << "-----" << endl;
        auto attackDiceNumbers = attackPlayer->getDiceValues(Player::MoveType::ATTACK);
        cout << "Resultado: " << attackDiceNumbers.getAsString() << endl;

        // Defend player
        auto defendDiceNumbers = defendPlayer->getDiceValues(Player::MoveType::DEFEND);
        cout << "Resultado: " << defendDiceNumbers.getAsString() << endl;

        for (int i = 0; i < min(attackDiceNumbers.size(), defendDiceNumbers.size()); i++)
        {
            if (attackDiceNumbers[i] > defendDiceNumbers[i])
            {
                defendPlayer->decreaseCoins();
                defendPlayerLosedCoins++;
            }
            else if (attackDiceNumbers[i] <= defendDiceNumbers[i])
            {
                attackPlayer->decreaseCoins();
                attackPlayerLosedCoins++;
            }
        }

        cout << attackPlayer->getNombre() << " pierde " << attackPlayerLosedCoins << " fichas";
        cout << " y " << defendPlayer->getNombre() << " pierde " << defendPlayerLosedCoins << " fichas" << endl;
    }

    auto *winnerPlayer = jugador1->getChips() == 0 ? jugador2 : jugador1;
    cout << "\n\n" << winnerPlayer->getNombre() << " ganó" << endl;
}

void setPlayersNames(Player *jugador1, Player *jugador2)
{
    auto jugador1Name = input<string>("Ingrese el nombre del jugador 1: ");
    auto jugador2Name = input<string>("Ingrese el nombre del jugador 2: ");
    cout << "\n";
    jugador1->setPlayerName(jugador1Name);
    jugador2->setPlayerName(jugador2Name);
}