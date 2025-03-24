/*
    LeetCode Medium             : 3169. Count Days Without Meetings
    LeetCode Link               : https://leetcode.com/problems/count-days-without-meetings/description/
*/

/*********************************************************** C++ **************************************************/



//  Using Sorting Approach
//  Time Complexity :O(NlogN);
//  Space Complexity :O(1);
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(begin(meetings), end(meetings));

        int res = 0;
        int s = 0;
        int e = 0;

        for (auto& meet : meetings) {
            if (meet[0] > e) {
                res += meet[0] - e - 1;
            }

            e = max(e, meet[1]);
        }

        if (days > e) {
            res += days - e;
        }
        return res;
    }
};
