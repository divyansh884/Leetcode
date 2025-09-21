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
    void trav(TreeNode* root, int &count, unordered_map<long long,int> &mp, long long sum, int targetSum) {
        if (!root) return;

        sum += root->val;

        if (mp.find(sum - targetSum) != mp.end()) 
            count += mp[sum - targetSum];

        mp[sum]++;

        if (root->left) trav(root->left, count, mp, sum, targetSum);
        if (root->right) trav(root->right, count, mp, sum, targetSum);

        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long long,int> mp;
        mp[0] = 1;
        trav(root, count, mp, 0LL, targetSum);
        return count;
    }
};
