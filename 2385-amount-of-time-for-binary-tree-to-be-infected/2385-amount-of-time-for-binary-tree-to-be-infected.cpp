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
void dfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* &ans,int &st){
    if(root==NULL)
    return;
    if(root->left)
    mp[root->left]=root; 
    if(root->right)
    mp[root->right]=root;
    if(root->val==st)
    ans=root;
    dfs(root->left,mp,ans,st);
    dfs(root->right,mp,ans,st);
}
int dist(TreeNode* root){
if(!root)
return -1;
int left=1+dist(root->left);
int right=1+dist(root->right);
return max(left,right);
}
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;
        TreeNode* st=NULL;
        mp[root]=NULL;
        dfs(root,mp,st,start);
        int take=dist(st);
        int dd=0;
        while(mp[st]!=NULL){
            TreeNode* parent=mp[st];
            dd++;
            int d=0;
            if(parent->left && parent->left!=st)
            d=1+dist(parent->left);
            if(parent->right && parent->right!=st)
            d=1+dist(parent->right);
            take=max(dd+d,take);
            st=parent;
        }
        return take;
    }
};