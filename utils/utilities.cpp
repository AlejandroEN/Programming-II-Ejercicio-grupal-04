#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#include "utilities.hpp"

template <typename T>
T input(const string &message)
{
    T value;
    cout << message;
    cin >> value;
    return value;
}
template string input(const string &);

template <typename T>
T input(T lowerLimit, T upperLimit, const string &message)
{
    T value;
    cout << message;
    cin >> value;

    while (value < lowerLimit || value > upperLimit)
    {
        cout << "El valor debe estar entre " << lowerLimit << " y " << upperLimit << "." << endl;
        cout << message;
        cin >> value;
    }

    return value;
}
template int input(int, int, const string &);

int randomInt(int lowerLimit, int upperLimit)
{
    random_device randomDevice;
    default_random_engine defaultEngine(randomDevice());
    uniform_int_distribution intDistribution(lowerLimit, upperLimit);
    return intDistribution(defaultEngine);
}

float randomFloat(float lowerLimit, float upperLimit)
{
    random_device randomDevice;
    default_random_engine defaultEngine(randomDevice());
    uniform_real_distribution realDistribution(lowerLimit, upperLimit);
    return realDistribution(defaultEngine);
}

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

    cout << "\n";
    return option;
}

template <typename T>
string SuperVector<T>::getAsString() const
{
    string result;

    for (int i = 0; i < this->size(); i++)
    {
        result += to_string(this->at(i));

        if (i < this->size() - 1)
        {
            result += ", ";
        }
    }

    return result;
}
template string SuperVector<int>::getAsString() const;

template <typename T>
void SuperVector<T>::sort(Order order)
{
    if (order == Order::ASC)
    {
        std::sort(this->begin(), this->end());
    }
    else
    {
        std::sort(this->begin(), this->end(), greater());
    }
}
template void SuperVector<int>::sort(Order);