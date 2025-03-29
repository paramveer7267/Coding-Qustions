/*
    LeetCode Medium             : 2780. Minimum Index of a Valid Split
    LeetCode Link               : https://leetcode.com/problems/minimum-index-of-a-valid-split/description/
*/

/*********************************************************** C++ **************************************************/



// Using Two Maps
// Time Complexity: O(n);
// Space Complexity:O(n);
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i  =0;i<n;i++){
            mp2[nums[i]]++;
        }

        for(int i = 0;i<n;i++){
            mp1[nums[i]]++;
            mp2[nums[i]]--;
            if(mp1[nums[i]]*2 > (i + 1) && mp2[nums[i]]*2 > (n - i - 1)){
                return i;
            }
        }
        return -1;
    }
};



// Using Boore Moyer(Majority Element)
// Time Complexity: O(n);
// Space Complexity:O(1);
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int maj = -1;
        int count = 0;

        // Boore Moyer Algorithm
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                maj = nums[i];
                count = 1;
            } else if (nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }

        // finding freq
        int majC = 0;
        for (int& num : nums) {
            if (maj == num) {
                majC++;
            }
        }
        count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maj) {
                count++;
            }

            int remC = majC - count;
            int n1 = i + 1;
            int n2 = n - i - 1;
            if (count * 2 > n1 && remC * 2 > n2) {
                return i;
            }
        }
        return -1;
    }
};
