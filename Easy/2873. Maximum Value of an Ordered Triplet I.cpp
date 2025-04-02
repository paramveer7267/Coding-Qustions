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



// Using Better Approach
// Time Complexity : O(n)
// Space Complexity: O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = size(nums);
        long long ans = INT_MIN;
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        for (int j = 1; j < n; j++) {
            leftMax[j] = max(leftMax[j - 1], nums[j - 1]);
        }

        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j + 1], nums[j + 1]);
        }

        for(int j = 1 ;j<n;j++){
            ans = max(ans,(long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return ans;
    }
};



// Using Optimal Approach
// Time Complexity : O(n)
// Space Complexity: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = size(nums);
        long long ans = INT_MIN;
        long long maxDiff = 0;
        long long maxi = 0;

        for(int  k = 0;k<n;k++){
            ans = max(ans , maxDiff * nums[k]);
            maxDiff = max(maxDiff , maxi - nums[k]);
            maxi = max(maxi,(long long)nums[k]);
        }
        return ans;
    }
};
