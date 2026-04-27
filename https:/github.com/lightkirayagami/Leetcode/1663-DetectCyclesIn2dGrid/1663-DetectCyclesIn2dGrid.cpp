// Last updated: 27/04/2026, 21:45:37
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
         int n = grid.size();

    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            if(!vis[i][j]) {

                if(dfs(i, j, -1, -1, grid, vis)) return true;

            }

        }

    }

    return false;
        
    }

    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<int>>& vis) {

    vis[i][j] = 1;

    int n = grid.size();

    int m = grid[0].size();

    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    for(int d = 0; d < 4; d++) {

        int ni = i + dirs[d][0];

        int nj = j + dirs[d][1];

        if(ni >= 0 && nj >= 0 && ni < n && nj < m) {

            if(grid[ni][nj] != grid[i][j]) continue;

            if(!vis[ni][nj]) {

                if(dfs(ni, nj, i, j, grid, vis)) return true;

            }

            else {

                // visited and not parent → cycle

                if(ni != pi || nj != pj) return true;

            }

        }

    }

    return false;

}
};