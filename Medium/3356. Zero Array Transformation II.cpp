/*
    LeetCode Medium             : 3356. Zero Array Transformation II
    LeetCode Link               : https://leetcode.com/problems/zero-array-transformation-ii/description/
*/

/*********************************************************** C++ **************************************************/

// Using Difference array with binary Search
// Time Complexity :O(logQ * (Q + N)) 
// Space Complexity:O(1)
class Solution {
public:
    int n;
    int Q;

    bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);

        //O(Q)
        for(int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r   = queries[i][1];
            int x     = queries[i][2];

            diff[l] += x;
            if(r+1 < n)
                diff[r+1] -= x;
        }

        int cumSum = 0;
        //O(n)
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];

            diff[i] = cumSum;

            if(nums[i] - diff[i] > 0) { //nums[i] 0 nahi ban paya
                return false;
            }
        }

        return true;

    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        auto lambda = [](int x) {
            return x == 0;
        };

        if(all_of(begin(nums), end(nums), lambda)) {
            return 0; //no query required because all are already zero
        }

        int l = 0;
        int r = Q-1;
        int k = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(checkWithDifferenceArrayTeq(nums, queries, mid) == true) {
                k = mid+1; //possible answer
                r = mid-1;
            } else {
                 l = mid+1;
            }
        }

        return k;
    }
};



// Using Line Sweep
// Time Complexity :O(Q + N)
// Space Complexity:O(N)
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, queryCount = 0;
        vector<int> diffArray(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + diffArray[i] < nums[i]) {
                queryCount++;
                if (queryCount > queries.size())
                    return -1;

                int left = queries[queryCount - 1][0],
                    right = queries[queryCount - 1][1],
                    value = queries[queryCount - 1][2];
                if (right >= i) {
                    diffArray[max(left, i)] += value;
                    if (right + 1 < diffArray.size()) {
                        diffArray[right + 1] -= value;
                    }
                }
            }
            sum += diffArray[i];
        }
        return queryCount;
    }
};

