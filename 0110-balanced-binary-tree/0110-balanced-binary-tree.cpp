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
    int f(TreeNode* root, bool& check) {
        if (root == NULL)
            return 0;
        int l = f(root->left, check);
        int r = f(root->right, check);
        if(abs(l-r)>1)
        check=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool check=true;
        f(root,check);
        return check;
    }
};