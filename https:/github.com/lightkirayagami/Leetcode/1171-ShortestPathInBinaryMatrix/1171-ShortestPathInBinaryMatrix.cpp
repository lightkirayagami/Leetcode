// Last updated: 27/04/2026, 21:46:09
class Solution {
public:
    int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
    int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
        int m = grid.size();
        int n = grid[0].size();
          if (grid[0][0] == 1 || grid[m-1][n-1] == 1) 
    return -1;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> p=q.front();

                int x = p.first;
                int y = p.second;
                q.pop();
                if(x == m-1 && y == n-1) return ans;
                for (int k = 0; k < 8; k++) {
                    int x1 = x + dx[k];
                    int y1 = y + dy[k];
                    if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n &&
                        grid[x1][y1] == 0 && visited[x1][y1] == 0) {
                        visited[x1][y1] = 2;
                        q.push({x1, y1});
                    }
                }
            }
            ans++;
        }

    return -1;
    }
};