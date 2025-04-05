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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int val;
        queue<TreeNode*> qe;
        qe.push(root);
        qe.push(NULL);
        if(root==NULL){
            return ans;
        }
        while(!qe.empty()){
            TreeNode* temp=qe.front();
            qe.pop();
            if(temp==NULL){
                ans.push_back(val);
                if(qe.empty()==false){
                qe.push(NULL);
                }
            }
            else{
                val=temp->val;
                if(temp->left!=NULL){
                    qe.push(temp->left);
                }
                if(temp->right!=NULL)
                qe.push(temp->right);
            }
        }
        return ans;
    }
};