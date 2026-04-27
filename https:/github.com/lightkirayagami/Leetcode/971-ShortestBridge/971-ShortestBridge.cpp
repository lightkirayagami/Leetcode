// Last updated: 27/04/2026, 21:46:35
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int shortestBridge(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        bool done = false;
        for (int i = 0; i < m; i++) {
            if (done == true) {
                break;
            }
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    markingbfs(grid, i, j, m, n, visited);
                    done = true;
                    break;
                }
            }
        }
        vector<vector<int>> visited1(m, vector<int>(n, 0));

        int ans = getlevel(grid, m, n, visited1);
        return ans ;
    }

    void markingbfs(vector<vector<int>>& grid, int i, int j, int m, int n,
                    vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 2;
        grid[i][j] = 2;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for (int k = 0; k < 4; k++) {
                int x1 = x + dx[k];
                int y1 = y + dy[k];
                if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n &&
                    visited[x1][y1] == 0 && grid[x1][y1] == 1) {
                    visited[x1][y1] = 2;
                    grid[x1][y1] = 2;
                    q.push({x1, y1});
                }
            }
        }
    }

    int getlevel(vector<vector<int>>& grid, int m, int n,
                 vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 2;
                }
            }
        }
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto p = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int x1 = p.first + dx[k];
                    int y1 = p.second + dy[k];

                    if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n &&
                        visited[x1][y1] == 0) {
                        if (grid[x1][y1] == 1) {
                            return ans;
                        } else if (grid[x1][y1] == 0) {
                            q.push({x1, y1});
                            visited[x1][y1] = 2;
                        }
                    }
                }
            }
            ans++;
        }
        return ans;
        ;
    }
};