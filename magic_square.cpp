#include "magic_square.h"

int** createMatrix(int size) {
    int** matr = new int* [size];
    for (int i = 0; i < size; i++) {
        matr[i] = new int[size];
    }
    return matr;
}

void fillMatrix(int** matr, int size) {
    std::cout << "Введите элементы матрицы: " << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> matr[i][j];
        }
    }
}

void printMatrix(int** matr, int size) {
    std::cout << "Матрица: " << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int** matr, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matr[i];
    }
    delete[] matr;
}

bool sumRows(int** matr, int size) {
    if (size == 0) return false;
    int firstRowSum = 0;
    for (int j = 0; j < size; j++) {
        firstRowSum += matr[0][j];
    }
    for (int i = 1; i < size; i++) {
        int currentSum = 0;
        for (int j = 0; j < size; j++) {
            currentSum += matr[i][j];
        }
        if (currentSum != firstRowSum) {
            return false;
        }
    }
    return true;
}

bool sumCols(int** matr, int size) {
    if (size == 0) return false;
    int firstColSum = 0;
    for (int i = 0; i < size; i++) {
        firstColSum += matr[i][0];
    }
    for (int j = 1; j < size; j++) {
        int currentSum = 0;
        for (int i = 0; i < size; i++) {
            currentSum += matr[i][j];
        }
        if (currentSum != firstColSum) {
            return false;
        }
    }
    return true;
}

bool isMagicSquare(int** matr, int size) {
    if (!sumRows(matr, size)) return false;
    if (!sumCols(matr, size)) return false;    
    int magicSum = 0;
    for (int j = 0; j < size; j++) {
        magicSum += matr[0][j];
    }    
    int diagSum = 0;
    for (int i = 0; i < size; i++) {
        diagSum += matr[i][i];
    }
    if (diagSum != magicSum) return false;    
    int antiDiagSum = 0;
    for (int i = 0; i < size; i++) {
        antiDiagSum += matr[i][size - 1 - i];
    }
    if (antiDiagSum != magicSum) return false;
    return true;
}

void runMagicSquareTask() {
    int number;
    std::cout << "Введите размер квадратичной матрицы: " << std::endl;
    std::cin >> number;
    int** matrix = createMatrix(number);
    fillMatrix(matrix, number);
    printMatrix(matrix, number);
    if (isMagicSquare(matrix, number)) {
        std::cout << "Матрица является магической" << std::endl;
    }
    else {
        std::cout << "Матрица не является магической" << std::endl;
    }
    deleteMatrix(matrix, number);
}