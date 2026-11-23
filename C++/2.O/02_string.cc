#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  char c = 'a'; // use single quart
  cout << c << endl;

  const char *cStr = "anuj"; // string literal
  cout << cStr << endl;
  // const -> string literals are read only
  // Modifying them -> undefined behaviour
  // char* cStr - allowed in old C, unsafe in C++

  //** Array of chars */

  char arr[] = "anuj"; // mutable
  arr[0] = 'A';
  cout << arr << endl;

  //** String */

  string s = "Anuj";

  size_t len = s.size(); // 4

  // Capacity ≥ size
  cout << "length: " << s.length() << endl; // 4
  cout << "size: " << s.size() << endl; // 4
  cout << "capacity: " << s.capacity() << endl; // 15

  // accessing chars in string
  s[len - 1] = 'z'; // "Anuz"
  cout << s[len - 1] << endl;

  s.push_back('x'); // "Anuzx"
  s.pop_back();     // "Anuz"

  cout << s.find("nu") << endl; // returns starting index -> 1
  // if not found -> string::npos
  if (s.find("asd") == string::npos)
  {
    cout << "NA" << endl;
  }

  string sTest = "hello";

  // Getting Sub String of a string 
  cout << sTest.substr(1, 3) << endl; // "ell" (start, length-upto)
  cout << sTest.substr(0, 1) << endl; // "h" 

  sTest += " knox";                      // concat -> "hello knox"
  cout << sTest.append(" boss") << endl; // "hello knox boss"

  cout << sTest.erase(1, 3) << endl;    // "ho knox boss"
  cout << sTest.insert(2, "Z") << endl; // hoZ knox boss

  cout << sTest.empty() << endl; // 0

  // comparison
  string a = "abc";
  string b = "abc";
  cout << (a == b) << endl; // 1; works

  cout << s[0] << endl;    // A
  cout << s.at(0) << endl; // A

  // ASCII
  printf("ASCII value: %d \n", 'A'); // 65  (A-Z = 65-90)
  printf("ASCII value: %d \n", 'a'); // 97  (a-z = 97-122)
  cout << (1 + 'a') << endl;         // 98

  // to convert a character in to number
  char n = '3'; // ascii = 51
  cout << (n - '0') << endl; // 51 - 48 = 3

  // useful while taking line(multiple strings as input)
  string line;

  getline(cin, line);
  cout << line << endl;

  // Looping
  for (const char c : line)
  {
    cout << c;
  }
  cout << endl;

  for (auto it = s.begin(); it != s.end(); it++)
  {
    cout << *it;
  }

  // Algorithms

  reverse(line.begin(), line.end());
  cout << line << endl;

  sort(line.begin(), line.end());
  cout << line << endl;

  return 0;
}