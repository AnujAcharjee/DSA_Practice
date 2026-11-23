#include <iostream>
using namespace std;

// Function Templates

template <typename T>
T add(T a, T b)
{
  return a + b;
}

// Multiple Template Parameters
template <typename T, typename U>
void print(T a, U b)
{
  cout << a << " " << b << endl;
}

// Class template

template <typename T>
class Box
{
public:
  T value;

  void set(T v) { value = v; }
  T get() { return value; }
};

int main()
{
  cout << add(2, 3) << endl;     // int
  cout << add(2.5, 3.5) << endl; // double

  Box<int> b1;
  b1.set(33);
  cout << b1.get() << endl;

  Box<string> b2;
  b2.set("hello");
  cout << b2.get() << endl;

  return 0;
}