/*
    LeetCode Medium             : 2563. Count the Number of Fair Pairs
    LeetCode Link               : https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
*/

/*********************************************************** C++ **************************************************/


// Using Upper & Lower Bound
// Time Comp : O(nlogn);
// Space Comp: O(1);
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums),end(nums));

        long long res = 0;

        for(int i  =0;i<n;i++){ //O(n + logn)
            int idx = lower_bound(begin(nums) + i + 1,end(nums),lower - nums[i]) - begin(nums);
            int x = idx - 1 - i;

            idx = upper_bound(begin(nums) + i + 1,end(nums), upper - nums[i]) - begin(nums);
            int y = idx - i - 1;
            res += (y - x);
        }
        return res;
    }
};
