 /*
    LeetCode Easy               : 2176. Count Equal and Divisible Pairs in an Array
    LeetCode Link               : https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/
*/

/*********************************************************** C++ **************************************************/


// Using Brute Force
// Time Complexity: O(n²)
// Space Complexity: O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1 ;j<nums.size();j++){
                if(nums[i] == nums[j] && (i * j) % k == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};



// Using Sliding Window
// Time Complexity: O(n * (log(k) + sqrt(k)))
// Space Complexity: O(n)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;

        unordered_map<int,vector<int>> indicesMap;
        for(int i = 0;i<n ;i++){
            indicesMap[nums[i]].push_back(i);
        }

        unordered_set<int> div;
        for(int f = 1; f * f <= k;f++){
            if(k % f==0){
                div.insert(f);
                div.insert(k/f);
            }
        }

        for(auto &[num,indices] : indicesMap){
            unordered_map<int,int> factorsMap;

            for(int i :indices){
                int GCD = gcd(i,k);
                int j = k / GCD;

                res += factorsMap[j];

                for(int f:div){
                    if(i % f == 0){
                        factorsMap[f]++;
                    }
                }
            }
        }
        return res;
    }
};
