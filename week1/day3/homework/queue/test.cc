#include "queue.h"

int main()
{
    Queue queue;
    
    cout << "if queue is empty " << queue.empty() << endl;

    queue.push(1);

    queue.push(2);

    queue.push(3);

    queue.push(4);
    cout << "the front is " << queue.front() << endl;
    cout << "the back is " << queue.back() << endl;

    queue.push(5);
    cout << "if queue is full " << queue.full() << endl;
    queue.push(6);

    queue.pop();
    cout << "the front is " << queue.front() << endl;

    return 0;
}

