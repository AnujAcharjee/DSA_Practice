#include <iostream>
#include <string>
#include <utility>

using namespace std;

// O(n^3)
class BruteForce
{
private:
  bool isPalindrome(string &subStr)
  {
    if (subStr.empty())
      return false;

    int left = 0, right = subStr.size() - 1;

    while (left < right)
    {
      if (subStr.at(left) != subStr.at(right))
        return false;

      left++;
      right--;
    }

    return true;
  }

public:
  string longestPalindrome(string s)
  {
    if (s.length() <= 1)
      return s;

    string max_str = s.substr(0, 1);
    int max_len = 1;

    // getting all Sub Strings of thr given string O(n^2)
    for (int i = 0; i < s.size(); i++)
    {
      for (int j = i + max_len; j < s.size(); j++)
      {
        // Palindrome check
        int curLen = j - i + 1;
        string subStr = s.substr(i, curLen);
        
        if (curLen > max_len && isPalindrome(subStr))
        {
          max_len = curLen;
          max_str = subStr;
        }
      }
    }

    return max_str;
  }
};

// O(n^2)
class ExpandAroundCenter
{
private:
  pair<int, int> getPalindrome(string &s, int left, int right)
  {
    while (left >= 0 && right < s.size() && s.at(left) == s.at(right))
    {
      left--;
      right++;
    }

    // +1 & -1 to remove the last loop change
    return {left + 1, right - 1};
  }

public:
  string longestPalindrome(string s)
  {
    if (s.size() <= 1)
      return s;

    string max_str = s.substr(0, 1);

    for (int i = 0; i < s.size() - 1; i++)
    {
      // for odd palindrome - {abcba} - c center
      pair<int, int> odd = getPalindrome(s, i, i);
      // for even palindrome - {abba} - no center
      pair<int, int> even = getPalindrome(s, i, i + 1);

      const int oddLength = odd.second - odd.first + 1; // +1 -> length +1 of last index
      const int evenLength = even.second - even.first + 1;

      if (oddLength > max_str.size())
        max_str = s.substr(odd.first, oddLength);
      if (evenLength > max_str.size())
        max_str = s.substr(even.first, evenLength);
    }

    return max_str;
  }
};

class DP
{
};

class ManachersAlgorithm
{
};

int main()
{
  string s;

  getline(cin, s);

  BruteForce bf;
  cout << "brute force: " << bf.longestPalindrome(s) << endl;

  ExpandAroundCenter eac;
  cout << "ExpandAroundCenter: " << eac.longestPalindrome(s) << endl;

  return 0;
}