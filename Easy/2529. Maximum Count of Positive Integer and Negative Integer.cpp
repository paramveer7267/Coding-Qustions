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
  int maximumCount(vector<int> &nums){
    int n = nums.size();
    int u = 0;
    int d = 0;

    for (int i = 0; i < n; i++){
      if (nums[i] < 0){
        d++;
      }
      if (nums[i] > 0){
        u++;
      }
    }
      
    return max(u, d);
  }
};


// Using STL/count_if Approach
// Time Complexity : O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        auto lambdaP = [](int num){
            return num > 0;
        };
        auto lambdaN = [](int num){
            return num < 0;
        };

        int pos = count_if(begin(nums),end(nums),lambdaP);
        int neg = count_if(begin(nums),end(nums),lambdaN);

        return max(pos,neg);
    }
};


// Using lower_bound Approach
// Time Complexity : O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int firstP = lower_bound(begin(nums), end(nums), 1) - begin(nums);
        int firstN = lower_bound(begin(nums), end(nums), 0) - begin(nums);

        return max(n - firstP, firstN);
    }
};
