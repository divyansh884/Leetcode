class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        int total = 1 << cnt;

        vector<vector<vector<int>>> dist(
            m,
            vector<vector<int>>(
                n,
                vector<int>(total, -1)
            )
        );

        pq.push({0, cnt, sr, sc, energy, 0});
        dist[sr][sc][0] = energy;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while (!pq.empty()) {
            int moves = pq.top()[0];
            int left = pq.top()[1];
            int r = pq.top()[2];
            int c = pq.top()[3];
            int currEnergy = pq.top()[4];
            int mask = pq.top()[5];

            pq.pop();

            if (left == 0)
                return moves;

            if (dist[r][c][mask] > currEnergy)
                continue;

            if (currEnergy == 0)
                continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n ||
                    classroom[nr][nc] == 'X')
                    continue;

                int nleft = left;
                int nmask = mask;

                if (classroom[nr][nc] == 'L') {
                    int x = id[nr][nc];

                    if (!(mask & (1 << x))) {
                        nmask |= (1 << x);
                        nleft--;
                    }
                }

                int nenergy = currEnergy - 1;

                if (classroom[nr][nc] == 'R')
                    nenergy = energy;

                if (nenergy > dist[nr][nc][nmask]) {
                    dist[nr][nc][nmask] = nenergy;

                    pq.push({
                        moves + 1,
                        nleft,
                        nr,
                        nc,
                        nenergy,
                        nmask
                    });
                }
            }
        }

        return -1;
    }
};