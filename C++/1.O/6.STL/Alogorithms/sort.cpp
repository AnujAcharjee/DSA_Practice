#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[6] = {3, 4, 52, 2, 6, 3};
    sort(arr, arr + 6); //(start, end) -> default: ascending order

    vector<int> v = {3, 5, 67, 56, 44};
    sort(v.begin(), v.end());

    sort(arr + 2, arr + 6); // sort from indx 2 to 5

    sort(arr, arr + 4, greater<int>()); // sort in descending order

    int num = 7;
    int cnt = __builtin_popcount(num); // returns the number of set bits

    long long num = 121342453645;
    int cnt = __builtin_popcountll(num);

    string s = "123";
    sort(s.begin(), s.end()); // should be sorted to get all

    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));  // returns all permutations

    int maxi = *max_element(arr, arr + 5); // returns max element 
}
