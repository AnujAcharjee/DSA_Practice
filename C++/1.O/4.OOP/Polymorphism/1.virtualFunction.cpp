#include <iostream>
#include <string>

using namespace std;

// virtual: tells compiler to call the derived class fn, not the base class
// virtual-ness get inherited downwards.
// a fn can be converted from Non-virtual to virtual, but not reverse.
class One
{
public:
    virtual void intro() { puts("I'm One\n"); }
    // virtual keyword in the base class One, allows derived class objects (Two, Three) to override the intro() method.

    void f(int i) { cout << i << endl; }
};

class Two : public One
{
public:
    void intro() { puts("I'm Two\n"); } // Overrides One::intro

    void f(string i) { cout << i << endl; } // Overload One::f
};

class Three : public One
{
public:
    void intro() { puts("I'm Three\n"); }
};

int main()
{
    One a;
    Two b;
    Three c;

    One *p;

    p = &a;
    p->intro(); // One::intro()
    p = &b;
    p->intro(); // Two::intro()
    p->f(11);

    // a->f("string"); // can't do - a don't have access of f
    b.f("Some string");

    p = &c;
    p->intro();

    return 0;
}