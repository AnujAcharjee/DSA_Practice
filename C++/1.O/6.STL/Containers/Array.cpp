#include <iostream>
using namespace std;

int main()
{
    int arr[4] = {1, 2, 3, 4};
    cout << arr[0] << endl; // 1 -> prints the first element of the array,
    cout << arr << endl;    // 0x61fefc -> This prints the address of the first element of the array

    int newArr[4];
    newArr[0] = 11;
    newArr[1] = 22;

    cout << newArr[0] << endl; // 11

    // When we dereference the pointer *newArr, it refers to the first element of the array
    *newArr = 77;
    cout << newArr[0] << endl; // 77

    int *arrPtr = newArr;      // arrPtr points towards newArr[0]
    arrPtr++;                  // moves the ptr to next array element, newArr[1]
    cout << newArr[1] << endl; // 22

    return 0;
}
