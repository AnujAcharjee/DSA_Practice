#include <iostream>
#include <string>
using namespace std;

// std::move casts the object to an rvalue, allowing it to be "moved" rather than copied.
// memory efficient - incase of large data.
void swap(int &a, int &b)
{
    int tmp = move(a); // a moved to tmp, a memory empty
    a = move(b);       // b moved to a, b empty
    b = move(tmp);     // temp moved to b, temp empty
}

string printMe() // function
{
    return "I am print";
};

int main()
{
    int a = 5, b = 6;

    swap(a, b);

    cout << "a:" << a << " b:" << b << endl;

    string s = printMe(); // stores a copy of the string returned by printMe().
    cout << s << endl;

    string &&ss = printMe();
    // is binding an rvalue reference to the temporary string returned by printMe().
    // This avoids copying the string, and instead, it directly references the temporary object.
    cout << ss << endl;

    return 0;
}