class Solution {
public:
    void f(TreeNode* root, TreeNode* prev, TreeNode*& temp, TreeNode*& parent, int key) {
        if (root == NULL)
            return;
            
        if (root->val == key) {
            temp = root;
            parent = prev;
            return;
        }
        
        if (key < root->val) 
            f(root->left, root, temp, parent, key);
        else 
            f(root->right, root, temp, parent, key);
    }
    
    void h(TreeNode* temp, TreeNode* parent, TreeNode*& root) {
        if (temp->left == NULL && temp->right == NULL) {
            if (parent == NULL) { 
                root = NULL;
            } else if (parent->left == temp) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            delete temp;
            return;
        }
        
        if (temp->right != NULL) {
            TreeNode* te = temp->right;
            TreeNode* prev = temp;
            while (te->left != NULL) {
                prev = te;
                te = te->left;
            }
            swap(temp->val, te->val);
            if (prev == temp)
                prev->right = te->right;
            else
                prev->left = te->right;
                
            delete te;
            return;
        }
        
        if (temp->left != NULL) {
            TreeNode* te = temp->left;
            TreeNode* prev = temp;
            while (te->right != NULL) {
                prev = te;
                te = te->right;
            }
            swap(temp->val, te->val);
            if (prev == temp)
                prev->left = te->left;
            else
                prev->right = te->left;
                
            delete te;
            return;
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = NULL;
        TreeNode* parent = NULL;
        
        f(root, NULL, temp, parent, key);
        
        if (temp == NULL)
            return root;
            
        h(temp, parent, root);
        
        return root;
    }
};