#include "queue.h"

void QueueUsingStacks::enqueue(int x) {
    enqueueStack.push(x);
}

bool QueueUsingStacks::dequeue(int& result) {
    if (dequeueStack.empty()) {
        while (!enqueueStack.empty()) {
            dequeueStack.push(enqueueStack.top());
            enqueueStack.pop();
        }
    }
    
    if (dequeueStack.empty()) {
        std::cout << "Очередь пуста!\n";
        return false;
    }
    
    result = dequeueStack.top();
    dequeueStack.pop();
    return true;
}

void QueueUsingStacks::print() {
    std::stack<int> tempDeq = dequeueStack;
    while (!tempDeq.empty()) {
        std::cout << tempDeq.top() << " ";
        tempDeq.pop();
    }
    
    std::stack<int> tempEnq = enqueueStack;
    std::stack<int> reverse;
    while (!tempEnq.empty()) {
        reverse.push(tempEnq.top());
        tempEnq.pop();
    }
    while (!reverse.empty()) {
        std::cout << reverse.top() << " ";
        reverse.pop();
    }
    
    std::cout << std::endl;
}

void runQueueTask() {
    QueueUsingStacks queue;
    int choice, value;
    
    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1) Добавить элемент\n";
        std::cout << "2) Удалить элемент\n";
        std::cout << "3) Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Введите значение: ";
                std::cin >> value;
                queue.enqueue(value);
                std::cout << "Очередь: ";
                queue.print();
                break;
            case 2:
                if (queue.dequeue(value)) {
                    std::cout << "Удалено: " << value << "\n";
                    std::cout << "Очередь: ";
                    queue.print();
                }
                break;
            case 3:
                return;
            default:
                std::cout << "Неверный выбор!\n";
        }
    }
}