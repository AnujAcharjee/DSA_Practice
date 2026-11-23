#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <future> // std::promise  std::future
#include <stdexcept>

using namespace std;

future<int> square(int num)
{
    return async(launch::async, [](int n) {
        if (n < 0) {
            throw runtime_error("Cannot calculate square of negative number");
        }
        return n * n;
    }, num);
}

int main()
{
    try {
        future<int> SquareFuture1 = square(5);
        future<int> SquareFuture2 = square(-5);

        // Wait for the results and handle any exceptions
        try {
            cout << "Square: " << SquareFuture1.get() << endl;
        } catch (const exception& e) {
            cerr << "Error calculating square: " << e.what() << endl;
        }
        
        try {
            cout << "Square: " << SquareFuture2.get() << endl;
        } catch (const exception& e) {
            cerr << "Error calculating square: " << e.what() << endl;
        }
    } catch (const exception& e) {
        cerr << "Async task error: " << e.what() << endl;
        return 1;
    }

    return 0;
}