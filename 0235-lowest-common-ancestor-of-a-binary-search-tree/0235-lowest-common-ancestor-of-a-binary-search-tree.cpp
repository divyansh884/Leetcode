/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void f(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
    if (!root)
        return;
    int parentvalue = root->val;
    if ((parentvalue <= p->val && parentvalue >= q->val) ||
        (parentvalue >= p->val && parentvalue <= q->val)) {
        if (ans == NULL)
            ans = root;
    }
    if(parentvalue>p->val && parentvalue>q->val)
    f(root->left, p, q, ans);
    if(parentvalue<p->val && parentvalue<q->val)
    f(root->right, p, q, ans);
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        TreeNode* ans = NULL;
        f(root, p, q, ans);
        return ans;
    }
};