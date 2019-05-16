#include <string.h>

#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
    Student(const char *name, int id) : _name(new char[strlen(name) + 1]), _id(id)
    {
        cout << "Student()" << endl;
        strcpy(_name, name);
    }

    void* operator new(size_t size)
    {
        cout << "operator new()" << endl;
        void* ret = malloc(size);
        return ret;
    }

    void destroy()
    {
        delete this;
    }

    void operator delete(void *ret)
    {
        cout << "operator delete()" << endl;
        free(ret);
    }

    void print() const
    {
        cout << "name " << _name  << "  " << "id " << _id 
            << endl;
    }

private:
    ~Student()
    {
        delete [] _name;
        cout << "~Student" << endl;
    }
private:
    char * _name;
    int _id;
};

int main()
{
    Student * pstu = new Student("xiaoqi", 789798);

    //Student stu("lihua", 123456);
    //stu.print();
    pstu->print();
    pstu->destroy();

    return 0;
}

