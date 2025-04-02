/*
    LeetCode Easy               : 2873. Maximum Value of an Ordered Triplet I
    LeetCode Link               : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/
*/

/*********************************************************** C++ **************************************************/



// Using AOC 
// Time Complexity : O(n³)
// Space Complexity: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = size(nums);
        long long ans = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                for(int k = j + 1;k<n;k++){
                    ans = max(ans,(long long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        if(ans < 0){
            ans = 0;
        }
        return ans;
    }
};



// Using AOC 
// Time Complexity : O(n³)
// Space Complexity: O(1)
