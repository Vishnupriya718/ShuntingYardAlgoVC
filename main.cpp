#include <iostream>
#include "Stackqueue.h"

// returns precedence of operators
int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}
int main(){

    Stack s;
    Queue q;

    cout << "Queue created successfully" << endl;
    cout << precedence('+') << endl;
    cout << precedence('*') << endl;
    cout << precedence('^') << endl;
    return 0;
}
