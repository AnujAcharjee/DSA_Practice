#include <iostream>
#include <string>

using namespace std;

// In Polymorphic hierarchy, Base destructor should be virtual
// if not, Base part get destroyed but rest remains (Called Slicing) 

class Base
{
    int data_;

public:
    Base(int d) : data_(d) { cout << "Base()" << endl; }
    virtual ~Base() { cout << "~Base()" << endl; }  // virtual destructor
    virtual void print() { cout << data_; }
};

class Derived : public Base
{
    int *ptr_;

public:
    Derived(int d1, int d2) : Base(d1), ptr_(new int(d2)) { cout << "Derived()" << endl; }
    ~Derived() { cout << "~Derived" << endl, delete ptr_; }
    void print()
    {
        Base::print();
        cout << " " << *ptr_;
    }
};

int main()
{
    Base *p = new Base(2);
    Base *q = new Derived(3, 5);

    p->print();
    cout << endl;
    q->print();
    cout << endl;

    delete p;
    delete q;

    return 0;
}
