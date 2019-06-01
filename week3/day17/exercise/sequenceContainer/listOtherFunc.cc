#include <iostream>
#include <list>
#include <utility>

using std::cout;
using std::endl;
using std::cin;
using std::list;

template <typename Container>
void display(const Container& con) {
    typename Container::const_iterator begIter = con.begin();
    while(begIter != con.end()) {
        cout << *begIter << endl;
        ++begIter;
    }
}

void test1()
{
    cout << "-------------------list1---------------------" << endl;
    list<int> lst1{3, 6, 2, 3, 4, 7, 6, 9, 7, 2, 1, 4, 5};
    display(lst1);
    cout << "-------------------list2---------------------" << endl;
    list<int> lst2(3, 666);
    display(lst2);
    //cout << "-------------------list1 & list2 merge---------------------" << endl;
    //lst1.merge(lst2);
    //display(lst1);
    cout << "-------------------splice---------------------" << endl;
   // //lst2.splice(lst2.begin(), lst1);
   // auto lst1Iter = lst1.begin();
   // ++lst1Iter;
   // ++lst1Iter;
   // ++lst1Iter;
   // lst2.splice(lst2.begin(), lst1, lst1Iter, lst1.end());
    
    //cout << "-------------------list1---------------------" << endl;
    //display(lst1);
    //cout << "-------------------list2---------------------" << endl;
    //display(lst2);
    //cout << "-------------------list1 reverse---------------------" << endl;
    //lst1.reverse();
    //cout << "-------------------list1---------------------" << endl;
    //display(lst1);

    cout << "-------------------list1 sort---------------------" << endl;
    lst1.sort();
    cout << "-------------------list1---------------------" << endl;
    display(lst1);
    cout << "-------------------list1 sort---------------------" << endl;
    lst1.sort(std::greater<int>());
    std::greater<int> gt;
    lst2.sort(gt);
    cout << "-------------------list1---------------------" << endl;
    display(lst1);

    lst1.unique();
    cout << "-------------------list1---------------------" << endl;
    display(lst1);
}

int main()
{
    test1();

    return 0;
}

