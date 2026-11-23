#include <iostream>

using namespace std;

// Base and Derived for dynamic_cast
class Base
{
public:
  virtual void show() { cout << "Base class\n"; }
};

class Derived : public Base
{
public:
  void show() { cout << "Derived class\n"; }
};

int main()
{
  // Implicit cast
  int i = 42;
  double d = i; // int → double, no data lost
  float f = 3.14;
  double g = f;

  // C-style cast
  cout << "===== C-STYLE CAST =====\n";
  int a = 10;
  double b = (double)a; // C-style cast
  cout << "C-style: " << b << endl;

  // Static cast
  cout << "\n===== STATIC_CAST =====\n";
  double d2 = 9.8;
  int i2 = static_cast<int>(d2); // 9 — explicit truncation
  cout << i2 << endl;

  void *ptr = &i2;
  // cout << *ptr << endl; // ❌ ERROR — "invalid use of void expression"

  int *ip = static_cast<int *>(ptr); // void* back to typed ptr
  cout << *ip << endl;               // ✅ 42 — compiler knows: read 4 bytes, interpret as int

  // Dynamic Cast
  cout << "\n===== DYNAMIC_CAST =====\n";

  // Base -> Derived (Downcasting) ✅
  Base *basePtr = new Derived();
  Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);

  if (derivedPtr)
    derivedPtr->show();
  else
    cout << "dynamic_cast failed\n";

  /*
    What’s happening internally
    Pointer type → Base*
    Actual object → Derived

    So memory looks like:

    basePtr ──▶ [Derived object]
    Why it works
    dynamic_cast checks: “Is this object actually Derived?”
    ✔️ Yes → cast succeeds
    derivedPtr gets a valid address
  */

  // Failed Downcasting ❌
  Base *bptr = new Base();
  Derived *dptr = dynamic_cast<Derived *>(bptr); // null_ptr

  if (dptr)
    dptr->show();
  else
    cout << "dynamic_cast failed\n";

  /*
    What’s happening internally
    Pointer type → Base*
    Actual object → Base

    Memory:

    base ──▶ [Base object]
    Why it fails
    dynamic_cast checks: “Is this object actually Derived?”
    ❌ No → it's just Base
    So it returns:
  */

  /*
    🔹 Key Rule
    Downcasting → use dynamic_cast
    Upcasting → automatic, no cast needed
  */

  cout << "\n===== CONST_CAST =====\n";
  const int val = 100;
  int *modifiable = const_cast<int *>(&val);
  cout << "Before: " << val << endl;
  // *modifiable = 200; // Undefined behavior if val is truly const
  cout << "After (not modifying to stay safe): " << *modifiable << endl;

  cout << "\n===== REINTERPRET_CAST =====\n";
  int num = 65;
  char *charPtr = reinterpret_cast<char *>(&num);
  cout << "reinterpret_cast (first byte as char): " << *charPtr << endl;

  delete basePtr;
  return 0;
}