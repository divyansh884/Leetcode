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
void f(TreeNode* root,string &s,vector<string> &ans){
    if(root==NULL)
    return;
    if(s.size()!=0){
    s.push_back('-');
    s.push_back('>');
    }
    s.push_back(root->val+'0');
    if(!root->left && !root->right){
        ans.push_back(s);
    }
    f(root->left,s,ans);
    f(root->right,s,ans);  
    s.pop_back();
    if(s.size()!=0){
    s.pop_back();
    s.pop_back();
    }
}
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        vector<string> ans;
        f(root,s,ans);
        return ans;
    }
};