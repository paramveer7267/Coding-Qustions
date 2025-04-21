/*
    LeetCode Medium             : 2486. Append Characters to String to Make Subsequence
    LeetCode Link               : https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/
*/

/*********************************************************** C++ **************************************************/


// Using Two Pointers
// Time Comp : O(n)
// Space Comp: O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.size()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }
         
        return t.size() - j;
    }
};
