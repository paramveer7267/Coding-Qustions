/*
    LeetCode Medium             : 152. Maximum Product Subarray
    LeetCode Link               : https://leetcode.com/problems/maximum-product-subarray/description/
*/

/*********************************************************** C++ **************************************************/

// Using Kadane's Approach
// Time Complexity : O(n);
// Space Complexity: O(1);

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int res = nums[0];
    int prod1 = nums[0];
    int prod2 = nums[0];
    int n = nums.size();
    int i = 1;
    while (i < n)
    {
      int temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]});
      prod2 = min({nums[i], prod1 * nums[i], prod2 * nums[i]});
      prod1 = temp;

      res = max(res, prod1);
      i++;
    }
    return res;
  }
};


// Using Suffix & Prefix Approach
// Time Complexity : O(n);
// Space Complexity: O(1);

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int res = nums[0];
    int pre = 1;
    int suf = 1;
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
      if (pre == 0)
        pre = 1;
      if (suf == 0)
        suf = 1;

      pre *= nums[i];
      suf *= nums[n - i - 1];

      res = max(res, max(pre, suf));
      i++;
    }
    return res;
  }
};