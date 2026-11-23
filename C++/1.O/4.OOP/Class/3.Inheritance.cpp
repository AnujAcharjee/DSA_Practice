#include <iostream>
#include <string>

using namespace std;


// Protected: Base class , Derived class/ Child classes allowed.

// Inheritance: Derived class 
// inherit all member fun of Base class - Public and protected only
// Overriding - not Constructor as it is a Static fn & Destructor
// Overloading of only Non-static members 

class Utility
{
public:
    void inheritance() { puts("multiple inheritance of classes also valid"); }
};

class Car  // Base class
{
    string _name;
    string _price;
    Car() {}; // private default constructor - can't call by member fns.

protected:
    Car(const string &name, const string &price) // Protected constructor - can be used by derived classes only
        : _name(name), _price(price) {};

    void startCar() { puts("Car started"); }

public:
    // constant member function -> here we can't change the state of the  object 
    void introduce() const;
};

void Car::introduce() const { cout << "hello! car owner's name is " << _name << " and price is " << _price << endl; }

// Derived class
class Sedan : public Car, public Utility
{
    bool isAvailable;

public:
    Sedan(string name) : Car(name, "10L") {} // Call the base class constructor

    void startCar() { puts("Sedan started"); } // Override allowed - startCar method in Car overriden
};

// Derived class
class Nano : public Car
{
    bool isBigEnough;

public:
    Nano(string name) : Car(name, "2L") {}
    void startCar() { puts("Nano started"); }
};

int main()
{
    // Car car("Lamin", "1B");

    // The Car class has a private default constructor.
    // so the object Car car("Lamin", "1B"); will fail to compile because the constructor is not accessible directly.
    // only be accessed by derived classes or members of the same class.

    // Sedan object
    Sedan sedan("Anuj");
    sedan.introduce();
    sedan.startCar();
    sedan.inheritance();

    // Nano object
    Nano nano("Gavi");
    nano.introduce();
    nano.startCar();

    return 0;
}