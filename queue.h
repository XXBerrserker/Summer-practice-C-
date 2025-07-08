#pragma once
#include <stack>
#include <iostream>

class QueueUsingStacks {
private:
    std::stack<int> enqueueStack;  
    std::stack<int> dequeueStack;  

public:
    void enqueue(int x);
    bool dequeue(int& result);
    void print();
};

void runQueueTask();