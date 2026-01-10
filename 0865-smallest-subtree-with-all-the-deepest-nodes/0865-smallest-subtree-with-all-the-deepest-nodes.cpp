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
    void dfs(TreeNode* root, unordered_map<TreeNode*, bool>& mp) {
        if (root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* tp = q.front();
            q.pop();
            if (tp != NULL)
                mp[tp] = true;
            if (tp == NULL) {
                if (!q.empty()) {
                    q.push(NULL);
                    mp.clear();
                }
            } else {
                if (tp->left)
                    q.push(tp->left);
                if (tp->right)
                    q.push(tp->right);
            }
        }
    }
    int dfs1(TreeNode* root, unordered_map<TreeNode*, bool>& mp,
             TreeNode*& ans) {
        if (root == NULL)
            return 0;
        int left = dfs1(root->left, mp, ans);
        int right = dfs1(root->right, mp, ans);
        int add = 0;
        if (mp.find(root) != mp.end())
            add = 1;
        if (add + left + right == mp.size() && ans == NULL)
            ans = root;
        return add + left + right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, bool> mp;
        dfs(root, mp);
        TreeNode* ans = NULL;
        dfs1(root, mp, ans);
        return ans;
    }
};