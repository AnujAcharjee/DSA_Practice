#include <iostream>
#include <string>

using namespace std;

// this -> is an implicit pointer, holds the address of an object.
// type of this pointer for a class X object is -> X * const this
// this pointer is only accessible to member functions only.

class X
{
public:
    int m1, m2;

    // member function
    void f(int k1, int k2)
    {
        m1 = k1;
        this->m2 = k2;
        cout << "Id: " << this << endl; // address same as the obj
    }
};

int main()
{
    X obj;
    obj.f(2, 3);

    cout << "Add: " << &obj << endl;
    cout << "obj.m1: " << obj.m1 << " obj.m2: " << obj.m2 << endl;

    X obj2;
    obj2.f(7, 8);
    cout << "Add2: " << &obj2 << endl;
    cout << "obj2.m1: " << obj2.m1 << " obj2.m2: " << obj2.m2 << endl;

    return 0;
}