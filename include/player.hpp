#ifndef EJERCICIO_04_GRUPAL_PLAYER_HPP
#define EJERCICIO_04_GRUPAL_PLAYER_HPP

#include <vector>
#include <string>
#include <format>
#include "dice.hpp"
#include "../utils/utilities.hpp"

using namespace std;

class Player
{
private:
    string _playerName;
    int _chips;

public:
    explicit Player(const string &playerName);

    enum class MoveType
    {
        ATTACK,
        DEFEND
    };

    // Getters
    [[nodiscard]] int getChips() const;
    [[nodiscard]] string getNombre() const;

    // Setters
    void setPlayerName(string &playerName);

    // Methods
    void decreaseCoins();
    [[nodiscard]] SuperVector<int> getDiceValues(MoveType moveType) const;
};

#endif //EJERCICIO_04_GRUPAL_PLAYER_HPP