class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent); // step 1

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            if (dist++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
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
