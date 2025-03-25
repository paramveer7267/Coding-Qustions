/*
    LeetCode Easy               : 283. Move Zeroes
    Leetcode Link               : https://leetcode.com/problems/move-zeroes/description/
*/

/*********************************************************** C++ **************************************************/



// Using Sorting
// Time Complexity: O(n*Logn)
// Space Complexity:O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    
    }
};
