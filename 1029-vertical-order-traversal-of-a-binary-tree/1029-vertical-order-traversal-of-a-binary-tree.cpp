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
void solvel(TreeNode* root,vector<vector<int>> & ans,int row, int col){
    if(root==NULL){
        return;
    }
    row++;
    col--;
    ans.push_back({col,row,root->val});
    solvel(root->left,ans,row,col);
    solver(root->right,ans,row,col); 
}
void solver(TreeNode* root,vector<vector<int>> & ans,int row, int col){
    if(root==NULL){
        return;
    }
    row++;
    col++;
    ans.push_back({col,row,root->val});
    solvel(root->left,ans,row,col);
    solver(root->right,ans,row,col); 
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int row=0,col=0;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back({col,row,root->val});
        solvel(root->left,ans,row,col);
        solver(root->right,ans,row,col);  
        sort(ans.begin(),ans.end());
        vector<vector<int>> ans1;
        unordered_map<int,bool> mp;
        vector<int> me;
        me.push_back(ans[0][2]);
        mp[ans[0][0]]=true;
        for(int i=1;i<ans.size();i++){
            if(mp[ans[i][0]]==true){
                me.push_back(ans[i][2]);
            }
            else{
                ans1.push_back(me);
                me.clear();
                me.push_back(ans[i][2]);
                mp[ans[i][0]]=true;
            }
        }
        if(!me.empty())
        ans1.push_back(me);
        return ans1;
    }
};