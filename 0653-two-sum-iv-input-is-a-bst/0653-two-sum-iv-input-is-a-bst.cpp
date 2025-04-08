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
    void solve(TreeNode* root, set<int>& mapping) {
        if (root == NULL)
            return;
        mapping.insert(root->val);
        solve(root->left, mapping);
        solve(root->right, mapping);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> mapping;
        solve(root, mapping);
        for (auto it : mapping) {
            int m = k - it;
            if(m==it)
            return false;
            if (mapping.find(m) != mapping.end())
                return true;
        }
        return false;
    }
};