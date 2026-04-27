// Last updated: 27/04/2026, 21:50:54
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 'O') {
                bfs(grid, 0, j, m, n);
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[m - 1][j] == 'O') {
                bfs(grid, m-1, j, m, n);
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 'O') {
                bfs(grid, i, 0, m, n);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][n - 1] == 'O') {
                bfs(grid, i, n-1, m, n);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='O')
                {
                    grid[i][j]='X';
                }
                else if(grid[i][j]=='2')
                {
                    grid[i][j]='O';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '2';
        while (!q.empty()) {
            pair<int, int> f = q.front();
            int x = f.first;
            int y = f.second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x1 = x + dx[k];
                int y1 = y + dy[k];
                if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n &&
                    grid[x1][y1] == 'O') {
                    grid[x1][y1] = '2';
                    q.push({x1, y1});
                }
            }
        }
    }
};