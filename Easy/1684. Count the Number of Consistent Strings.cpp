/*
    LeetCode Easy               : 1684. Count the Number of Consistent Strings
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-consistent-strings/description/
*/

/*********************************************************** C++ **************************************************/

// Using Unordered Set Approach
// Time complexity:O(1)
// Space complexity:O(n)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int count = 0;

        for (const string& word : words) {
            bool isValid = true;
            for (char c : word) {
                if (!allowedSet.count(c)) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) count++;
        }

        return count;
    }
};


// Using Bitset Approach
// Time complexity:O(1)
// Space complexity:O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26> allowedBits;

        for (char c : allowed) {
            allowedBits[c - 'a'] = 1;
        }

        int count = 0;
        for (const string& word : words) {
            bool isValid = true;

            for (char c : word) {
                if (!allowedBits[c - 'a']) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) count++;
        }

        return count;
    }
};
