#include <iostream>
#include <string>

using namespace std;

int constCount = 0;
int copyCount = 0;
int assignCount = 0;

class Rectangle
{
    double _length = 0;
    double _breadth = 0;

public:
    // * Constructor function to initialize the obj -> name it same as the Class
    // has no return type , not even void
    // gets the pointer to the memory where the obj is created
    Rectangle(double l, double b) : _length(l), _breadth(b)
    {
        ++constCount;
        cout << constCount << " Constructor called " << " l= " << l << " b= " << b << endl;
    }

    // * Copy constructor -> invokes when we refer by value
    // Copies the referred object
    Rectangle(const Rectangle &r) : _length(r._length), _breadth(r._breadth)
    {
        ++copyCount;
        cout << copyCount << " copy constructor called " << " l=" << _length << " b= " << _breadth << endl;
    }

    // * Copy assignment operator
    Rectangle &operator=(const Rectangle &r)
    {
        if (this == &r) // Check for self-assignment
            return *this;

        _length = r._length;
        _breadth = r._breadth;

        ++assignCount;
        cout << assignCount << " copy assignment operator called" << " l=" << _length << " b= " << _breadth << endl;

        return *this; // Return the current object - for chained assignment.
    }

    //* Destructor -> invoked automatically after the object scope ends.
    // if not defined - compile uses a free destructor to free up memory
    ~Rectangle() { cout << " memory deallocation complete " << " l=" << _length << " b= " << _breadth << endl; }

    //* Member functions
    double area() { return _length * _breadth; }

    bool compare(Rectangle r) // refer by value -> copy constructor will get invoked.
    {
        puts("compare called\n");
        return this->area() > r.area();
    };
};

int main()
{
    Rectangle r1(3.2, 4.33); // Initialise the  Obj - the constructor fun get called automatically.
    Rectangle r2(4.77, 4.3); // Constructor call

    Rectangle r3(r1), // copy constructor call
        r4 = r3;      // copy constructor call

    Rectangle r5(0, 0); // constructor call

    r5 = r2; // copy assignment -> operates from right.
    r4 = r3 = r2; // copy assignment operator call 

    if (r1.compare(r2))
    {
        cout << "r1 > r2" << endl;
    }
    else
    {
        cout << "r1 < r2" << endl;
    };

    return 0;
}

// by observing the construction and deletion process we can say that memory is allocated in Stack (LIFO).

// 1 Constructor called  l= 3.2 b= 4.33
// 2 Constructor called  l= 4.77 b= 4.3
// 1 copy constructor called  l=3.2 b= 4.33
// 2 copy constructor called  l=3.2 b= 4.33
// 3 Constructor called  l= 0 b= 0
// 1 copy assignment operator called l=4.77 b= 4.3
// 2 copy assignment operator called l=4.77 b= 4.3
// 3 copy assignment operator called l=4.77 b= 4.3
// 3 copy constructor called  l=4.77 b= 4.3
// compare called

//  memory deallocation complete  l=4.77 b= 4.3
// r1 < r2
//  memory deallocation complete  l=4.77 b= 4.3
//  memory deallocation complete  l=4.77 b= 4.3
//  memory deallocation complete  l=4.77 b= 4.3
//  memory deallocation complete  l=4.77 b= 4.3
//  memory deallocation complete  l=3.2 b= 4.33