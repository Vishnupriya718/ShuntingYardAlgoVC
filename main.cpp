#include <iostream>
#include "Stackqueue.h"
#include <stack>
using namespace std;

// precedence
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

// prefix
void printPrefix(Node* root){
    if(!root) return;
    cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// infix
void printInfix(Node* root){
    if(!root) return;
    printInfix(root->left);
    cout << root->data << " ";
    printInfix(root->right);
}

// postfix
void printPostfix(Node* root){
    if(!root) return;
    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->data << " ";
}

int main(){

    Stack operators;
    Queue output;

    cout << "Enter expression (with spaces): ";

    char c;

    // READ CHARACTER BY CHARACTER
    while(cin >> c){

        if(isdigit(c)){
            output.enqueue(c);
        }
        else if(isOperator(c)){
            while(!operators.empty() &&
                  precedence(operators.peek()) >= precedence(c)){
                output.enqueue(operators.pop());
            }
            operators.push(c);
        }
        else if(c == '='){  
            break;  // use '=' to end input
        }
    }

    // move remaining operators
    while(!operators.empty()){
        output.enqueue(operators.pop());
    }

    // BUILD TREE FROM POSTFIX
    stack<Node*> treeStack;

    while(!output.empty()){
        char val = output.dequeue();

        if(isdigit(val)){
            treeStack.push(new Node(val));
        }
        else if(isOperator(val)){
            Node* right = treeStack.top(); treeStack.pop();
            Node* left  = treeStack.top(); treeStack.pop();

            Node* opNode = new Node(val);
            opNode->left = left;
            opNode->right = right;

            treeStack.push(opNode);
        }
    }

    Node* root = treeStack.top();

    // OUTPUT FROM TREE
    cout << "Prefix: ";
    printPrefix(root);
    cout << endl;

    cout << "Infix: ";
    printInfix(root);
    cout << endl;

    cout << "Postfix: ";
    printPostfix(root);
    cout << endl;

    return 0;
}
