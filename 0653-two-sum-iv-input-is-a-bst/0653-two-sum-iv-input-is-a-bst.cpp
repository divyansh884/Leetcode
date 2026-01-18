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
bool dfs(TreeNode* root,int k,unordered_map<int,int> & mp){
    if(!root)
    return NULL;
    if(mp.find(k-root->val)!=mp.end())
    return true;
    mp[root->val]++;
    bool left=dfs(root->left,k,mp);
    bool right=dfs(root->right,k,mp);
    return left|| right;
}
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        return dfs(root,k,mp);
    }
};