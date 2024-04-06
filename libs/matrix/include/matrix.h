#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;

public:
    Matrix(const std::vector<std::vector<double>>& matrix) : data(matrix) {}
    Matrix(const int size);

    void display() const;
    void inverse();
};