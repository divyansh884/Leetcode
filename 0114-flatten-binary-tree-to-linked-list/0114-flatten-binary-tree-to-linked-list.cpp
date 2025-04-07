/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    void solve(TreeNode* &root, vector<int> &ans,int &index,int n){
        if(index>=n){
            return;
        }
        if(root->right==NULL && index!=n-1){
            root->right=new TreeNode(0);
        }
        root->val=ans[index++];
        root->left=NULL;
        solve(root->right,ans,index,n);
    }
    void flatten(TreeNode* a) {
        if(a==NULL)
        return;
        vector<int> ans;
        int index = 0;
        preorder(a, ans);
        int n= ans.size();
        solve(a, ans,index,n);
    }
};
