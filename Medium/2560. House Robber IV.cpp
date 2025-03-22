/*
    LeetCode Medium             : 2560. House Robber IV
    LeetCode Link               : https://leetcode.com/problems/house-robber-iv/description/
*/

/*********************************************************** C++ **************************************************/



// Using Brute Force
// Disclaimer:(Gives TLE)
// Time Complexity :O(exp)
// Space Complexity:O(N)
class Solution {
public:
    int n;
    int solve(vector<int>& nums,int i, int k,vector<vector<int>>& t){
        if(k == 0){
            return 0;
        }

        if(i >= n){
            return INT_MAX;
        }

        if(t[i][k] != -1){
            return t[i][k];
        }
        int take = max(nums[i],solve(nums,i + 2, k - 1,t));
        int skip = solve(nums,i + 1, k,t);

        return t[i][k] = min(take,skip);
    }
    int minCapability(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<int>> t(n + 1,vector<int>(k + 1, -1));
        return solve(nums,0,k,t);
    }
};


