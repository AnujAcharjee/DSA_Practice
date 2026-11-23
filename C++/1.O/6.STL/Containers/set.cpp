#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    set<int> st; // store unique val in sorted order
    // TimeC every - O(log n)

    st.insert(1);
    st.insert(2);
    st.insert(2); // will not be inserted
    st.insert(3); // { 1,2,3}

    // begin(), end(), rbegin(), rend(), size(), empty(), swap()

    auto it = st.find(3); // returns an iterator pointing towards 3

    auto it = st.find(55); // not present in set
    // return st.end

    st.erase(2);  // can give the val
    st.erase(it); // give the address

    auto it1 = st.find(1);
    auto it2 = st.find(2);
    st.erase(it1, it2);

    int cnt = st.count(1); // arg: true or false

    auto it = st.lower_bound(2); // 3
    auto it = st.lower_bound(3); // 3
    // returns an iterator to the first element in the set that is not less than (i.e., greater than or equal to) the specified value.
    // If all elements in the set are less than value, it returns an iterator to the end of the set.

    auto it = st.upper_bound(2); // 3
    // set.upper_bound(value) returns an iterator to the first element in the set that is greater than the specified value.
    // If no elements in the set are greater than value, it returns an iterator to the end of the set.

    //* Multi set - stores duplicate elements also in sorted order
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4); // {1,2,2,3,4}

    ms.erase(2);          // all 2s erased
    ms.erase(ms.find(2)); // only one 2 erased

    // ms.erase(ms.find(2), ms.find(1) + 2); -> doesn't work here

    auto itStart = ms.find(2);
    auto itEnd = itStart;
    advance(itEnd, 2); // Move `it` forward by 2 positions
    ms.erase(itStart, itEnd);

    //* Unordered set - stores unique elements in unsorted order
    unordered_set<int> ust;
    // TimeC every - O(n) , worst case- O(log n)
    // lower_bound and upper_bound fun. doesn't work
    // rest all are same
}