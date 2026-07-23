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
    int f(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;
        int l = f(root->left, ans);
        int r = f(root->right, ans);
        int num1 = max(l + root->val, max(r + root->val, l + r + root->val));
        ans = max(ans, max(num1, root->val));
        return max(max(l, r) + root->val, root->val);
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int ans = root->val;
        f(root, ans);
        return ans;
    }
};