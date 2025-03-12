/*
    LeetCode Easy               : 2529. Maximum Count of Positive Integer and Negative Integer
    Leetcode Link               : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer
*/

/*********************************************************** C++ **************************************************/

// Using Naive Approach
// Time Complexity : O(n)
// Space Complexity: O(1)

class Solution
{
public:
  int maximumCount(vector<int> &nums)
  {
    int n = nums.size();
    int u = 0;
    int d = 0;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] < 0)
      {
        d++;
      }
      if (nums[i] > 0)
      {
        u++;
      }
    }

    return max(u, d);
  }
};
