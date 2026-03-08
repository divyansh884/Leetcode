/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void f(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
    if(root==NULL)
    return;
    if(root->left)
    parent[root->left]=root;
    if(root->right)
    parent[root->right]=root;
    f(root->left,parent);
    f(root->right,parent);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        f(root,parent);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int dist=0;
        while(!q.empty()){
            int size = q.size();
            if (dist++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                 if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp] );
                    visited[parent[temp]]=true;
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};