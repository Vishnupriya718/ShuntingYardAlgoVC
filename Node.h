#ifndef NODE_H
#define NODE_H

// Node class used for stack, queue, and binary tree
class Node{
public:
    char data;

    // pointer used for stack and queue
    Node* next;

    // pointers used for binary expression tree
    Node* left;
    Node* right;

    // constructor
    Node(char val){
        data = val;
        next = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

#endif
