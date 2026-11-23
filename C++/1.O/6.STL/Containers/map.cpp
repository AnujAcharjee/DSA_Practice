#include <iostream>
#include <map>

using namespace std;

int main()
{
    // store key: value pair - can be of any dta type.
    // unique keys - in sorted order.
    // TC: O(log n)

    map<int, int> mpp1;
    mpp1[1] = 2;
    mpp1.emplace(2, 4);
    mpp1.insert({2, 3});

    map<int, pair<int, int>> mpp2;
    mpp2[1] = {10, 20};
    mpp2.emplace(2, make_pair(30, 40));

    map<pair<int, int>, int> mpp3;
    mpp3[{1, 2}] = 100;
    mpp3.emplace(make_pair(3, 4), 400);

    for(auto it: mpp1) {
        cout << it.first << " " << it.second << endl;
    }

    auto it = mpp1.find(1);
    cout << it->first << endl;

    auto it = mpp1.lower_bound(2);

    auto it = mpp1.upper_bound(3);

    // erase, swap, size, empty


 //* multimap -> can store duplicate keys , sorted

 //* unordered_map -> unique keys, not sorted
 //Tc: O(1) , worst: O(log n)


}
