#include "hw1.h"

using namespace algebra;

Matrix algebra::zeros(size_t n, size_t m)
{
    Matrix matrix;
    matrix.resize(n);
    for (int i = 0;i < n; i++)
    {
        matrix[i].resize(m, 0);
    }
    return matrix;
}

Matrix algebra::ones(size_t n, size_t m)
{
    Matrix matrix;
    matrix.resize(n);
    for (int i = 0;i < n; i++)
    {
        matrix[i].resize(m, 1);
    }
    return matrix;
}

Matrix algebra::random(size_t n, size_t m, double min, double max)
{
    std::uniform_real_distribution<double> random(min, max);
    std::default_random_engine s;
    s.seed(time(0));
    Matrix matrix;
    matrix = zeros(n, m);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            matrix[i][j] = random(s);
        }
    }
    return matrix;
}

void algebra::show(const Matrix& matrix) {
    // 设置输出格式，以显示有 3 位小数的数字
    std::cout << std::fixed << std::setprecision(3);
    size_t matrix_line = matrix.size();
    size_t matrix_row = matrix[0].size();
    for(size_t line = 0; line < matrix_line; line++) {
        for(size_t row = 0; row < matrix_row; row++) {
            std::cout << matrix[line][row];
            if (row < matrix_row - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}