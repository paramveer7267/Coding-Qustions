/*
    LeetCode Easy               : 2490. Circular Sentence
    Leetcode Link               : https://leetcode.com/problems/circular-sentence/description/
*/

/*********************************************************** C++ **************************************************/


// Using Optimal Approach
// Time complexity:O(1)
// Space complexity:O(n)


class Solution {
public:
    bool isCircularSentence(string sen) {
        int j = 0;
        char first = sen[0];
        char last = sen[sen.size() - 1];
        if(first != last){
            return false;
        }
        for(int i=0;i<sen.size();i++){
            if(sen[i] == ' '){
                if(sen[i - 1] != sen[i + 1]){
                    return false;
                }
            }
        }
        return true;
    }
};
