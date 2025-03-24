/*
    LeetCode Medium             : 2401. Longest Nice Subarray
    LeetCode Link               : https://leetcode.com/problems/longest-nice-subarray/description/
*/

/*********************************************************** C++ **************************************************/


// Using n² Approach
// Time Complexity : O(n²);
// Space Complexity : O(1);
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int res = 0;

        for (int i = 0; i < n; i++) {
            int mask = 0;

            for (int j = i; j < n; j++) {
                if ((mask & nums[j]) != 0) {
                    break;
                }

                res = max(res, j - i + 1);
                mask = (mask | nums[j]);
            }
        }
        return res;
    }
};



// Using Sliding Approach
// Time Complexity : O(n);
// Space Complexity : O(1);
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int res = 1;

        int i = 0;
        int j = 0;

        int mask = 0;

        while (j < n) {

            while ((mask & nums[j]) != 0) {
                mask = (mask ^ nums[i]);
                i++;
            }

            res = max(res, j - i + 1);
            mask = (mask | nums[j]);
            j++;
        }
        return res;
    }
};
