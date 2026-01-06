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
    int maxLevelSum(TreeNode* root) {
        int level = 1, rel = 1;
        queue<TreeNode*> q;
        int sum = 0, ans = root->val;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* tp = q.front();
            q.pop();
            if (tp == NULL) {
                if (!q.empty())
                    q.push(NULL);
                if (sum > ans) {
                    ans = sum;
                    rel = level;
                }
                level++;
                sum=0;
            } else {
                sum += tp->val;
                if (tp->left)
                    q.push(tp->left);
                if (tp->right)
                    q.push(tp->right);
            }
        }
        return rel;
    }
};