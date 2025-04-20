/*
    LeetCode Medium             : 781. Rabbits in Forest
    LeetCode Link               : https://leetcode.com/problems/rabbits-in-forest/description/
*/

/*********************************************************** C++ **************************************************/


// Using Maps
// Time Comp: O(n)
// Space Comp:O(n)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;

        for(int &x:answers){
            mp[x]++;
        }

        int total = 0;

        for(auto &it : mp){
            int x = it.first;
            int count = it.second;

            int groupSize = (x + 1);
            int groups = ceil((double) count/groupSize);

            total += groups * (groupSize);
        }

        return total;
    }
};
