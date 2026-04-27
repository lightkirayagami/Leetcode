// Last updated: 27/04/2026, 21:50:08
class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        int count=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,m,n,grid);
                }
            }
        }
        return count;
        
    }

    void bfs(int x,int y,int m,int n,vector<vector<char>>&grid)
    {

        queue<pair<int,int>>q;
        q.push({x,y});
        grid[x][y]='2';
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();

            for(int k=0;k<4;k++)
            {
                int xdx=p.first+dx[k];
                int ydy=p.second+dy[k];

                if(xdx>=0&&xdx<m&&ydy>=0&&ydy<n&&grid[xdx][ydy]=='1')
                {
                    q.push({xdx,ydy});
                    grid[xdx][ydy]='2';
                }
            }
        }
    }
};