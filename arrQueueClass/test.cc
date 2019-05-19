#include "arrQueue.h"

int main(void)
{
	Queue que;
	cout << "此时队列是否为空? " << que.empty() << endl;
	que.push(1);
	cout << "此时队列是否为空? " << que.empty() << endl;

	for(int idx = 2; idx != 12; ++idx) {
		que.push(idx);
	}
	cout << "此时队列是否已满? " << que.full() << endl;

	cout << ">> 队列头部的元素是: " << que.front() << endl;
	cout << ">> 队列尾部的元素是: " << que.back() << endl;
	cout << "执行元素出队和入队操作之后:" << endl;

	que.pop();
	que.push(10);
	cout << ">> 队列头部的元素是: " << que.front() << endl;
	cout << ">> 队列尾部的元素是: " << que.back() << endl;

	while(!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
	cout << "此时队列是否为空? " << que.empty() << endl;
	return 0;
}

