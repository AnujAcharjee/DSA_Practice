#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <future> // std::promise  std::future
#include <stdexcept>

using namespace std;

void square(promise<int> &&SquarePromise, int num)
{
    try
    {
        if (num < 0) {
            throw runtime_error("Cannot calculate square of negative number");
        }
        int squareVal = num * num;
        SquarePromise.set_value(squareVal);
    }
    catch (const exception& e)
    {
        SquarePromise.set_exception(make_exception_ptr(e));
    }
    catch (...)
    {
        SquarePromise.set_exception(current_exception());
    }
}

int main()
{
    try {
        // Create separate promises for each thread
        promise<int> SquarePromise1;
        promise<int> SquarePromise2;
        future<int> SquareFuture1 = SquarePromise1.get_future();
        future<int> SquareFuture2 = SquarePromise2.get_future();
 
        thread t1(square, move(SquarePromise1), 5);
        thread t2(square, move(SquarePromise2), -5); 
        
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
        
        t1.join();
        t2.join();
    } catch (const exception& e) {
        cerr << "Thread error: " << e.what() << endl;
        return 1;
    }

    return 0;
}