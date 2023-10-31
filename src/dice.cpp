#include "../include/dice.hpp"

SuperVector<int> simulateDiceRoll(int dicesAmount)
{
    SuperVector<int> values;

    for (int i = 0; i < dicesAmount; i++)
    {
        values.push_back(randomInt(1, 6));
    }

    return values;
}