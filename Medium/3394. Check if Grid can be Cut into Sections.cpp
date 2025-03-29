/*
    LeetCode Medium             : 3394. Check if Grid can be Cut into Sections
    LeetCode Link               : https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/
*/

/*********************************************************** C++ **************************************************/



// Using Sorting
// Time Complexity : O(nlogn);
// Space Complexity: O(1);
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[1] > intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // X-axis
        vector<vector<int>> hor;
        
        // Y-axis
        vector<vector<int>> vert;

        for(auto &cord:rectangles){
            int x1 = cord[0];
            int y1 = cord[1];
            int x2 = cord[2];
            int y2 = cord[3];

            hor.push_back({x1 , x2});
            vert.push_back({y1 , y2});
        }

        vector<vector<int>> res1 = merge(hor);
        vector<vector<int>> res2 = merge(vert);

        return res1.size() >= 3 || res2.size() >= 3;
    }
};
