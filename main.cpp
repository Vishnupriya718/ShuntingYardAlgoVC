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

int main() {

    string expr = "3 + 4 * 2";

    Stack operators;
    Queue output;
    
    stringstream ss(expr);
    string token;

    //process tokens
    while(ss >> token){
      char c = token[0];

      if(isdigit(c)){
	output.enqueue(c);
	
    }
 }
    // print queue after loop 
    cout <<"Queue:";
    
    while(!output.empty()){
      cout << output.dequeue() << " ";
    } 

    cout << endl;

    return 0;
}

