#pragma once
#include <iostream>

int** createMatrix(int size);
void fillMatrix(int** matr, int size);
void printMatrix(int** matr, int size);
void deleteMatrix(int** matr, int size);
bool sumRows(int** matr, int size);   
bool sumCols(int** matr, int size); 
bool isMagicSquare(int** matr, int size);
void runMagicSquareTask();