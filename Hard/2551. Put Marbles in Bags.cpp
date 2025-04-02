/*
    LeetCode Hard               : 2551. Put Marbles in Bags
    LeetCode Link               : https://leetcode.com/problems/put-marbles-in-bags/description/
*/

/*********************************************************** C++ **************************************************/



// Using PairSum
// Time Complexity: O(nlogn);
// Space Complexity:O(n);
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n  =weights.size();

        int m = n - 1;
        vector<int> pairSum(m,0);

        for(int i =0;i<m;i++){
            pairSum[i] = weights[i] + weights[i + 1];
        }

        sort(begin(pairSum),end(pairSum));
        long maxSum = 0;
        long minSum = 0;
        m--;
        for(int i =0;i<k - 1;i++){
            minSum += pairSum[i];
            maxSum +=pairSum[m--];
        }
        return maxSum - minSum;
    }
};
