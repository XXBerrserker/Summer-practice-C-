#include "primes.h"

bool checkNumber(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int fillArr(int s, int e, int arr[], int size) {
    int count = 0;
    for (int i = s; i <= e && count < size; i++) {
        if (checkNumber(i)) {
            arr[count] = i;
            count++;
        }
    }
    return count;
}

void printArr(int arr[], int size) {
    if (size == 0) {
        std::cout << "Простых чисел не найдено" << std::endl;
        return;
    }
    std::cout << "Простые числа: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void runPrimesTask() {
    int ten;
    std::cout << "Введите десятку: ";
    std::cin >> ten;
    if (ten <= 0){
        std::cout << "Введите число больше нуля" << std::endl;
    }
    int startTen = (ten - 1) * 10;
    int endTen = startTen + 9;
    int arrTen[4];
    int numbersCount = fillArr(startTen, endTen, arrTen, 4);
    printArr(arrTen, numbersCount);
}