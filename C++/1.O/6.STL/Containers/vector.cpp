#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v; // dynamic arr (singly linked list), whose size increases as we insert elements

    v.push_back(1); // pushes val in vector
    v.push_back(2);
    v.emplace_back(3);

    vector<pair<int, int>> vp;

    vp.push_back({4, 5});
    vp.emplace_back(4, 5); // need of parenthesis

    vector<int> v1(5, 200); // size 5 - can be increased , all elements 200

    vector<int> v2(10); // size 10 , all elements empty or garbage val

    vector<int> v3(v1); // creates a copy of v1 in v3

    //* Iterators
    vector<int>::iterator it = v.begin(); // refers to the memory address of first element
    cout << *(it) << " ";                 // 1

    it++;
    cout << *(it) << " "; // 2
    // when we add a pointer to a memory address we can access the memory.

    vector<int>::iterator it2 = v.end(); // start form 1 element after last element
    cout << *(it2) << " ";               // 0

    it2--;
    cout << *(it2) << " "; // 3

    vector<int>::reverse_iterator it3 = v.rend();
    cout << *(it3) << " "; // garbage

    vector<int>::reverse_iterator it4 = v.rbegin();
    cout << *(it4) << " "; // garbage

    cout << v.back() << endl; // returns the last element

    //* Loop
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    //* Deletion
    // { 1, 2, 3, 4, 5}
    v.erase(v.begin() + 2); // {1, 2, 4, 5} (location)

    v.erase(v.begin(), v.begin() + 3); // {4, 5} (start, end+1)

    //* Insert function

    v.insert(v.begin(), 300);       // (position, val)
    v.insert(v.begin(), 500, 6000); // (position, val, val)

    vector<int> my(2, 88); // {88 , 88}

    v.insert(v.begin(), my.begin(), my.end());

    v.size(); // return size

    v.pop_back(); // pop the last element

    v.swap(v2); // swap v and v2 elements 

    v.clear(); // erases entire vector

    v.empty(); // return bool value
}