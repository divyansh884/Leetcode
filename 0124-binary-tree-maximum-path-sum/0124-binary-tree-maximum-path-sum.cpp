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
int solve(TreeNode* root,int &ans){
    if(root==NULL){
    return -1001;
    }
    int left=solve(root->left,ans);
    int right=solve(root->right,ans);
    int temp=left+right+root->val;
    int temp2=max(left,right)+root->val;
    ans=max(ans,max(temp2,max(root->val,temp)));
    return max(temp2,root->val);
}
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        if(root==NULL)
        return 0;
        return max(solve(root,ans),ans);
    }
};