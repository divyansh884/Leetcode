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
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp,
             TreeNode*& ans, int& st) {
        if (root == NULL)
            return;
        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;
        if (root->val == st)
            ans = root;
        dfs(root->left, mp, ans, st);
        dfs(root->right, mp, ans, st);
    }
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
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* st = NULL;
        unordered_map<TreeNode*, TreeNode*> parent;
         dfs(root, parent, st, start);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(st);
        visited[st] = true;
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if (temp->right && !visited[temp->right]) {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if (parent[temp] && !visited[parent[temp]]) {
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        } 
         return dist-1;
    }
};