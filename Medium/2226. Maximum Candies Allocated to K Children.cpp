/*
    LeetCode Medium             : 2226. Maximum Candies Allocated to K Children
    LeetCode Link               : https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/
*/

/*********************************************************** C++ **************************************************/


// Using Brute Force
// Disclaimer:(Gives TLE)
// Time Complexity :O(pow(N,2))
// Space Complexity:O(1)
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxC = 0;
        int total = 0;
        int n = candies.size();

        for(int i = 0;i<n;i++){
            total += candies[i];
            maxC = max(maxC,candies[i]);
        }

        if(total < k){
            return 0;
        }

        for(int c = maxC; c >= 1;c--){
            long long count = 0;
            for(int i =0;i<n;i++){
                count += candies[i]/c;

                if(count >= k){
                    return c;
                }
            }
        }
        return 0;
    }
};



// Using Binary Search (Optimal)
// Time Complexity :O(N * log(maxC))
// Space Complexity:O(1)
class Solution {
public:
    bool candiesGet(vector<int>& candies, int mid, long long k) {
        int n = candies.size();

        for (int i = 0; i < n; i++) {
            k -= candies[i] / mid;

            if (k <= 0) {
                return true;
            }
        }
        return k <= 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxC = 0;
        long long total = 0;
        int n = candies.size();

        for (int i = 0; i < n; i++) {
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if (total < k) {
            return 0;
        }

        int l = 1;
        int r = maxC;
        int res = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (candiesGet(candies, mid, k)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
