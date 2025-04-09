/*
    LeetCode Easy               : 3396. Minimum Number of Operations to Make Elements in Array Distinct
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/
*/

/*********************************************************** C++ **************************************************/



// Using Brute Force
// Time Complexity: O(n²)
// Space COmplexity:O(n)
class Solution {
public:
    bool check(vector<int>& nums,int s) {
        unordered_set<int> st;

        for (; s < nums.size(); s++) {
            if (st.count(nums[s])) {
                return false;
            }
            st.insert(nums[s]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        for (int i = 0; i < n; i += 3) {
            if (check(nums,i)) {
                return ops;
            }
            ops++;
        }
        return ops;
    }
};



// Using Right pass
// Time Complexity: O(n)
// Space COmplexity:O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int ops = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (st.count(nums[i])) {
                return ceil((i + 1)/3.0);
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};
