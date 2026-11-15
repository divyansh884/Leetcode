/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void f(TreeNode* root, int p, int q, TreeNode* &ans) {
        if (root == NULL)
            return;
        if (root->val == p || root->val == q) {
            ans = root;
            return;
        }
        if (root->val > min(p, q) && root->val < max(p, q)) {
            ans = root;
            return;
        }
        if (root->val < min(p, q))
            f(root->right, p, q, ans);
        else if (root->val > max(p, q))
            f(root->left, p, q, ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        f(root,p->val,q->val,ans);
        return ans;
    }
};