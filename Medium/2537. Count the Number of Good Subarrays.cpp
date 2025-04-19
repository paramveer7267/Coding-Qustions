/*
    LeetCode Medium             : 2537. Count the Number of Good Subarrays
    LeetCode Link               : https://leetcode.com/problems/count-the-number-of-good-subarrays/description/
*/

/*********************************************************** C++ **************************************************/


// Using Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        long long result = 0;

        unordered_map<int, int> mp;

        long long pairs = 0;

        while(j < n) {
            pairs += mp[nums[j]]; //isse pehle kitni baar nums[j] dekha hai humne
            mp[nums[j]]++;

            while(pairs >= k) {
                result += (n-j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }

            j++;
        }

        return result;
    }
};
