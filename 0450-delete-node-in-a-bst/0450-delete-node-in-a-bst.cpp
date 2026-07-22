class Solution {
public:
    void travel(TreeNode* root, TreeNode*& ans, int val) {
        if (root == NULL)
            return;
        if (root->val == val) {
            ans = root;
            return;
        }
        if (root->val < val) {
            travel(root->right, ans, val);
        } else
            travel(root->left, ans, val);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
            
        TreeNode* ans = NULL;
        travel(root, ans, key);
        
        TreeNode* prev = NULL;
        if (ans == nullptr)
            return root;

        TreeNode* curr = root;
        while (curr != ans) {
            prev = curr;
            if (key < curr->val) curr = curr->left;
            else curr = curr->right;
        }

        if (ans->left == nullptr && ans->right == nullptr) {
            if (prev == nullptr) return nullptr; 
            
            if (prev->left == ans) prev->left = nullptr;
            else prev->right = nullptr;
            
            delete ans;
            return root;
        }

        if (ans->right != nullptr) {
            TreeNode* targetToSwap = ans; 
            
            prev = ans;
            ans = ans->right;
            
            while (ans->left != nullptr) {
                prev = ans;
                ans = ans->left;
            }
            
            swap(targetToSwap->val, ans->val);
            
            if (prev->left == ans) {
                prev->left = ans->right;
            } else {
                prev->right = ans->right; 
            }
            
            delete ans;
            return root;
        }

        if (prev == nullptr) {
            TreeNode* newRoot = ans->left;
            delete ans;
            return newRoot;
        }
        
        if (prev->left == ans) {
            prev->left = ans->left;
        } else {
            prev->right = ans->left;
        }
        
        delete ans;
        return root;
    }
};