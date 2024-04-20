#include <gtest/gtest.h>
#include "matrix.h"


TEST(matrix_ut, MatrixInverse)
{
    std::vector<std::vector<double>> data = {{3, 9, -4}, {1, 3, -1},{2, 5, -2}};

    std::vector<std::vector<double>> diagonal = {{1, 0, 0}, {0, 1, 0},{0, 0, 1}};

    Matrix matrix(data);
    Matrix inverse_matrix(data);
    Matrix diagonalMatrix(diagonal);

    inverse_matrix.inverse();

    Matrix expected = inverse_matrix * matrix;
    expected.round();

    EXPECT_EQ(expected.get_data(), diagonalMatrix.get_data());
}


