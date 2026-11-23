#include <iostream>
using namespace std;

class A
{
    int i_;

public:
    A(int i) : i_(i) {} // Constructor
    int get() const { return i_; }
    void set(int j) { i_ = j; }
};

void print(char *str) { cout << str << endl; }

int main()
{
    const char *c = "sample text";
    // print(c); // error: ’void print(char *)’: cannot convert argument 1 from 'const char *' to 'char *'
    // This line produces an error because print expects a char*, but c is a const char*.
    print(const_cast<char *>(c)); // remove the const qualifier from c

    const A a(1); // constant object - value and state can't be modified
    cout << a.get() << endl;

    // a.set(5); // error: 'void A::set(int)': cannot convert 'this' pointer from 'const A' to 'A &'
    // This line fails because a is a const A, so set cannot be called on it. The set method is non-const, and calling it would attempt to modify the object, which is not allowed for a const instance.

    const_cast<A &>(a).set(5); // const_cast is used to remove the const qualifier from a
    cout << a.get() << endl;

    // const_cast<A>(a).set(5); // error: 'const_cast': cannot convert from 'const A' to 'A'
    // This line fails because const_cast can only modify const or volatile qualifiers on references or pointers, not on objects directly.
    // Attempting to cast const A to a non-const A with const_cast results in an error because const_cast cannot create a copy without const.
}
