#include "tree.h"

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

ListNode::ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}

TreeNode* BinaryTreeConverter::insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    
    if (value < root->val) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

TreeNode* BinaryTreeConverter::createRandomTree(int n) {
    TreeNode* root = nullptr;
    srand(time(0));
    
    for (int i = 0; i < n; ++i) {
        int randomValue = rand() % 100;
        root = insertNode(root, randomValue);
    }
    
    return root;
}

ListNode* BinaryTreeConverter::treeToDoublyList(TreeNode* root) {
    if (!root) return nullptr;
    
    ListNode* first = nullptr;
    ListNode* last = nullptr;
    TreeNode* current = root;
    ListNode* listNode = nullptr;
    
    while (current || !stack.empty()) {
        while (current) {
            stack.push(current);
            current = current->left;
        }
        
        current = stack.top();
        stack.pop();
        
        listNode = new ListNode(current->val);
        
        if (!first) {
            first = listNode;
        }
        
        if (last) {
            last->next = listNode;
            listNode->prev = last;
        }
        
        last = listNode;
        current = current->right;
    }
    
    return first;
}

void BinaryTreeConverter::printTree(TreeNode* root) {
    if (root) {
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }
}

void BinaryTreeConverter::printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val;
        if (current->next) {
            std::cout << " - ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

void runTreeTask() {
    BinaryTreeConverter converter;
    int n;
    
    std::cout << "Введите количество элементов в бинарном дереве: ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "Количество элементов должно быть положительным числом!" << std::endl;
        return;
    }
    
    TreeNode* root = converter.createRandomTree(n);
    
    std::cout << "\nИнфиксный обход бинарного дерева (отсортированный порядок):\n";
    converter.printTree(root);
    std::cout << std::endl;
    
    ListNode* head = converter.treeToDoublyList(root);
    
    std::cout << "\nРезультат преобразования в двусвязный список:\n";
    converter.printList(head);
}