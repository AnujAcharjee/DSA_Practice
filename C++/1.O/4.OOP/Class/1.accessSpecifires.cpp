#include <iostream>
#include <string>

using namespace std;

// Private: Base class allowed.
// Public: Base Class, Derived class, Others allowed.

// To store only variables use Struct. For both var. and methods use Class.
class User
{
    int _secret = 100; // Private by default
public:
    string name = "Default";
    void classMessage() { cout << "User name is " << name << endl; }
    void setSecret(const int &newSecret) { _secret = newSecret; } // setter
    int getSecret() { return _secret; }                           // getter
    void userMethod(); // method initialised
};

// member function of User class -> return type Void
// using scope resolution operators :: to define scope.
// method defined outside the class
void User::userMethod() 
{
    cout << "Hello! " << name << endl;
}

int main()
{
    User sam; // setting Object of User data type , named sam
    sam.name = "Sam";
    sam.classMessage();

    sam.setSecret(999); // setting new secret
    cout << sam.getSecret() << endl;

    sam.userMethod();

    User ruby;
    ruby.classMessage();

    return 0;
}