#include <iostream>
#include<list>

using namespace std;

int main() {
    list<int> ls; // doubly linked list

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5); // {5, 2, 4}

    ls.emplace_front(); 

    // rest func same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap



}