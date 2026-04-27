// Last updated: 27/04/2026, 21:45:41
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));


        

        int x=solve(grid,0,0,n-1,m,n,dp);
        return x;
        
    }

    int solve(vector<vector<int>>&grid,int i,int ja,int jb,int m,int n,vector<vector<vector<int>>>&dp)
    {
        if(i<0||i>=m||ja<0||ja>=n||jb<0||jb>=n)
        {
            return INT_MIN;
        }

        if(i==m-1)
        {
            if(ja==jb)
            {
                return grid[i][ja];
            }
            else
            {
                return grid[i][ja]+ grid[i][jb];
            }
        }
        if(dp[i][ja][jb]!=-1)
        {
            return dp[i][ja][jb];
        }

        int cherries = grid[i][ja];
        if (ja != jb)
            cherries += grid[i][jb];

        int bestNext = INT_MIN;

        for(int x=-1;x<=1;x++)
        {
            for(int y=-1;y<=1;y++)
            {
                int new_i=i+1;
                int new_ja=ja+x;
                int new_jb=jb+y;

               int next = solve(grid, new_i, new_ja, new_jb, m, n,dp);
                bestNext = max(bestNext, next);
            }
        }
        dp[i][ja][jb]= bestNext+cherries;

        return bestNext+cherries;
    }



};