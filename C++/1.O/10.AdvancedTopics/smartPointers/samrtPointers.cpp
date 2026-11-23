#include <iostream>
#include <string>
#include <memory> // Include memory for smart pointers

using namespace std;

class User
{
public:
    // Constructor
    User() { cout << "User create \n"; }

    // Destructor
    ~User() { cout << "User destroyed \n"; }

    void testFunc() { cout << "I am a test function\n"; }
};

int main()
{
    {
        unique_ptr<User> sam = make_unique<User>();
        sam->testFunc();

        // unique_ptr<User> samm = sam; // NOT ALLOWWED
    }
    // After going out of this scope, memory allocated for pointer get destroyed.

    cout << "Outside code\n";

    {
        shared_ptr<User> tim = make_shared<User>();
        shared_ptr<User> timm = tim;  // ALLOWED

        weak_ptr<User> wtim = tim;
    }

    return 0;
}