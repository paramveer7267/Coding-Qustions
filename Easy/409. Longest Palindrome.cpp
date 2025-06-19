/*
    LeetCode Easy               : 409. Longest Palindrome
    Leetcode Link               : https://leetcode.com/problems/longest-palindrome/description/
*/

/*********************************************************** C++ **************************************************/


// Using Map Approach
// Time complexity:O(1)
// Space complexity:O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            if (mp[s[i]] % 2 == 0) {
                res += 2;
            }
        }

        for (const auto& [ch, freq] : mp) {
            if (freq % 2 != 0) {
                res++;
                break;
            }
        }

        return res;
    }
};



// Using Bitset Approach
// Time complexity:O(1)
// Space complexity:O(1)
class Solution {
public:
    int longestPalindrome(string s) {
        bitset<56> seen;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a']) {
                res += 2;
                seen[s[i] - 'a']=0;

            } else {
                seen[s[i] - 'a']=1;
            }
        }

        for (char c : s) {
            if (seen[c - 'a']) {
                res++;
                break;
            }
        }
        return res;
    }
};
