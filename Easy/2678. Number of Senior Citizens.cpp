/*
    LeetCode Easy               : 1534. Count Good Triplets
    Leetcode Link               : https://leetcode.com/problems/number-of-senior-citizens/description/
*/

/*********************************************************** C++ **************************************************/


// Time Comp : O(n)
// Space Comp :O(1)
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i = 0;i<details.size();i++){
        string str = details[i].substr(11,2);
        int age = stoi(str);
            if(age > 60){
                ans++;
            }
        }
        return ans;
    }
};
