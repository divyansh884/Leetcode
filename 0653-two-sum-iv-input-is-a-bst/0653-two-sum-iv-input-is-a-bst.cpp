/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, deque<int>& mapping) {
        if (root == NULL)
            return;
        solve(root->left, mapping);
        mapping.push_back(root->val);
        solve(root->right, mapping);
    }
    bool findTarget(TreeNode* root, int k) {
        deque<int> mapping;
        solve(root, mapping);
        for (auto it : mapping) {
            int m = k - it;
            if(m==it)
            return false;
            if (find(mapping.begin(),mapping.end(),m) != mapping.end())
                return true;
        }
        return false;
    }
};