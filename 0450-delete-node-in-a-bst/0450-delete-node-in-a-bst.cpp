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
    int findmax(TreeNode*& root) {
        int ans;
        TreeNode* temp = root;
        ans = temp->val;
        while (temp->right != NULL) {
            ans = temp->val;
            temp = temp->right;
        }
        ans= temp->val;
        return ans;
    }
    TreeNode* deleteNode(TreeNode*& root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->left != NULL && root->right != NULL) {
                int maxi = findmax(root->left);
                root->val = maxi;
                root->left = deleteNode(root->left, maxi);
                return root;
            }
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else {
            root->right = deleteNode(root->right, key);
            return root;
        }
        return NULL;
    }
};