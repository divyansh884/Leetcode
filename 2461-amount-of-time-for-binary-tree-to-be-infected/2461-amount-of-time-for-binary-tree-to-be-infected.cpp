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
TreeNode* createmap(TreeNode* root, int start,unordered_map<TreeNode*,TreeNode*> &mapping){
    queue<TreeNode*> qe;
    qe.push(root);
    TreeNode* res= NULL;
    mapping[root]=NULL;
    while(!qe.empty()){
        TreeNode* temp=qe.front();
        qe.pop();
        if(temp->val==start)
        res=temp;
        if(temp->left!=NULL){
            mapping[temp->left]=temp;
            qe.push(temp->left);
        }
        if(temp->right!=NULL){
            mapping[temp->right]=temp;
            qe.push(temp->right);
        }
    }
    return res;
}
int infect(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mapping){
    int ans=0;
     unordered_map<TreeNode*,bool> visited;
     queue<TreeNode*> qe;
     visited[root]=true;
     qe.push(root);
     while(!qe.empty()){
        bool flag=0;
        int size=qe.size();
        for(int i=0;i<size;i++){
            TreeNode* temp= qe.front();
            qe.pop();
            if(temp->left!=NULL && !visited[temp->left]){
                flag=1;
                qe.push(temp->left);
                visited[temp->left]=1;
            }
            if(temp->right!=NULL && !visited[temp->right]){
                flag=1;
                qe.push(temp->right);
                visited[temp->right]=1;
            }
            if(mapping[temp]!=NULL && !visited[mapping[temp]]){
                flag=1;
                qe.push(mapping[temp]);
                visited[mapping[temp]]=1;
            }
        }
        if(flag==1)
        ans++;
     }
     return ans;
}
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mapping;
        TreeNode* infectednode=createmap(root,start,mapping);
        return infect(infectednode,mapping);
    }
};