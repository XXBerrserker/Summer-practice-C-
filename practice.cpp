#include <iostream>
#include "tree.h"
#include "primes.h"
#include "magic_square.h"
#include "factorial.h"
#include "file.h"
#include "list.h"
#include "search.h"
#include "queue.h"

int main() {
    int choice;
    do {
        std::cout << "\nВыберите задачу для выполнения:\n";
        std::cout << "1. Поиск простых чисел в десятке\n";
        std::cout << "2. Проверка магического квадрата\n";
        std::cout << "3. Вычисление факториала больших чисел\n";
        std::cout << "4. Обработка научных тем (F, G, H файлы)\n";
        std::cout << "5. Работа со списком чисел\n";
        std::cout << "6. Работа с очередью на стеках\n";
        std::cout << "7. Преобразование бинарного дерева в список\n";
        std::cout << "8. Поиск наименьшего недостающего элемента\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1: runPrimesTask(); break;
            case 2: runMagicSquareTask(); break;
            case 3: runFactorialTask(); break;
            case 4: runFileTask(); break;
            case 5: runListTask(); break;
            case 6: runQueueTask(); break;
            case 7: runTreeTask(); break;
            case 8: runSearchTask(); break;
            case 0: std::cout << "Выход из программы.\n"; break;
            default: std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while(choice != 0);
    
    return 0;
}