/*
    LeetCode Easy               : 2108. Find First Palindromic String in the Array
    Leetcode Link               : https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
*/

/*********************************************************** C++ **************************************************/



// Using Two Pointers
// Time Complexity : O(n * m);
// Space Complexity: O(1);
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (string& word : words) {
            if (isPalindrome(word)) {
                return word; // Return first palindromic word
            }
        }
        return ""; // No palindrome found
    }
};
