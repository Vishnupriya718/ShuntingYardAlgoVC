#include <iostream>
#include "Stackqueue.h"

using namespace std;

int main(){

    Stack s;

    if(s.empty())
        cout << "Stack is empty" << endl;

    s.push('3');

    if(!s.empty())
        cout << "Stack is not empty" << endl;

    return 0;
}

   
   

   
