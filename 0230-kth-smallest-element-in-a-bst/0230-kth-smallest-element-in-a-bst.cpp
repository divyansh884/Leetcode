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
void travel(TreeNode* root,vector<int>& ans){
    if(root==NULL)
    return;
    travel(root->left,ans);
    ans.push_back(root->val);
    travel(root->right,ans);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        travel(root,ans);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};