#include "../utils.h"
#include <vector>
#include <math.h>

#define TEMPLATE template <typename T>
#define MATRIX std::vector<std::vector<T>>

TEMPLATE
class Matrix
{
private:
    MATRIX _matrix;

public:
    /// @brief Инициализация матрицы
    /// @tparam T Тип элементов матрицы
    /// @param nRow Количество строк
    /// @param nCol Количество столбцов
    Matrix(unsigned int nRow, unsigned int nCol);
    Matrix(const Matrix<T> &matrix);
    ~Matrix();

    /// @brief Получение заданной строки
    /// @param index 
    /// @return Строка с заданным индексом
    std::vector<T> &operator[](unsigned int index)
    {
        return _matrix[index % _matrix.size()];
    }

    /// @return Количество строк матрицы
    int getNRow();
    /// @return Количество столбцов матрицы
    int getNCol();

    /// @brief Вывод матрицы
    void print();

    /// @brief Удаление строки
    /// @param index Индекс строки
    /// @return true, если строка удалена, иначе false
    bool removeRow(int index);

    /// @brief Удаление столбца
    /// @param index Индекс столбца
    /// @return true, если столбец удалён, иначе false
    bool removeCol(int index);

    /// @brief Получение подматрицы путём удаления i-ой строки и j-го столбца
    /// @param i Индекс строки
    /// @param j Индекс столбца
    /// @return Подматрица
    Matrix subMatrix(int i, int j);

    /// @brief Вычисления минора
    /// @param i Индекс строки минора
    /// @param j Индекс столбца минора
    /// @return Минор i-ой строки j-го столбца
    T minor (unsigned int i, unsigned int j);

    /// @brief Вычисление определителя матрицы
    /// @return определитель матрицы, если матрица числовая, иначе 0
    float det();
};