/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool check(TreeNode *p,TreeNode*q){
    if(p==NULL && q==NULL)
    return true;
    if(p==NULL && q!=NULL)
    return false;
    if(p!=NULL && q==NULL)
    return false;
    bool cc= check(p->left,q->right);
    bool cc1= check(p->right,q->left);
    bool cc2= p->val==q->val;
    if(cc1 && cc2 & cc)
    return true;
    return false;
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;
        return check(root->left , root->right);
    }
};