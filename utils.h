#include <iostream>
#include <regex>
#include <string>
#include <vector>

/// @brief Действия после ввода
enum ACTION
{
    NOTHING,
    CLEAR_CONSOLE,
};

/// @brief Очистка консоли
void clear(ACTION action = ACTION::CLEAR_CONSOLE);

void Input(std::string msg, std::string &str, ACTION action);

/// @brief Ввод целого числа
/// @param msg Сообщение предложения ввода
/// @return Введённое число
int InputInteger(std::string msg = "Введите целое число: ", ACTION action = ACTION::CLEAR_CONSOLE);
float InputFloat(std:: string msg = "Введите число: ", ACTION action = ACTION::CLEAR_CONSOLE);


#pragma region Выводы
/// @brief Вывод вектора
/// @tparam T Тип значений вектора
/// @param values Вектор
/// @param separator Разделитель значений
template <typename T>
void PrintVector(std::vector<T> values, char separator = '\n')
{
    for (T e : values)
    {
        std::cout << e << separator;
    }

    std::cout << std::endl;
}
#pragma endregion