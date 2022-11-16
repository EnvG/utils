#ifndef UTILS_H
#define UTILS_H

#define WIN_CLEAR_CONSOLE defined(_WIN32) || defined(__CYGWIN__)
#define LINUX_CLEAR_CONSOLE defined(__linux__)
#define MAC_CLEAR_CONSOLE defined(__APPLE__) && defined(__MACH__)

#include "utils.h"
#include "tools/regex.h"
#include <cstdio>

/// @brief Действия после ввода
enum ACTION
{
    NOTHING,
    CLEAR_CONSOLE,
};

/// @brief Очистить консоль
void clear(ACTION action = ACTION::CLEAR_CONSOLE)
{
    switch (action)
    {
    case ACTION::CLEAR_CONSOLE:
// Очистка консоли
#if WIN_CLEAR_CONSOLE
        system("cls");
#elif LINUX_CLEAR_CONSOLE
        system("clear");
#elif MAC_CLEAR_CONSOLE
        system("clear");
#endif
        break;
    default:
        return;
    }
}

void Input(std::string msg, std::string &str, ACTION action)
{
    // Очистка консоли
    clear(action);
    // Предложение ввода
    std::cout << msg;
    // Ввод
    std::cin >> str;
}

/// @brief Ввод целого числа
/// @param msg Сообщение предложения ввода
/// @return Введённое число
int InputInteger(std::string msg, ACTION action = ACTION::CLEAR_CONSOLE)
{
    float a;
    std::string str;

    // Цикл запрета ввода символов и нецелых чисел
    do
    {
        // Ввод
        Input(msg, str, action);
    } while (!std::regex_search(str, std::regex(REGEX_INTEGER)) || (a = atof(str.c_str())) != (int)a);

    return (int)a;
}
/// @brief Ввода числа с плавающей точкой
/// @param msg Сообщения предложения ввода
/// @return Введённое число
float InputFloat(std::string msg = "Введите число: ", ACTION action = ACTION::CLEAR_CONSOLE)
{
    float a;
    std::string str;

    do
    {
        // Ввод
        Input(msg, str, action);
    } while (!std::regex_search(str, std::regex(REGEX_FLOAT)));

    a = atof(str.c_str());

    return a;
}
#endif