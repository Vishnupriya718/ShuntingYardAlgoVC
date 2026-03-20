#include <iostream>
#include <cctype>
#include "Stackqueue.h"

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

// TREE STACK 
class TreeStackNode{
public:
    Node* treeNode;
    TreeStackNode* next;

    TreeStackNode(Node* n){
        treeNode = n;
        next = nullptr;
    }
};

class NodeStack{
public:
    TreeStackNode* top = nullptr;

    void push(Node* n){
        TreeStackNode* temp = new TreeStackNode(n);
        temp->next = top;
        top = temp;
    }

    Node* pop(){
        if(top == nullptr) return nullptr;

        TreeStackNode* temp = top;
        Node* val = temp->treeNode;

        top = top->next;
        delete temp;

        return val;
    }

    Node* peek(){
        if(top == nullptr) return nullptr;
        return top->treeNode;
    }

    bool empty(){
        return top == nullptr;
    }
};

//  TREE PRINTS 

// prefix
void printPrefix(Node* root){
    if(!root) return;
    cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// infix (WITH PARENTHESES)
void printInfix(Node* root){
    if(!root) return;

    if(isOperator(root->data)) cout << "( ";

    printInfix(root->left);
    cout << root->data << " ";
    printInfix(root->right);

    if(isOperator(root->data)) cout << ") ";
}

// postfix
void printPostfix(Node* root){
    if(!root) return;
    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->data << " ";
}

// MAIN 
int main(){

    Stack operators;
    Queue output;

    cout << "Enter expression (space separated, end with =): ";

    char c;

    // SHUNTING YARD
    while(cin >> c){

        if(isdigit(c)){
            output.enqueue(c);
        }
        else if(isOperator(c)){
            while(!operators.empty() &&
                 ((precedence(operators.peek()) > precedence(c)) ||
                 (precedence(operators.peek()) == precedence(c) && c != '^'))){
                output.enqueue(operators.pop());
            }
            operators.push(c);
        }
        else if(c == '('){
            operators.push(c);
        }
        else if(c == ')'){
            while(!operators.empty() && operators.peek() != '('){
                output.enqueue(operators.pop());
            }
            operators.pop(); // remove '('
        }
        else if(c == '='){
            break;
        }
    }

    // move remaining operators
    while(!operators.empty()){
        output.enqueue(operators.pop());
    }

    //  BUILD TREE 
    NodeStack treeStack;

    while(!output.empty()){
        char val = output.dequeue();

        if(isdigit(val)){
            treeStack.push(new Node(val));
        }
        else if(isOperator(val)){
            Node* right = treeStack.pop();
            Node* left  = treeStack.pop();

            if(left == nullptr || right == nullptr){
                cout << "Error: invalid expression" << endl;
                return 0;
            }

            Node* opNode = new Node(val);
            opNode->left = left;
            opNode->right = right;

            treeStack.push(opNode);
        }
    }

    Node* root = treeStack.pop();

    if(root == nullptr){
        cout << "Error: empty expression" << endl;
        return 0;
    }

    // OUTPUT
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
