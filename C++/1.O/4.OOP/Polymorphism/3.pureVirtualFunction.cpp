#include <iostream>
using namespace std;

// pure-virtual function - dont have a body (but compiler allow) - can't have any instance.
// abstract Class - contain pure virtual fns

class Shapes // Abstract Base Class
{
public:
    virtual void draw() = 0; // Pure Virtual Function
};

class Polygon : public Shapes // Concrete class
{
public:
    void draw() { cout << "Polygon: Draw by Triangulation" << endl; }
};

class Triangle : public Polygon // Concrete class
{
public:
    void draw() { cout << "Triangle: Draw by Lines" << endl; }
};

class Quadrilateral : public Polygon // Concrete class
{
public:
    void draw() { cout << "Quadrilateral: Draw by Lines" << endl; }
};

class ClosedConics : public Shapes // Abstract Class
{
public:
    // draw() inherited - Pure Virtual fn
};

int main()
{
    Shapes *arr[] = {new Triangle, new Quadrilateral};
    for (int i = 0; i < sizeof(arr) / sizeof(Shapes *); ++i)
        arr[i]->draw();

    return 0;
}