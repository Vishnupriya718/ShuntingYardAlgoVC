#include <iostream>
#include "Stackqueue.h"
#include <sstream>
#include <stack>
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

void printPrefix(Node* root){
  if(!root) return;
  cout<< root->data << "";
  printPrefix(root->left);
  printPrefix(root->right);
}

void printInfix(Node* root){
  if(!root) return;
  printInfix(root->left);
  printPrefix(root->right);
}


void printPostfix(Node* root){
  if(!root) return;
  printPostfix(root->left);
  printPostfix(root->right);
  cout << root->data << "";
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
      // if operator to the handle precendence
      else if (isOperator(c)){
	while (!operators.empty() &&
	       precedence(operators.peek()) >= precedence(c)){

	  output.enqueue(operators.pop());
	}

	operators.push(c);
      }
      
 }
    // moving the operators first
    while(!operators.empty()){
	output.enqueue(operators.pop());
      }
    

    // print queue after loop 
    cout <<"Postfix: ";
    
    while(!output.empty()){
      cout << output.dequeue() << " ";
    }
			   

    cout << endl;

    stack<Node*> treeStack;
    Queue tempQueue = output;// copies the output for treebuilding

    while(!tempQueue.empty()){
      char c = tempQueue.dequeue();

      if(isdigit(c)){
	treeStack.push(new Node(c));
      }
      else if(isOperator(c)){
	Node* right = treeStack.top(); treeStack.pop();
	Node* left  = treeStack.top(); treeStack.pop();

	Node* opNode = new Node(c);
	opNode->left = left;
	opNode->right = right;

	treeStack.push(opNode);
      }
    }

    Node* root = treeStack.top();

    cout << "Prefix: ";
    printPrefix(root);
    cout << endl;

    cout << "Infix: ";
    printInfix(root);
    cout << endl;

    cout << "Postfix (tree): ";
    printPostfix(root);
    cout << endl;





    
    return 0;
}

