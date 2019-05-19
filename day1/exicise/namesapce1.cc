#include <stdio.h>
#include <iostream>

namespace wd
{
int number = 10;//实体

void display()
{
	std::cout << "display()" << std::endl;//:: 作用域限定符
}

}//end of namespace wd
 
using namespace wd;

void cout()
{
	//printf("hello,world\n");
	std::cout << "cout()" << std::endl;
}

int main(void)
{
	display();
	cout();

	return 0;
}
