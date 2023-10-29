#include "utilities.hpp"

/**
 * @brief Takes a message as input and returns a value of type T.
 *
 * @tparam T The type of value to be returned.
 * @param message The message to be displayed to the user.
 * @return T The value entered by the user.
 */
template <typename T>
T input(const string &message)
{
    T value;
    cout << message;
    cin >> value;
    return value;
}

/**
 * Generates a random integer between the given lower and upper limits (inclusive).
 * @param lowerLimit The lower limit of the range.
 * @param upperLimit The upper limit of the range.
 * @return A random integer between the given limits.
 */
int randomInt(int lowerLimit, int upperLimit)
{
    random_device randomDevice;
    default_random_engine defaultEngine(randomDevice());
    uniform_int_distribution intDistribution(lowerLimit, upperLimit);
    return intDistribution(defaultEngine);
}

/**
 * Generates a random float number between the given lower and upper limits.
 * @param lowerLimit The lower limit of the range.
 * @param upperLimit The upper limit of the range.
 * @return A random float number between the given limits.
 */
float randomFloat(float lowerLimit, float upperLimit)
{
    random_device randomDevice;
    default_random_engine defaultEngine(randomDevice());
    uniform_real_distribution realDistribution(lowerLimit, upperLimit);
    return realDistribution(defaultEngine);
}

/**
 * @brief Generates a random number between the given lower and upper limits.
 *
 * @tparam T The type of the numbers to generate.
 * @param lowerLimit The lower limit of the range.
 * @param upperLimit The upper limit of the range.
 * @return T A random number between the given limits.
 */
template <typename T>
T random(T lowerLimit, T upperLimit)
{
    if (is_integral_v<T>)
    {
        return randomInt(lowerLimit, upperLimit);
    }
    else if (is_floating_point_v<T>)
    {
        return randomFloat(lowerLimit, upperLimit);
    }
}
template int random(int lowerLimit, int upperLimit);
template float random(float lowerLimit, float upperLimit);

/**
 * Returns the selected option from a menu of options.
 * @param options A vector of strings representing the menu options.
 * @return An integer representing the selected option.
 */
int getMenuOption(vector<string> options)
{
    int option;
    cout << "Seleccione una opción:" << endl;

    for (int i = 0; i < options.size(); i++)
    {
        cout << i + 1 << ". " << options[i] << endl;
    }

    do
    {
        option = input<int>("Opción: ");
    }
    while (option < 1 || option > options.size());

    return option;
}