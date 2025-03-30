/*
    LeetCode Medium             : 763. Partition Labels
    LeetCode Link               : https://leetcode.com/problems/partition-labels/description/
*/

/*********************************************************** C++ **************************************************/



// Using Two Pointers
// Time Complexity : O(n)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        int i = 0, j = 0, end;

        end = mp[s[j]];
        while (j < n) {

            if (mp[s[j]] > end) {
                end = mp[s[j]];
            }

            if (j == end) {
                ans.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }
        return ans;
    }
};
