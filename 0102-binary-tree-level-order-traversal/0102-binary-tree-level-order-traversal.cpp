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
       vector<vector<int>> ans;
       queue<TreeNode*> qe;
       vector<int> me;
       qe.push(root);
       qe.push(NULL);
       if(root==NULL)
        return ans;
       while(!qe.empty()){
        TreeNode* temp= qe.front();
        qe.pop();
        if(temp==NULL){
            ans.push_back(me);
            me.clear();
            if(!qe.empty())
            qe.push(NULL);
        }
        else{
            me.push_back(temp->val);
            if(temp->left!=NULL)
            qe.push(temp->left);
            if(temp->right!=NULL)
            qe.push(temp->right);
        }
       }
        return ans;
    }
};