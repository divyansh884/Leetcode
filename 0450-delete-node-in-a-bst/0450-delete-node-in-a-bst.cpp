class Solution {
public:
    void travel(TreeNode* root, TreeNode*& target, TreeNode*& parent, int val, TreeNode* prev = nullptr) {
        if (root == nullptr)
            return;
            
        if (root->val == val) {
            target = root;
            parent = prev; 
            return;
        }
        
        if (root->val < val) {
            travel(root->right, target, parent, val, root);
        } else {
            travel(root->left, target, parent, val, root);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        TreeNode* ans = nullptr;
        TreeNode* prev = nullptr; 
        
        travel(root, ans, prev, key);

        if (ans == nullptr) return root;

        if (ans->left != nullptr && ans->right != nullptr) {
            TreeNode* successorParent = ans;
            TreeNode* successor = ans->right;
            
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            
            swap(ans->val, successor->val);
            
            ans = successor;
            prev = successorParent;
        }

        TreeNode* child = (ans->left != nullptr) ? ans->left : ans->right;

        if (prev == nullptr) {
            root = child;
        } 
        else if (prev->left == ans) {
            prev->left = child; 
        } 
        else {
            prev->right = child;
        }

        delete ans;
        
        return root;
    }
};