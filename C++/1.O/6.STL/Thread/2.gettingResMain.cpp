// To get the result back from  the executed task in main thread
// with plain task, there is no notion of getting return values - use std::future
// Alternatively - we can pass an Argument in the task telling where to put the result  (*res)

#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <future> // std::promise  std::future
#include <stdexcept>

using namespace std;

// function obj - can also se a normal func
struct Sum
{
    const vector<int> &v; // Store reference instead of copy
    int *res;             // stores the ref where response has to be put

    Sum(const vector<int> &vv, int *r) : v(vv), res(r) {};

    void operator()()
    {
        if (!res)
        {
            throw runtime_error("Invalid result pointer");
        }
        *res = 0;
        for (auto x : v)
        {
            *res += x; // result modified at that location
        }
    }
};

int main()
{
    vector vtr{2, 3, 5, 10};
    int res1; // address initialised for storing the result
    thread t1{Sum(vtr, &res1)};
    t1.join();
    cout << "Sum: " << res1 << endl;

    return 0;
}