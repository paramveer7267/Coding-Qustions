/*
    LeetCode Easy               : 2529. Maximum Count of Positive Integer and Negative Integer
    Leetcode Link               : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer
*/

/*********************************************************** C++ **************************************************/



// Using Constraint Observation Approach
// Time Complexity :O(N)
// Space Complexity:O(1) or O(501)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> arr(501,0);

        for(int i = 0;i<nums.size();i++){
            arr[nums[i]]++;
        }

        for(int i =1;i<arr.size();i++){
            if(arr[i] == 1 || arr[i]%2 != 0){
                return false;
            }
        }
        return true;
    }
};
