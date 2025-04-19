/*
    LeetCode Medium             : 38. Count and Say
    LeetCode Link               : https://leetcode.com/problems/count-and-say/description/
*/

/*********************************************************** C++ **************************************************/


// Using recursion
// Time Complexity: O(2ⁿ)
// Space Complexity: O(2ⁿ)
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }

        string say = countAndSay(n - 1);
        string res = "";
        for(int i = 0;i< say.size();i++){
            char ch = say[i];
            int count = 1;

            while( i < say.size() - 1 && say[i] == say[i + 1]){
                count++;
                i++;
            }

            res += to_string(count) + string(1,ch);
        }
        return res;
    }
};
