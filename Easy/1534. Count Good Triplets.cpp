/*
    LeetCode Easy               : 1534. Count Good Triplets
    Leetcode Link               : https://leetcode.com/problems/count-good-triplets/description/
*/

/*********************************************************** C++ **************************************************/


// Usinig Brute Force
// Time Complexity:O(n3)
// Space Complexity:O(1)
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int count = 0;

        for(int i = 0; i <= n-3; i++) {
            for(int j = i+1; j <= n-2; j++) {

                if(abs(arr[i] - arr[j]) <= a) {
                    for(int k = j+1; k <= n-1; k++) {
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;

    }
};
