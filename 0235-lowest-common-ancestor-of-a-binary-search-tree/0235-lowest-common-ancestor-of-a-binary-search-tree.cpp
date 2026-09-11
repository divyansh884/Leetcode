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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
        return nullptr;
        if(root->val==p->val || root->val==q->val)
        return root;
        if(root->val>min(p->val,q->val) && root->val<max(p->val,q->val))
        return root;
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l!=NULL)
        return l;
        if(r!=NULL)
        return r;
        return nullptr;
    }
};