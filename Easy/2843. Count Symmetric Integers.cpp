/*
    LeetCode Easy               : 2843. Count Symmetric Integers
    Leetcode Link               : https://leetcode.com/problems/count-symmetric-integers/
*/

/*********************************************************** C++ **************************************************/


// Usinig Brute Force
// Time Complexity:O(digits *(high - low + 1))
// Space Complexity:O(1)
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            string s = to_string(i);
            int len = s.length();
            if (len % 2 != 0) continue; // Only even-digit numbers

            int half = len / 2;
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < half; ++j) {
                sum1 += s[j] - '0';
            }
            for (int j = half; j < len; ++j) {
                sum2 += s[j] - '0';
            }

            if (sum1 == sum2) {
                count++;
            }
        }
        return count;
    }
};


// Usinig Optimal Approach
// Time Complexity:O(n)
// Space Complexity:O(1)
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans =0;
        for(int i = low ;i<=high;i++){
            if(i >=10 && i <=99 && i % 11 ==0){
                ans++;
            }else if(i >=1000 && i <= 9999){
                int f = i / 1000;
                int s = (i/100)%10;
                int t = (i/10)%10;
                int ft = i % 10;

                if(f+ s == t+ft){
                    ans++;
                }
            }
        }
        return ans;
    }
};
