#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include "Node.h"
#include <iostream>
using namespace std;


// STACK CLASS
class Stack{
public:

    Node* top = nullptr;

    void push(char value){
        Node* temp = new Node(value);
        temp->next = top;
        top = temp;
    }

    char peek(){
        if(top == nullptr)
            return '\0';

        return top->data;
    }

    char pop(){

        if(top == nullptr)
            return '\0';

        Node* temp = top;
        char value = temp->data;

        top = top->next;

        delete temp;

        return value;
    }

    bool empty(){
        return top == nullptr;
    }
};   // ← IMPORTANT


// QUEUE CLASS
class Queue{
public:

    Node* front = nullptr;
    Node* rear = nullptr;

    void enqueue(char value){

        Node* temp = new Node(value);

        if(rear == nullptr){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }

    char dequeue(){

        if(front == nullptr)
            return '\0';

        Node* temp = front;
        char value = temp->data;

        front = front->next;

        if(front == nullptr)
            rear = nullptr;

        delete temp;

        return value;
    }

    bool empty(){
        return front == nullptr;
    }
};   // ← IMPORTANT

#endif
