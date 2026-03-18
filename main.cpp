#include <iostream>
#include "Stackqueue.h"
#include <sstream> 
using namespace std;

// precedence function
int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

// operator check
bool isOperator(char c){
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

int main(){

    string expr = "3 + 4 * 2";

    stringstream ss(expr);
    string token;

    while(ss >> token){
        cout << "Token: " << token << endl;
    }

    return 0;
}

