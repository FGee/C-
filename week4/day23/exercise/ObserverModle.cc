#include <stdlib.h>

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::find;
using std::string;
using std::unique_ptr;

class Observer;
class Subject
{
public:
    virtual 
        void attach(Observer* ober) = 0;
    virtual 
        void dettach(Observer* ober) = 0;
    virtual
        void notifyall() = 0;
    virtual
        ~Subject() {};
};

class Observer
{
public:
    virtual
        void update() = 0;
    string& name()
    {
        return _name;
    }
    string _name;
};

class Ring
: public Subject
{
public:
    void alarm()
    {
        notifyall();  
    }
    void attach(Observer* ober)
    {
        auto retIter = std::find(_oberList.begin(), _oberList.end(), ober);
        if (retIter != _oberList.end()) {
            return;
        } else {
            _oberList.push_back(ober);
        }
    }
    void dettach(Observer* ober)
    {
        auto retIter = std::find(_oberList.begin(), _oberList.end(), ober);
        if (retIter == _oberList.end()) {
            return;
        } else {
            auto begIter = _oberList.begin();
            auto endIter = _oberList.end();
            for (; begIter != endIter; ++begIter) {
                if (*begIter == ober) {
                    _oberList.erase(begIter);
                    return;
                }
            }
        }
    }
    void notifyall()
    {
        auto begIter = _oberList.begin();
        auto endIter = _oberList.end();
        for (; begIter != endIter; ++begIter) {
            (*begIter)->update();
        }
    }
private:
    list<Observer*> _oberList;
};

class Baby
: public Observer
{
public:
    Baby(string name) { _name = name; }
    void update()
    {
        ::srand(::clock());
        int random = ::rand() % 100;
        if (random > 70) {
            cout << "Baby: " << _name << "sleep sweety" << endl;
        } else {
            cout << "Baby: " << _name << "is crying aloud" << endl;
        }
    }
};

class Nurse
: public Observer
{
public:
    Nurse(string name) { _name = name; }
    void update() {
        ::srand(::clock());
        int random = ::rand() % 100;
        if (random > 70) {
            cout << "Nurse: " << _name << "is aweak and going to look" << endl;
        } else {
            cout << "Nurse: " << _name << "sleeps sweety" << endl;
        }
    }
};

class Guest
{
public:
    Guest(string name) : _name(name) {}
    void ring(Ring* ring)
    {
        cout << "Guest: " << _name << " is knock the door and ring " << endl;
        ring->alarm();
    }
private:
    string _name;
};

int main()
{
    unique_ptr<Baby> baby1(new Baby("huanhuan"));
    unique_ptr<Baby> baby2(new Baby("xinxin"));
    unique_ptr<Baby> baby3(new Baby("dongdong"));

    unique_ptr<Nurse> nurse1(new Nurse("xiao li"));
    unique_ptr<Nurse> nurse2(new Nurse("liu xin"));
    
    unique_ptr<Ring> ring(new Ring);
    ring->attach(baby1.get());
    ring->attach(baby2.get());
    ring->attach(baby3.get());
    ring->attach(nurse1.get());
    ring->attach(nurse2.get());

    //unique_ptr<Guest> guest1(new Guest("lao wang"));
    //guest1->ring(ring.get());

    cout << "nurse1 is left" << endl;
    ring->dettach(nurse1.get());

    unique_ptr<Guest> guest1(new Guest("lao wang"));
    guest1->ring(ring.get());
    
    return 0;
}

