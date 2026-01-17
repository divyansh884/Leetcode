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
    bool dfs(TreeNode* root, TreeNode* p) {
        if (root == NULL)
            return false;
       bool left=dfs(root->left,p);
       bool right=dfs(root->right,p);
       if(left || right || root==p)
       return true;
       return false;
    }
    void dfs1(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == NULL)
            return;
        if (dfs(root, p) && dfs(root, q))
            ans = root;
        dfs1(root->left, p, q, ans);
        dfs1(root->right, p, q, ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        dfs1(root,p,q,ans);
        return ans;

    }
};