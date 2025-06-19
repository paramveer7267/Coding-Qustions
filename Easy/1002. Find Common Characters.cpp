/*
    LeetCode Easy               : 1002. Find Common Characters
    Leetcode Link               : https://leetcode.com/problems/find-common-characters/description/
*/

/*********************************************************** C++ **************************************************/


// Using Multiset Approach
// Time comp:O(N * L log L) //L = average length of word, N = Number of words
// Space comp:O(L)
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        multiset<char> temp(words[0].begin(), words[0].end());

        for (int i = 1; i < words.size(); i++) {
            multiset<char> temp2;
            multiset<char> currentWord(words[i].begin(), words[i].end());

            for (char c : currentWord) {
                // If the character exists in temp, include it once
                if (temp.count(c)) {
                    temp2.insert(c);
                    temp.erase(temp.find(c));  // remove one occurrence
                }
            }

            temp = temp2; // update after processing whole word
        }

        // Convert chars to strings
        vector<string> res;
        for (char c : temp) {
            res.push_back(string(1, c));
        }

        return res;
    }
};

