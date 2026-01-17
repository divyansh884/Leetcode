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
    void dfs(TreeNode* root, int key, TreeNode*& ans,
             unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!root)
            return;
        if (root->val == key) {
            ans = root;
        }
        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;
        dfs(root->left, key, ans, mp);
        dfs(root->right, key, ans, mp);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* target = NULL;
        unordered_map<TreeNode*, TreeNode*> mp;
        dfs(root, key, target, mp);
        if(target==NULL || !root)
        return root;
        TreeNode* exe=target->right;
        if(exe==NULL){
            if(mp[target]==NULL){
                root=target->left;
                return root;
            }
            if(mp[target]->right==target)
            mp[target]->right=target->left;
            else
            mp[target]->left=target->left;
            target->left=NULL;
            return root;
        }
        while(exe->left!=NULL){
            exe=exe->left;
        }
        swap(exe->val,target->val);
            if(mp[exe]->left==exe)
            mp[exe]->left=exe->right;
            if(mp[exe]->right==exe)
            mp[exe]->right=exe->right;
            exe->right=NULL;
        return root;
    }
};