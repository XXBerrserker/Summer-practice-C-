#include "list.h"

void append(Node*& head, int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeLastOccurrence(Node*& head, int k) {
    if (head == nullptr) return;

    Node* last = nullptr;
    Node* prevLast = nullptr;
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == k) {
            prevLast = prev;
            last = current;
        }
        prev = current;
        current = current->next;
    }

    if (last != nullptr) {
        if (prevLast == nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            prevLast->next = last->next;
            delete last;
        }
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << " - ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void runListTask() {
    Node* head = nullptr;
    int n, k, num;

    std::cout << "Введите количество чисел в списке: ";
    std::cin >> n;

    std::cout << "Введите " << n << " чисел:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        append(head, num);
    }

    std::cout << "Созданный список: ";
    printList(head);

    std::cout << "Введите число k для удаления его последнего вхождения: ";
    std::cin >> k;

    removeLastOccurrence(head, k);

    std::cout << "Список после удаления: ";
    printList(head);

    deleteList(head);
}