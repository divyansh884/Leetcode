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
    int n,i=0;

    TreeNode* Construct(int Bound,vector<int>& Pre)
    {
        if(i>=n || Pre[i]>Bound) return nullptr;

        TreeNode *a = new TreeNode(Pre[i++]);
        a->left=Construct(a->val,Pre);
        a->right=Construct(Bound,Pre);
        return a;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& Pre) {
        n=Pre.size(); 
        return Construct(INT_MAX,Pre);
    }
};