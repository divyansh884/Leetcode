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
    void f(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root == NULL)
            return;
        if (root->left)
            parent[root->left] = root;
        if (root->right)
            parent[root->right] = root;
        f(root->left, parent);
        f(root->right, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        f(root, parent);
        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        visited[target] = true;
        vector<int> ans;
        while(!q.empty()){
            int dist=q.front().second;
            TreeNode* node=q.front().first;
            q.pop();
            if(dist==k){
                ans.push_back(node->val);
                continue;
            }
            if(node->left && !visited[node->left]){
                visited[node->left]=1;
                q.push({node->left,dist+1});
            }
            if(node->right && !visited[node->right]){
                visited[node->right]=1;
                q.push({node->right,dist+1});
            }
            if(parent[node] && !visited[parent[node]]){
                visited[parent[node]]=1;
                q.push({parent[node],dist+1});
            }
        }
        return ans;
    }
};