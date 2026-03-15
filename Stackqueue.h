#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include "Node.h"
#include <iostream>
using namespace std;

class Stack{
public:
    Node* top = nullptr;

    // push element onto stack
    void push(char value){
        Node* temp = new Node(value);
        temp->next = top;
        top = temp;
    }

    // look at top element
    char peek(){
        if(top == nullptr)
            return '\0';

        return top->data;
    }

    // remove top element
    char pop(){

        if(top == nullptr)
            return '\0';

        Node* temp = top;
        char value = temp->data;

        top = top->next;

        delete temp;

        return value;
    }
};

#endif
   
