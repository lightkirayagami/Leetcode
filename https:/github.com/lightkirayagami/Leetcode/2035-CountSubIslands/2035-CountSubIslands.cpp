// Last updated: 27/04/2026, 21:45:16
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {

        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1&&visited[i][j]==0) {
                    ans=ans+bfs(grid1, grid2, i, j, m, n, visited);
                }
            }
        }

        return ans;
    }

    int bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
            int j, int m, int n,vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] =2;
        int flag = true;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            if (grid1[x][y] != 1) {
                flag = false;
            }
            for (int k = 0; k < 4; k++) {
                int x1 = x + dx[k];
                int y1 = y + dy[k];
                if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n &&
                    visited[x1][y1] == 0 && grid2[x1][y1] == 1) {
                    visited[x1][y1] = 2;
                    q.push({x1, y1});
                }
            }
        }
        if (flag == false) {
            return 0;
        }
        return 1;
    }
};