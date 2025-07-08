#pragma once
#include <iostream>

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int val);
void removeLastOccurrence(Node*& head, int k);
void printList(Node* head);
void deleteList(Node*& head);
void runListTask();
