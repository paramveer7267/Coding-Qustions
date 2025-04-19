/*
    LeetCode Easy               : 2176. Count Equal and Divisible Pairs in an Array
    LeetCode Link               : https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/
*/

/*********************************************************** C++ **************************************************/


// Using recursion
// Time Complexity: O(n²)
// Space Complexity: O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1 ;j<nums.size();j++){
                if(nums[i] == nums[j] && (i * j) % k == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
