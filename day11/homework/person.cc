#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person
{
public:
    Person(string name, int age) 
        : _name(name), _age(age)
    {
        cout << "Person()" << endl;
    }
    ~Person() { cout << "~Person()" << endl; }

    virtual
    void display()
    {
        cout << "Name: " << _name << " Age: " << _age << endl;
    }
private:
    string _name;
    int _age;
};

class Employee
: protected Person
{
public:
    Employee(string name, int age, string department, float salary)
        : Person(name, age), _department(department), _salary(salary)
    {
        cout << "Employee(string, int, string, float)" << endl;
    }

    void display()
    {
        Person::display();
        cout << "Department: " << _department << "  Salary: " << _salary << endl;
    }

    float getSalary() { return _salary; }

private:
    string _department;
    float _salary;
};

void test0()
{
    Person per0("xiaoli", 22);
    per0.display();
}

void test1()
{
    Employee em1("xioli", 22, "develop department", 12000);
    Employee em2("fuxin", 21, "market department", 10000);
    Employee em3("liuhu", 25, "goverment department", 18000);
    
    em1.display();
    em2.display();
    em3.display();

    cout << "Average salary: " << (em1.getSalary() + em2.getSalary() + em3.getSalary()) / 3 << endl;
}

int main()
{
    //test0();
    
    test1();

    return 0;
}

