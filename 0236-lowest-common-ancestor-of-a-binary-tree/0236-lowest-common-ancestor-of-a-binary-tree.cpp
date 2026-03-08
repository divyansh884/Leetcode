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
TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q)
{
    TreeNode* node=root;
    if(node==nullptr) return 0;
    TreeNode* leftside=lca(node->left,p,q);
    TreeNode*  rightside=lca(node->right,p,q);
    if((leftside&&rightside)||(node==p)||(node==q))
    {
        return node;
    }
    if(leftside==nullptr) return rightside;
    return leftside;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      return  lca(root,p,q);
        
    }
};