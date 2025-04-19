/*
    LeetCode Easy               : 1863. Sum of All Subset XOR Totals
    Leetcode Link               : https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
*/

/*********************************************************** C++ **************************************************/


// Using Brute Force
// Time Complexity: O(2^n * len(num))
// Space Complexity:O(2^n * len(num)) 
class Solution {
public:
    void solve(vector<int>& nums,int i, vector<int>& curr, vector<vector<int>>& subsets){
        if(i >= nums.size()){
            subsets.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums,i+1,curr,subsets);

        curr.pop_back();
        solve(nums,i+1,curr,subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curr;

        solve(nums,0,curr,subsets);

        int res = 0;
        for(vector<int>& subset : subsets){
            int Xor = 0;
            for(int &num : subset){
                Xor ^= num;
            }

            res += Xor;
        }
        return res;
    }
};


// Using Optimal Approach
// Time Complexity: O(2^n)
// Space Complexity:O(n) 
class Solution {
public:
    int solve(vector<int>& nums,int i,int Xor){
        if(i >= nums.size()){
            return Xor;
        }

        int include = solve(nums,i+1,Xor ^ nums[i]);
        int exclude = solve(nums,i+1, Xor);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {

        return solve(nums,0,0);
    }
};


// Using Observation
// Time Complexity: O(n)
// Space Complexity:O(1)
// 1. Find OR of all the elements.
// 2. Append n - 1 zeros in right side the ans of OR.
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int &num :nums){
            res |= num;
        }

        return res << (n - 1);
    }
};
