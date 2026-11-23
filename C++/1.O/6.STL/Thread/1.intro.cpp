// Introduced in STL in C++11
// A thread usually shares a address space with other threads
// can be launched as std::thread with a function / func object / ladda

// A thread is not CopyConstructable and CopyAssignable
// It is  MoveConstructable and MoveAssignable - std::move()

#include <iostream>
#include <thread>
#include <vector>
#include <functional> // bind() , ref() -> binds a func and it params into a func object | ref pass the val as reference

void f(std::vector<int> &v)
{
    std::cout << "In f()" << ":";
    for (auto x : v)
    {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;
}

 // func Object
struct F  
{
    std::vector<int> &v;

    F(std::vector<int> &vv) : v{vv} {} // Constructor initializes the reference

    void operator()()   // Overloaded () for thread execution
    { 
        std::cout << "In F() :";
        for (auto x : v)
        {
            std::cout << ' ' << x;
        }
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<int> my_vtr{2, 3, 5, 7, 11};

    std::thread t1{std::bind(f, std::ref(my_vtr))}; // std::bind ensures reference passing
    std::thread t2{F(my_vtr)};

    // If you pass a copy of the vector instead of a reference, then:
    // Each thread gets its own separate copy of my_vtr.
    // Modifications inside the thread will not reflect in the original vector in main().
    // There is no risk of data races since each thread operates on its own copy.

    t1.join(); // main thread have to wait for bot threads to execute first
    t2.join();

    return 0;
}