#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x);
};

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x);
};

class BinaryTreeConverter {
private:
    std::stack<TreeNode*> stack;
    TreeNode* insertNode(TreeNode* root, int value);
    
public:
    TreeNode* createRandomTree(int n);
    ListNode* treeToDoublyList(TreeNode* root);
    void printTree(TreeNode* root);
    void printList(ListNode* head);
};

void runTreeTask();
