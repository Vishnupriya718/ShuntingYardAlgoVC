#include <iostream>
#include "Stackqueue.h"

using namespace std;

int main(){

    Stack s;

    s.push('3');
    s.push('+');
    s.push('5');

    cout << "Pop: " << s.pop() << endl;
    cout << "Peek after pop: " << s.peek() << endl;

    return 0;
}

   
   

   
