#ifndef EJERCICIO_04_GRUPAL_PLAYER_HPP
#define EJERCICIO_04_GRUPAL_PLAYER_HPP

#include <string>
#include <vector>
#include "../utils/utilities.hpp"

using namespace std;

class Player
{
private:
    string _playerName;
    int _playerNumber;
    int _coins; // Cantidad de fichas
public:
    Player(int playerNumber);
    Player(string playerName);
    ~Player();

    int getCoins() const;
    string getNombre() const;
    int getPlayerNumber() const;

    void setCoins(int &coins);

    void decreaseCoins();
    static vector<int> getDiceNumbers(int &dicesAmount);
};

#endif //EJERCICIO_04_GRUPAL_PLAYER_HPP