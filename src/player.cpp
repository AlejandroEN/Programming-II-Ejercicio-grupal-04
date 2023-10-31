#include "../include/Player.hpp"

Player::Player(int playerNumber)
{
    _playerNumber = playerNumber;
    _coins = 3;
}

Player::Player(string playerName)
{
    _playerName = playerName;
    _coins = 3;
}

string Player::getNombre() const { return _playerName; }
int Player::getPlayerNumber() const { return _playerNumber; }
int Player::getCoins() const { return _coins; }

void Player::decreaseCoins() { _coins--; }

vector<int> Player::getDiceNumbers(int &dicesAmount)
{
    vector<int> values;

    for (int i = 0; i < dicesAmount; i++)
    {
        values.push_back(random<int>(1, 6));
    }

    return values;
}