class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long f(TreeNode* root, unordered_map<TreeNode*, long long>& mp) {
        if (root == NULL)
            return 0;

        long long left = f(root->left, mp);
        long long right = f(root->right, mp);

        return mp[root] = left + right + root->val;
    }

    void dfs(TreeNode* root, long long totalsum, long long &ans,
             unordered_map<TreeNode*, long long> &mp) {

        if (root == NULL)
            return;

        long long part = mp[root];
        long long product = part * (totalsum - part);

        ans = max(ans, product);

        dfs(root->left, totalsum, ans, mp);
        dfs(root->right, totalsum, ans, mp);
    }

    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, long long> mp;
        long long ans = 0;

        long long totalsum = f(root, mp);
        dfs(root, totalsum, ans, mp);

        return ans % MOD;
    }
};
