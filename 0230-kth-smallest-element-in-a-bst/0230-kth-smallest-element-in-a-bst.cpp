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
    void dfs(TreeNode* root, int &cnt, int& ans) {
        if (root == NULL) {
            return;
        }
        dfs(root->left, cnt, ans);
        cnt--;
        if (cnt == 0) {
            ans = root->val;
            return;
        }
        dfs(root->right, cnt, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfs(root, k, ans);
        return ans;
    }
};