#include <iostream>
#include <vector>
using namespace std;

// Problem Statement: Given an array, print all the elements which are leaders.
// A Leader is an element that is greater than all of the elements on its right side in the array.

// Input:
// arr = [10, 22, 12, 3, 0, 6]
// Output:
// 22 12 6

// Brute force: O(n^2) - 1st loop iterate over arr & 2nd check for any elemnet greater than a[i] on right

vector<int> optimalSol(vector<int> &v)
{
    int l = v.size();
    int greatest = v[l - 1];
    vector<int> res;
    res.emplace_back(v[l - 1]);

    for (int i = l - 2; i > 0; i--)
    {
        if (greatest < v[i])
        {
            greatest = v[i];
            res.emplace_back(v[i]);
        }
    }

    return res;
}

void print(vector<int> &v)
{
    for (int e : v)
    {
        cout << e << ' ';
    }
}

int main()
{
    vector<int> v{10, 22, 12, 3, 0, 6}, result((int)v.size());

    vector<int> optimalRes = optimalSol(v);
    print(optimalRes);

    return 0;
}