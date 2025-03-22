/*
    LeetCode Easy               : 2206. Divide Array Into Equal Pairs
    Leetcode Link               : https://leetcode.com/problems/divide-array-into-equal-pairs/description/
*/

/*********************************************************** C++ **************************************************/



// Using Constraint Observation Approach
// Time Complexity :O(N)
// Space Complexity:O(500) ~ O(1)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> arr(501,0);

        for(int i = 0;i<nums.size();i++){
            arr[nums[i]]++;
        }

        for(int i =1;i<arr.size();i++){
            if(arr[i] == 1 || arr[i]%2 != 0){
                return false;
            }
        }
        return true;
    }
};



// Using Map
// Time Complexity :O(N)
// Space Complexity:O(N)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int &x : nums) {
            mp[x]++;
        }

        for(auto &it : mp) {
            if(it.second % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};


// Using Set
// Time Complexity :O(N)
// Space Complexity:O(N)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> st;

        for(int &x : nums) {
            if(st.count(x)) {
                st.erase(x);
            } else {
                st.insert(x);
            }
        }

        return st.empty();
    }
};



// Using sorting and comparing
// Time Complexity :O(N*logN)
// Space Complexity:O(1)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i = 1; i < n; i+=2) {
            if(nums[i] != nums[i-1]) {
                return false;
            }
        }

        return true;
    }
};


// Using sorting and xor
// Time Complexity :O(N * logN)
// Space Complexity:O(1)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i = 1; i < n; i+=2) {
            if((nums[i] ^ nums[i-1]) != 0) {
                return false;
            }
        }

        return true;
    }
};
