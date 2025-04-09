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
class BSTIterator {
    TreeNode* root;
    vector<int> travel;
    int index;
public:
void solve(TreeNode* root,vector<int> &travel){
    if(root==NULL)
    return;
    solve(root->left,travel);
    travel.push_back(root->val);
    solve(root->right,travel);
}
    BSTIterator(TreeNode* root) {
        this->root=root;
        this->index=0;
        solve(root,travel);
    }
    
    int next() {
        return travel[index++];
    }
    
    bool hasNext() {
        if(index+1<0 || index+1>travel.size())
        return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */