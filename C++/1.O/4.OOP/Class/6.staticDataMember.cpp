#include <iostream>
#include <string>

using namespace std;

class Data
{
    string id_;

public:
    Data(const string &id) : id_(id) { cout << "Constructor: " << id_ << endl; }
    ~Data() { cout << "Destructor: " << id_ << endl; }
};

class MyClass
{
    static int x; // Declared static member - shared by all MyClass objects - any change in one obj wii show in other.
public:
    void get() { x = 15; }
    void print()
    {
        x = x + 10;
        cout << "x= " << x << endl;
    }

    static Data d2_; // order of static members when swapped.
    static Data d1_;
};

// Define static data member - in global scope
// initialized during program start.

int MyClass::x = 0;

Data MyClass::d1_("obj_1"); // constructed 1st
Data MyClass::d2_("obj_2"); // constructed 2nd
// Don't depends upon how they are initialised in class.

int main()
{
    MyClass obj1, obj2; // both have same x

    obj1.get(); // 15
    obj2.get(); // 25

    obj1.print(); // x= 25
    obj2.print(); // x= 35

    return 0;
}

// static member fuctions don't have this pointer.
// So we can't access non  static data members in static functions.