#include <iostream>
#include <utility>

#include <vector>
#include <list>
#include <deque>

#include <set>

using namespace std;

template <typename T>
void printContainer(const T &container, const string &event = "")
{
  if (!event.empty())
    cout << event << ": ";

  for (const auto &x : container)
  {
    cout << x << " ";
  }
  cout << endl;
}

void utilityExp()
{
  cout << "> UTILITY ....\n";

  // make_pair is a utility function used to create a pair object without explicitly specifying its types
  pair<int, string> p1 = make_pair(10, "Anuj");
  cout << p1.first << " " << p1.second << endl;

  // modern way
  p1 = {11, "Anup"};
  cout << p1.first << " " << p1.second << endl;

  // without main_pair -> with par better since C++ 17
  pair<int, string> p2 = {10, "Anuj"};

  pair<int, int> p3 = {2, 4};
  cout << p3.first << " " << p3.second << endl;

  pair<int, pair<int, char>> p4 = {1, {5, 'X'}};
  cout << p4.first << " " << p4.second.first << " " << p4.second.second << endl;

  pair<int, int> arr[] = {{1, 2}, {3, 4}, {4, 5}};
  for (pair<int, int> p : arr)
  {
    cout << p.first << "," << p.second << " | ";
  }
  cout << endl;
}

void vectorExp()
{
  cout << "> VECTORS ....\n";

  vector<int> v; // dynamic array (contiguous memory), grows automatically

  // insert elements
  v.push_back(1);
  v.push_back(2);
  v.emplace_back(3);

  printContainer(v, "v");

  // vector of pairs
  vector<pair<int, int>> vp;
  vp.push_back({4, 5});
  vp.emplace_back(6, 7);

  // allocating memory
  vector<int> v1(5, 200); // size 5, all elements = 200
  printContainer(v1, "v1");

  vector<int> v2(10); // size 10, all elements initialized to 0
  printContainer(v2, "v2");

  vector<int> v3(v1); // copy of v1
  printContainer(v3, "v1 in v3");

  // Iterators
  cout << "Iterating over V\n";

  auto it = v.begin();          // points to first element
  cout << "it: " << *it << " "; // 1

  it++;
  cout << "it: " << *it << " "; // 2

  // ❌ DO NOT dereference end()
  auto it2 = v.end();                    // points AFTER last element (garbage val)
  it2--;                                 // move to last element
  cout << "it2 (last): " << *it2 << " "; // 3

  // reverse iterators
  // ❌ DO NOT dereference rend()
  auto it3 = v.rbegin();                   // points to last element (garbage val)
  cout << "it3 (rbegin): " << *it3 << " "; // 3

  cout << "v back: " << v.back() << endl; // last element

  //* Loop
  for (auto it = v.begin(); it != v.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;

  //* Deletion
  // current v = {1, 2, 3}

  v.erase(v.begin() + 2); // removes 3 → {1, 2}

  // ⚠️ avoid invalid ranges (ensure size >= 3 before doing below)
  if (v.size() >= 3)
    v.erase(v.begin(), v.begin() + 3);

  //* Insert function (overloads)

  v.insert(v.begin(), 5); // insert single value at beginning
  printContainer(v, "Insert 5 at begin");

  v.insert(v.begin(), 6, 6000); // insert 6 copies of 6000 at beginning
  printContainer(v, "Insert 6 copies of 6000");

  vector<int> my(2, 88);                     // {88, 88}
  v.insert(v.begin(), my.begin(), my.end()); // insert range
  printContainer(v, "Insert my at begin");

  // Size
  cout << "size: " << v.size() << endl;

  v.pop_back(); // removes last element
  printContainer(v, "v pop back");

  v.swap(v2); // swaps contents of v and v2
  printContainer(v, "v after swap");
  printContainer(v2, "v2 after swap");

  v.clear(); // removes all elements
  printContainer(v, "v clear");

  cout << "is empty: " << v.empty() << endl; // returns 1 (true) or 0 (false)
}

void listExp()
{
  list<int> ls; // doubly linked list (non-contiguous)

  ls.push_back(2);    // {2}
  ls.emplace_back(4); // {2, 4}

  ls.push_front(5);    // {5, 2, 4}
  ls.emplace_front(1); // {1, 5, 2, 4}

  printContainer(ls, "List");

  // supports:
  // begin(), end(), rbegin(), rend()
  // size(), clear(), insert(), erase(), swap()

  // ⚠️ No random access:
  // no ls[i]
  // no iterator + index
  // ls.begin() + 2; // ❌ INVALID
}

void dequeExp()
{
  deque<int> dq; // double-ended queue (non-contiguous, supports fast insert at both ends)

  dq.push_back(1);    // {1}
  dq.emplace_back(2); // {1, 2}

  dq.push_front(11);    // {11, 1, 2}
  dq.emplace_front(22); // {22, 11, 1, 2}

  dq.pop_back();  // {22, 11, 1}
  dq.pop_front(); // {11, 1}

  printContainer(dq, "Deque");

  cout << dq.back() << endl;  // access last element
  cout << dq.front() << endl; // access first element

  // common functions:
  // begin(), end(), rbegin(), rend()
  // size(), clear(), insert(), erase(), swap()
}

void setExp()
{
  // SET: store unique values in sorted order
  // All operation takes O(log n) time
  cout << "> Set ... \n";

  set<int> st = {1, 2, 3};

  st.insert(4);
  printContainer(st, "Set st");

  st.insert(2); // will not be inserted (already present)

  // begin(), end(), rbegin(), rend(), size(), empty(), swap()

  auto it = st.find(3); // returns an iterator pointing towards 3
  cout << "it: " << *it << endl;

  it = st.find(55); // not present in set -> returns st.end
  if (it != st.end())
    st.erase(it);
  cout << "it: " << *it << endl;

  // remove value
  cout << st.erase(2); // can give the val
  // st.erase(it);        // give the address

  auto it1 = st.find(1);
  auto it2 = st.find(2);
  st.erase(it1, it2);

  int cnt = st.count(1); // arg: true or false

  it = st.lower_bound(2); // 3 -> returns an iterator to the first element in the set that is not less than (i.e., greater than or equal to) the specified value.
  it = st.upper_bound(2); // 3 -> returns an iterator to the first element in the set that is greater than the specified value.
  // If no elements in the set are greater than value, it returns an iterator to the end of the set.

  //* Multi set - stores duplicate elements also in sorted order

  multiset<int> ms = {1, 2, 2, 3, 4};

  ms.insert(5); // {1,2,2,3,4,5}

  ms.erase(2); // remove all 2s in set

  ms.erase(ms.find(2)); // only one 2 erased

  printContainer(ms, "ms after erase");

  // ms.erase(ms.find(2), ms.find(1) + 2); -> doesn't work here

  auto itStart = ms.find(2);
  if (itStart != ms.end())
  {
    auto itEnd = itStart;
    advance(itEnd, 2); // Move `it` forward by 2 positions
    printContainer(ms, "after advance");
    ms.erase(itStart, itEnd);
    printContainer(ms, "after erase");
  }
}

int main()
{
  utilityExp();
  vectorExp();
  listExp();
  dequeExp();
  setExp();

  return 0;
}