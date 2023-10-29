#ifndef PROJECT_01_LECTURE_UTILITIES_HPP
#define PROJECT_01_LECTURE_UTILITIES_HPP

#include <random>
#include <iostream>

using namespace std;

template <typename T>
T input(const string &message);

template <typename T>
T random(T lowerLimit, T upperLimit);

int getMenuOption(vector<string> options);

#endif //PROJECT_01_LECTURE_UTILITIES_HPP