/*
    LeetCode Medium             : 2874. Maximum Value of an Ordered Triplet II
    LeetCode Link               : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/
*/

/*********************************************************** C++ **************************************************/


// Using Optimal Approach
// Time Complexity : O(n)
// Space Complexity: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = size(nums);
        long long ans = INT_MIN;
        long long maxDiff = 0;
        long long maxi = 0;

        for(int  k = 0;k<n;k++){
            ans = max(ans , maxDiff * nums[k]);
            maxDiff = max(maxDiff , maxi - nums[k]);
            maxi = max(maxi,(long long)nums[k]);
        }
        return ans;
    }
};
