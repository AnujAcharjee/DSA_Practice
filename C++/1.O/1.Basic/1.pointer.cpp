#include <iostream>
using namespace std;

int main()
{
    int score = 500;

    // *ptr points towards the memory address of score.
    int *ptr = &score;
    cout << "ptr: " << *ptr << endl; // 500

    // modifying *ptr will directly change score.
    // This is because both *ptr and score refer to the same memory location.
    *ptr = 800;
    cout << "ptr: " << *ptr << endl;   // 800
    cout << "score:" << score << endl; // 800

    // newScore is just a variable which stores the value in the memory address of *ptr.
    int newScore = *ptr;
    cout << "newScore: " << newScore << endl; // 800

    // so making changes to newScore will not affect *ptr and score.
    newScore = 600;
    cout << "newScore: " << newScore << endl; // 600
    cout << "ptr: " << *ptr << endl;          // 800
    cout << "score:" << score << endl;        // 800

    // This creates a reference anotherScore that refers to the same memory location as score.
    int &anotherScore = score;
    cout << "anotherScore:" << anotherScore << endl; // 800

    // Any modifications to anotherScore will also affect score, and vice versa.
    anotherScore = 700;
    cout << "anotherScore:" << anotherScore << endl; // 700
    cout << "ptr: " << *ptr << endl;                 // 700
    cout << "score:" << score << endl;               // 700

    return 0;
}
