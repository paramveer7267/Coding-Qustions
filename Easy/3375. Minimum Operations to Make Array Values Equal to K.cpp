/*
    LeetCode Easy               : 3375. Minimum Operations to Make Array Values Equal to K
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/
*/

/*********************************************************** C++ **************************************************/


// Usinig Optimal Approach
// Time Complexity:O(n)
// Space Complexity:O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int &x : nums) {
            if(x < k) {
                return -1;
            } else if(x > k) {
                st.insert(x);  
            }
        }
        return st.size();
    }
};
