/*
    LeetCode Medium             : 2594. Minimum Time to Repair Cars
    LeetCode Link               : https://leetcode.com/problems/minimum-time-to-repair-cars/description/
*/

/*********************************************************** C++ **************************************************/



// Using Binary Search
// Time Complexity: O(N * log(maxR * cars * cars));
// Space Complexity:O(1);
class Solution {
public:
    typedef long long ll;
    bool isPossible(vector<int>& ranks, int cars, ll mid){
        ll carF = 0;

        for(int i = 0;i<ranks.size();i++){
            carF += sqrt(mid/ranks[i]);
        }

        return carF >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        ll l = 1;
        int maxR = *max_element(begin(ranks),end(ranks));
        ll r = 1ll * maxR * cars * cars;

        ll res = -1;

        while(l <= r){
            ll mid = l + (r - l)/2;

            if(isPossible(ranks,cars,mid)){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;

    }
};
