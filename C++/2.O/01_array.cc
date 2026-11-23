#include <iostream>
#include <array>

using namespace std;

int main()
{
  //** C Style array */

  int arr[4] = {1, 2, 3, 4};
  cout << arr[0] << endl;

  cout << arr << endl;     //  This prints the address of the first element of the array
  cout << &arr[0] << endl; //  same addresss
  cout << &arr[1] << endl;

  int newArr[4];
  newArr[0] = 11;
  newArr[1] = 22;

  cout << newArr[0] << endl; // 11

  // When we dereference the pointer *newArr, it refers to the first element of the array
  *newArr = 77;
  cout << newArr[0] << endl; // 77

  int *ptr = newArr;         // ptr points towards newArr[0]
  ptr++;                     // moves the ptr to next array element, newArr[1]
  cout << newArr[1] << endl; // 22

  cout << arr + 1 << endl;
  cout << *(arr + 1) << endl;

  cout << (arr[1] == *(arr + 1)) << endl; // true/1

  // <cstring> used to initialize arrays or buffers to zero or set them to a specific character efficiently.
  // (pointer, value, no of bytes to be filled)
  memset(arr, 0, sizeof(arr));

  //** STL: array */

  array<int, 4> arrPro = {1, 2, 3, 4};

  cout << arrPro[0] << endl;    // has no bounds check
  cout << arrPro.at(0) << endl; // throws error if out of range

  cout << arrPro.size() << endl; // C arrays don’t have this

  cout << arrPro.front() << endl; // 1
  cout << arrPro.back() << endl;  // 4

  cout << arrPro.empty() << endl; // check if empty

  // Pointer Access
  cout << arrPro.data() << endl;  // address of first element
  cout << *arrPro.data() << endl; // address of first element

  int *ptrPro = arrPro.data();
  ptrPro++;
  cout << *ptrPro; // next element

  arrPro.data() == &arrPro[0];

  arrPro.fill(0); // fill all elements with value

  // Loop
  for (int i = 0; i < arrPro.size(); i++)
  {
    cout << arrPro[i] << " ";
  }

  // or better
  for (int x : arrPro)
  {
    cout << x << " ";
  }
  cout << endl;

  // Assignment & copy allowed - not in C style arr
  array<int, 3> a = {1, 2, 3};
  array<int, 3> b;

  b = a;

  return 0;
}