// Use - try, catch, throw

// std::exception	Base class for all standard exceptions.
// std::runtime_error	Errors that occur during program execution.
// std::logic_error	Errors due to flawed program logic.
// std::bad_alloc	Thrown when new fails due to memory shortage.
// std::out_of_range	Accessing elements beyond the valid range (e.g., vector index).
// std::invalid_argument	Invalid arguments passed to functions.

// noexcept -- mark a func if its expected to throw no exceptions (improves performance) 

// When an exception is thrown, C++ automatically destroys all local objects in reverse order before propagating the exception.
// This process is called Stack Unwinding.

#include <iostream>
#include <exception>

using namespace std;

void testException(int x)
{
    try
    {
        if (x == 0)
            throw "Zero is not allowed!";
        if (x < 0)
            throw runtime_error("Negative value error!");
        if (x > 100)  // random case
            throw 43; // throwing int as error - not handled, go under all error
        cout << "Value is: " << x << endl;
    }
    catch (const char *msg)
    { // Catch string exceptions
        cout << "Caught exception: " << msg << endl;
    }
    catch (const runtime_error &e)
    { // Catch runtime errors
        cout << "Caught runtime error: " << e.what() << endl;
    }
    catch (...)
    { // Catch all exceptions
        cout << "Caught an unknown exception!" << endl;
    }
}

// Define own custom exception class inherited from std::exception
class CustomException : public exception
{
public:
    const char *what() const noexcept override
    { // Override what()
        return "Custom Exception: Something went wrong!";
    }
};

int main()
{
    testException(5);
    testException(0);
    testException(-3);
    testException(101);

    try
    {
        throw CustomException(); // Throw custom exception
    }
    catch (const CustomException &e)
    {
        cout << e.what() << endl;
    }


    return 0;
}
