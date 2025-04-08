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
void solve(TreeNode* root,vector<int> &ans, set<int> &also) {
        if(root==NULL)
        return;
        solve(root->left,ans,also);
        ans.push_back(root->val);
        also.insert(root->val);
        solve(root->right,ans,also);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        set<int> also;
        solve(root,ans,also);
        if(also.size()<ans.size())
        return false;
        vector<int> check=ans;
        sort(check.begin(),check.end());
        return check==ans;
    }
};