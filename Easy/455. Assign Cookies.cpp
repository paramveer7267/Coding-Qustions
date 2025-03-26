/*
    LeetCode Easy               : 455. Assign Cookies
    Leetcode Link               : https://leetcode.com/problems/assign-cookies/description/
*/

/*********************************************************** C++ **************************************************/



// Using Sorting & Two Pointer
// Time Complexity : O(n log n + m log m)
// Space Complexity: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes
        
        int i = 0, j = 0, ans = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {  // If cookie satisfies the child
                ans++;
                i++;  // Move to the next child
            }
            j++;  // Move to the next cookie (used or too small)
        }

        return ans;
    }
};
