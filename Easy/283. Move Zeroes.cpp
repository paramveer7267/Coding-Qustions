/*
    LeetCode Easy               : 283. Move Zeroes
    Leetcode Link               : https://leetcode.com/problems/move-zeroes/description/
*/

/*********************************************************** C++ **************************************************/



// Using Two Pointer
// Time Complexity : O(n)
// Space Complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int z = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] != 0)
            {
                swap(nums[z++],nums[i]);
            }
        }
    }
};
