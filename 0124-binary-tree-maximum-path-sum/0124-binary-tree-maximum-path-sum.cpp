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
int dfs(TreeNode* root,int &ans){
    if(root==NULL)
    return 0;
    int left=dfs(root->left,ans);
    int right=dfs(root->right,ans);
    int temp=left+right+root->val;
    int temp1=max(left,right)+root->val;
    ans= max(ans,max(temp1,max(temp,root->val)));
    return max(temp1,root->val);
}
    int maxPathSum(TreeNode* root) {
    if(root==NULL)
    return 0;
    int ans=root->val;
    dfs(root,ans);
    return ans;
    }
};