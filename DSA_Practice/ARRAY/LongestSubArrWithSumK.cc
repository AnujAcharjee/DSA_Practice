#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// optimal if arr contain -ve
int longestSubArr(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> map; // prefixSum -> index
    int prefixSum = 0, maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        // Case 1: subarray from start to i
        if (prefixSum == k)
            maxLength = max(maxLength, i + 1);

        // Case 2: subarray from some j+1 to i
        int complement = prefixSum - k;
        if (map.find(complement) != map.end())
            maxLength = max(maxLength, i - map[complement]);

        // Store prefix sum only if it hasn't been stored before
        if (map.find(prefixSum) == map.end())
            map[prefixSum] = i;
    }

    return maxLength;
}

// optimal for +ve & 0 only
int longestSubArr2(vector<int> &arr, int k)
{
    int left = 0, right = 0;
    int sum = 0, maxLen = 0;
    int n = arr.size();

    while (right < n)
    {
        sum += arr[right];

        // Shrink window until sum <= k
        while (sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // Check if valid subarray
        if (sum == k)
            maxLen = max(maxLen, right - left + 1);

        right++;
    }

    return maxLen;
}

int main()
{
    vector<int> arr{1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k = 3;

    cout << longestSubArr(arr, k) << endl;

    return 0;
}
