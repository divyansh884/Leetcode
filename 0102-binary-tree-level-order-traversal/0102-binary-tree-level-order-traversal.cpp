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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==NULL)
        return vec;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* tr=q.front();
            q.pop();
            if(tr==NULL){
                vec.push_back(temp);
                if(!q.empty())
                q.push(NULL);
                temp.clear();
                continue;
            }
            temp.push_back(tr->val);
            if(tr->left)
            q.push(tr->left);
            if(tr->right)
            q.push(tr->right);
        }
        return vec;
    }
};