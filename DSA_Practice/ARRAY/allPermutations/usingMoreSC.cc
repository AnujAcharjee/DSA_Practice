#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find all possible permutations in lexigraphically increasing order

void recPermutation(vector<int> &nums, vector<int> &temp, vector<bool> &elementTaken, vector<vector<int>> &ans)
{
    int numsLength = nums.size();

    if ((int)temp.size() == numsLength)
    {
        ans.emplace_back(temp);
        return;
    }

    for (int i = 0; i < numsLength; i++)
    {
        if (!elementTaken[i])
        {
            temp.emplace_back(nums[i]);
            elementTaken[i] = true;

            recPermutation(nums, temp, elementTaken, ans);

            temp.pop_back();
            elementTaken[i] = false;
        }
    }
}

void print(vector<vector<int>> &v)
{
    for (auto &perm : v)
    {
        for (int x : perm)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    vector<int> nums{1, 6, 3}, temp;
    vector<bool> elementTaken(nums.size(), false);
    vector<vector<int>> ans;

    recPermutation(nums, temp, elementTaken, ans);
    print(ans);

    cout << '\n';

    // sort the ans vector lexicographically
    sort(ans.begin(), ans.end());
    print(ans);

    return 0;
}
