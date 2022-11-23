#include "Matrix.h"

TEMPLATE
Matrix<T>::Matrix(unsigned int nRow, unsigned int nCol)
{
    // Заполнение матрицы
    for (int i = 0; i < nRow; i++)
    {
        // Текущая строка
        std::vector<T> row;

        // Заполнение текущей строки
        for (int j = 0; j < nCol; j++)
        {
            T el;
            row.push_back(el);
        }

        // Добавление текущей строки в матрицу
        this->_matrix.push_back(row);
    }
}

TEMPLATE
Matrix<T>::Matrix(const Matrix<T> &matrix)
{
    _matrix = matrix._matrix;
}

TEMPLATE
int Matrix<T>::getNRow()
{
    return this->_matrix.size();
}
TEMPLATE
int Matrix<T>::getNCol()
{
    return this->_matrix[0].size();
}

TEMPLATE
void Matrix<T>::print()
{
    // Проход по строкам матрицы
    for (std::vector<T> row : this->_matrix)
    {
        // Проход по элементам строки
        for (T el : row)
        {
            std::cout << el << '\t';
        }

        // Перевод на новую строку
        std::cout << std::endl;
    }
}

TEMPLATE
bool Matrix<T>::removeRow(int index)
{
    // Если строки с данным индексом нет,
    if (this->getNRow() < index + 1)
    {
        // то вернуть false
        return false;
    }

    auto iterator = this->_matrix.begin();
    this->_matrix.erase(iterator + index);

    return true;
}

TEMPLATE
bool Matrix<T>::removeCol(int index)
{
    // Если столбца с данным индексом нет,
    if (this->getNCol() < index + 1)
    {
        // то вернуть false
        return false;
    }

    // Проход по строкам
    for (int i = 0; i < this->getNRow(); i++)
    {
        // Удаление заданного столбца
        auto iterator = this->_matrix[i].begin();
        this->_matrix[i].erase(iterator + index);
    }

    return true;
}

TEMPLATE
Matrix<T> Matrix<T>::subMatrix(int i, int j)
{
    Matrix<T> matrix = *this;

    // Удаление строки и столбца
    matrix.removeRow(i);
    matrix.removeCol(j);

    return matrix;
}

TEMPLATE
float Matrix<T>::det()
{
    float det;

    // Если матрица не квадратная,
    if (this->getNRow() != this->getNCol() || this->getNRow() == 0)
    {
        // то вернуть значение по умолчанию
        return det;
    }
    // Если порядок матрицы равен единицы,
    if (this->getNRow() == 1)
    {
        // то определитель равень единственному элементу матрицы
        return this->_matrix[0][0];
    }
    // Если порядок матрицы равен двум,
    if (this->getNRow() == 2)
    {
        // то определитель считается как разность
        // произведений главной и побочной диагоналей
        return this->_matrix[0][0] * this->_matrix[1][1] - this->_matrix[0][1] * this->_matrix[1][0];
    }

    // Если порядок матрицы более двух, то определитель
    // считается по формуле:
    // det A = a_11 * M_11 - a_12 * M_12 + ...
    int rowIndex = 0;
    for (int i = 0; i < this->getNCol(); i++)
    {
        det += pow(-1, rowIndex + i) * this->_matrix[rowIndex][i] * this->subMatrix(rowIndex, i).det();
    }

    return det;
}

TEMPLATE
Matrix<T>::~Matrix()
{
}
