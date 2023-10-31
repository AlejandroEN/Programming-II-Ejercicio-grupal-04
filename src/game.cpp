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
        int attackPlayerLosedCoins = 0, defendPlayerLosedCoins = 0;

        // Attack player
        cout << "\n-----" << endl;
        auto dicesAttackAmount = input<int>(format("{}, ¿con cuántos dados ataca?: ", attackPlayer->getNombre()));
        dicesAttackAmount = min(attackPlayer->getCoins(), dicesAttackAmount);
        vector<int> attackDiceNumbers = Player::getDiceNumbers(dicesAttackAmount);
        sort(attackDiceNumbers.begin(), attackDiceNumbers.end(), greater());

        cout << "Resultado: " << getVectorElements(attackDiceNumbers) << endl;

        // Defend player
        auto dicesDefendAmount = input<int>(format("{}, ¿con cuántos dados defiende?: ", defendPlayer->getNombre()));
        dicesDefendAmount = min(defendPlayer->getCoins(), dicesDefendAmount);
        vector<int> defendDiceNumbers = Player::getDiceNumbers(dicesDefendAmount);
        sort(defendDiceNumbers.begin(), defendDiceNumbers.end(), greater());

        cout << "Resultado: " << getVectorElements(defendDiceNumbers) << endl;

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
        cout << " y " << defendPlayer->getNombre() << " pierde " << defendPlayerLosedCoins << " fichas";

        turn ++;
    }

    auto *winnerPlayer = jugador1->getCoins() == 0 ? jugador2 : jugador1;

    cout << "\n\n" << winnerPlayer->getNombre() << " ganó" << endl;
}