/*
    LeetCode Medium             : 1358. Number of Substrings Containing All Three Characters
    LeetCode Link               : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
*/

/*********************************************************** C++ **************************************************/

// Using Sliding Window Approach
// Time Complexity : O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> mp(3,0);

        int i =0;
        int j = 0;
        int res = 0;
        while(j < n){
            char ch = s[j];
            mp[ch - 'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                res += (n - j);
                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return res;
    }
};
