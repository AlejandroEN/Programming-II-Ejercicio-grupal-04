#include "../include/Player.hpp"

Player::Player(const string &playerName)
{
    _playerName = playerName;
    _chips = 3;
}

string Player::getNombre() const { return _playerName; }

int Player::getChips() const { return _chips; }

void Player::setPlayerName(string &playerName) { _playerName = playerName; }

void Player::decreaseCoins() { _chips--; }

SuperVector<int> Player::getDiceValues(MoveType moveType) const
{
    string text;

    if  (moveType == MoveType::ATTACK)
        text = format("{}, ¿con cuántos dados ataca?: ", this->getNombre());
    else
        text = format("{}, ¿con cuántos dados defiende?: ", this->getNombre());

    auto attackAmount = input<int>(1, this->getChips(), text);
    auto attackDiceNumbers = simulateDiceRoll(attackAmount);
    attackDiceNumbers.sort(SuperVector<int>::Order::DESC);

    return attackDiceNumbers;
}