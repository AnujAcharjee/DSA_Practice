#include <iostream>

// Function Object (Functor)
struct Multiply {
    int factor;  // Member variable

    Multiply(int f) : factor(f) {} // Constructor initializes factor

    int operator()(int x) const {  // Overload () to make the object callable
        return x * factor;
    }
};

// General Functor: Performs any arithmetic operation
struct Operation {
    char op; // Stores operation type ('+', '-', '*', '/')

    Operation(char operation) : op(operation) {}

    int operator()(int a, int b) const {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return (b != 0) ? a / b : 0; // Avoid division by zero
            default: return 0;
        }
    }
};

int main() {
    Multiply multiplyBy3(3); // Create functor instance with factor 3 (ie. factor = 3)

    std::cout << "3 * 5 = " << multiplyBy3(5) << std::endl; // Calls operator()
    std::cout << "3 * 10 = " << multiplyBy3(10) << std::endl; // Calls operator()

    Operation add('+');   // Functor for addition
    Operation multiply('*'); // Functor for multiplication

    std::cout << "5 + 3 = " << add(5, 3) << std::endl;
    std::cout << "5 * 3 = " << multiply(5, 3) << std::endl;

    return 0;
}
