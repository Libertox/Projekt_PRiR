#include "matrix.h"
#include <vector>
#include <cmath>


Matrix::Matrix(const int size){
    data = std::vector<std::vector<double>>(size, std::vector<double>(size, 0));
    srand(time(nullptr));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            data[i][j] = static_cast<double>(rand()) / RAND_MAX * 10.0;
        }
    }
}

std::vector<std::vector<double>> Matrix::get_data(){
    return data;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (data[0].size() != other.data.size()) {
        std::cout << "Matrix dimensions incompatible for multiplication\n";
        return Matrix(data[0].size());
    }

    Matrix result(data.size());
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < other.data[0].size(); ++j) {
            double sum = 0;
            for (int k = 0; k < other.data.size(); ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

void Matrix::display() const{
     for (const auto& wiersz : data) {
            for (double element : wiersz) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
}

void Matrix::inverse(){
       int size = data.size();

        std::vector<std::vector<double>> inverse_matrix(size, std::vector<double>(size, 0));

        for (int i = 0; i < size; ++i) {
            inverse_matrix[i][i] = 1;
        }

        std::vector<std::vector<double>> temp_matrix = data;

        for (int k = 0; k < size; ++k) {
            int max_row = k;
            for (int i = k + 1; i < size; ++i) {
                if (std::abs(temp_matrix[i][k]) > std::abs(temp_matrix[max_row][k])) {
                    max_row = i;
                }
            }

            if (max_row != k) {
                std::swap(temp_matrix[k], temp_matrix[max_row]);
                std::swap(inverse_matrix[k], inverse_matrix[max_row]);
            }

            double divisor = temp_matrix[k][k];
            for (int j = 0; j < size; ++j) {
                temp_matrix[k][j] /= divisor;
                inverse_matrix[k][j] /= divisor;
            }

            for (int i = 0; i < size; ++i) {
                if (i != k) {
                    double multiplier = temp_matrix[i][k];
                    for (int j = 0; j < size; ++j) {
                        temp_matrix[i][j] -= multiplier * temp_matrix[k][j];
                        inverse_matrix[i][j] -= multiplier * inverse_matrix[k][j];
                    }
                }
            }
        }
        data = inverse_matrix;

}

void Matrix::round(){
     for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            data[i][j] = std::round(data[i][j]);
        }
    }
}