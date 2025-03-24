/*
    LeetCode Easy               : 26. Remove Duplicates from Sorted Array
    Leetcode Link               : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

/*********************************************************** C++ **************************************************/



// Using Two Pointer Approach
// Time Complexity: O(N);
// Space Complexity:O(1); // without any extra space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;

        while(j < nums.size()){
            if(nums[i] != nums[j]){
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        return i + 1;
    }
};
