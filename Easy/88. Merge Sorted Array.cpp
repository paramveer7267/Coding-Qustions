/*
    LeetCode Easy               : 88. Merge Sorted Array
    Leetcode Link               : https://leetcode.com/problems/merge-sorted-array/description/
*/

/*********************************************************** C++ **************************************************/


// Using Two Pointers
// Time Complexity:O(n + m)
// Space Complexity:O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = n+m-1;
        for(int p =0;p<m+n;p++){
            if(i<0 or j<0) break;
            if(nums1[i]>=nums2[j]){
                nums1[k--] = nums1[i--];

            }
            else{
                nums1[k--] = nums2[j--];

            }
        
       
        }
        while(j>=0) {
            nums1[k--] = nums2[j--];
        }
    }
};



// Using Sorting
// Time Complexity:O((m + n)logn)
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
