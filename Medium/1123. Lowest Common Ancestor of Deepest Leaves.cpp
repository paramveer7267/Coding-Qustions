/*
    LeetCode Medium             : 1123. Lowest Common Ancestor of Deepest Leaves
    LeetCode Link               : https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/
*/

/*********************************************************** C++ **************************************************/



// Using Recursion (One Pass)
// Time Complexity: O(N)
// Space Complexity: O(maxD)
class Solution {
public:
    pair<int, TreeNode*> p;
    int maxD = 0;

    pair<int, TreeNode*> solve(TreeNode* root) {
        if (root == NULL) {
            return {0,NULL};
        }

        auto l = solve(root->left);
        auto r = solve(root->right);

        if (l.first == r.first) {
            return {l.first + 1,root};
        }
        else if(l.first < r.first){
            return {r.first + 1,r.second};
        }
        else return {l.first + 1,l.second};
    }
   
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};
