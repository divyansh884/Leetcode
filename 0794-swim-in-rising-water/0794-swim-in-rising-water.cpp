class Solution {
public:
 void bfs(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dis,
             int& rown,int& coln) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, i, j});
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!pq.empty()) {
            int row = pq.top()[1];
            int col = pq.top()[2];
            int dist = pq.top()[0];
            pq.pop();
           for (int dir = 0; dir < 4; dir++) {
                int newX = row + dx[dir];
                int newY = col + dy[dir];
                if (newX >= 0 && newY >= 0 && newX < rown && newY < coln) {
                    int eff=max(grid[row][col],grid[newX][newY]);
                    int maxeff=  max(eff,dist);
                    if(maxeff<dis[newX][newY]){
                        dis[newX][newY]=maxeff;
                        pq.push({maxeff,newX,newY});
                    }
                }
            }
        }
    }
    int swimInWater(vector<vector<int>>& heights) {
         int row=heights.size();
        int col=heights[0].size();
        vector<vector<int>> dis(row,vector<int>(col,1e9));
        dis[0][0]=0;
        bfs(0,0,heights,dis,row,col);
        return dis[row-1][col-1];
    }
};