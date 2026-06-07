class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, vector<int>> mp;
        map<int, int> nodes;

        for (auto &d : des) {
            mp[d[0]].push_back(d[1]);
            mp[d[0]].push_back(d[2]);
            nodes[d[1]]++;
        }

        unordered_map<int, TreeNode*> tree;

        TreeNode* ans = nullptr;
        queue<TreeNode*> q;

        for (auto it : mp) {
            if (nodes.find(it.first) == nodes.end()) {
                ans = new TreeNode(it.first);
                tree[it.first] = ans;
                q.push(ans);
                break;
            }
        }

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            for (int i = 0; i < mp[node->val].size(); i += 2) {
                int num = mp[node->val][i];
                int isleft = mp[node->val][i + 1];

                if (!tree.count(num))
                    tree[num] = new TreeNode(num);

                if (isleft)
                    node->left = tree[num];
                else
                    node->right = tree[num];

                q.push(tree[num]);
            }
        }

        return ans;
    }
};