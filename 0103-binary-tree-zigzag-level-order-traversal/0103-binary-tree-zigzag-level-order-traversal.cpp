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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
        queue<TreeNode*> set;
        vector<int> me;
        set.push(root);
        set.push(NULL);
        if(root==NULL)
        return ans;
        while(!set.empty()){
            TreeNode* temp= set.front();
            set.pop();
            if(temp==NULL){
                ans.push_back(me);
                me.clear();
                if(!set.empty())
                set.push(NULL);
            }
            else{
                me.push_back(temp->val);
                if(temp->left!=NULL)
                set.push(temp->left);
                if(temp->right!=NULL)
                set.push(temp->right);
            }
        }
        for(int i=0;i<ans.size();i++){
            if(i%2!=0)
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};