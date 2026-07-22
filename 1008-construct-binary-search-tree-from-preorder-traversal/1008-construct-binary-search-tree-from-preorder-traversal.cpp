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
class Solution {
public:
TreeNode* bst(vector<int> & arr,int &index,int lower,int upper){
    if(index>=arr.size() || arr[index]<lower || arr[index]>upper)
    return NULL;
    TreeNode* root= new TreeNode(arr[index++]);
    root->left= bst(arr,index,lower,root->val);
    root->right= bst(arr,index,root->val,upper);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
          int index = 0;
        return bst(preorder,index,INT_MIN,INT_MAX);
    }
};