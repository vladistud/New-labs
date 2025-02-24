#include <iostream>

using namespace std;

void sortMatrixBySecondRow(int** matrix, int rows, int cols) {
    for (int i = 0; i < cols - 1; ++i) {
        for (int j = 0; j < cols - i - 1; ++j) {
            if (matrix[1][j] > matrix[1][j + 1]) {
                for (int k = 0; k < rows; ++k) {
                    swap(matrix[k][j], matrix[k][j + 1]);
                }
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    int data[3][4] = {
        {3, 1, 4, 2},
        {9, 7, 5, 6},
        {8, 3, 2, 1}
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = data[i][j];
        }
    }

    cout << "Исходная матрица:\n";
    printMatrix(matrix, rows, cols);

    sortMatrixBySecondRow(matrix, rows, cols);

    cout << "\nОтсортированная матрица:\n";
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
