#ifndef PROJECT_01_LECTURE_UTILITIES_HPP
#define PROJECT_01_LECTURE_UTILITIES_HPP

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Takes a message as input and returns a value of type T.
 *
 * @tparam T The type of value to be returned.
 * @param message The message to be displayed to the user.
 * @return T The value entered by the user.
 */
template <typename T>
T input(const string &message = "");

template <typename T>
T input(T lowerLimit, T upperLimitconst, const string &message = "");

/**
 * Generates a random float number between the given lower and upper limits.
 * @param lowerLimit The lower limit of the range.
 * @param upperLimit The upper limit of the range.
 * @return A random float number between the given limits.
 */
float randomFloat(float lowerLimit, float upperLimit);

/**
 * Generates a random integer between the given lower and upper limits (inclusive).
 * @param lowerLimit The lower limit of the range.
 * @param upperLimit The upper limit of the range.
 * @return A random integer between the given limits.
 */
int randomInt(int lowerLimit, int upperLimit);

/**
 * Returns the selected option from a menu of options.
 * @param options A vector of strings representing the menu options.
 * @return An integer representing the selected option.
 */
int getMenuOption(vector<string> options);

template <typename T>
class SuperVector : public vector<T>
{
public:
    enum class Order
    {
        ASC,
        DESC
    };

    [[nodiscard]] string getAsString() const;
    void sort(Order);
};

#endif //PROJECT_01_LECTURE_UTILITIES_HPP
#pragma clang diagnostic pop