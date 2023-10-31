#include "../include/Player.hpp"

Player::Player(int playerNumber) : _playerNumber(playerNumber) {}
Player::Player(string playerName): _playerName(playerName) {}

string Player::getNombre() const { return _playerName; }
int Player::getPlayerNumber() const { return _playerNumber; }
int Player::getCoins() const { return _coins; }

void Player::setCoins(int &coins) { _coins = coins; }