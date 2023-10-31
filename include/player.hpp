#ifndef EJERCICIO_04_GRUPAL_PLAYER_HPP
#define EJERCICIO_04_GRUPAL_PLAYER_HPP

#include <string>
#include <vector>

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

    string getNombre() const;
    int getPlayerNumber() const;
    int getCoins() const;

    void setCoins(int &coins);
    static vector<int> getDiceNumbers(int &dices);
};

#endif //EJERCICIO_04_GRUPAL_PLAYER_HPP