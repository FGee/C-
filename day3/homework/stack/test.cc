#include "stack.h" 

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(12);
    stack.push(14);
    
    cout << "top stack elem is " << stack.top() << endl;
    
    stack.pop();

    cout << "top stack elem is " << stack.top() << endl;

    return 0;
}
