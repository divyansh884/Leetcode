class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        if(prerequisites.size()==0)
        return true;
        for (int i = 0; i <prerequisites.size() ; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0)
                q.push(it);
            }
        }
        return ans.size()==n;
    }
};