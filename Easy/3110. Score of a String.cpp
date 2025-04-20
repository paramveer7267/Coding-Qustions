/*
    LeetCode Easy               : 3110. Score of a String
    Leetcode Link               : https://leetcode.com/problems/score-of-a-string/description/
*/

/*********************************************************** C++ **************************************************/

// Time Comp: O(n);
// Space Comp:O(1);
class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for(int i = 0;i<s.size() - 1;i++){
            int ch =(int)s[i];
            int ch2 = (int)s[i + 1];
            ans += abs(ch - ch2);
        }
        return ans;
    }
};
