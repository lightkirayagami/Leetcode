// Last updated: 27/04/2026, 21:46:22
class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
    int uniquePathsIII(vector<vector<int>>& grid) {

        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        int valid=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0||grid[i][j]==1)
                {
                    valid++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                solve(i,j,grid,ans,0,m,n,valid);
            }
        }

        
        return ans;
        
    }

    void solve(int i,int j,vector<vector<int>>& grid,int &ans,int count,int m,int n,int valid)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==-1)
        {
            return;
        }
        if(grid[i][j]==2)
        {
            if(count==valid)
            {
                ans++;
            }
            return;
        }

        int temp=grid[i][j];
        grid[i][j]=-1;

        for(int z=0;z<4;z++)
        {
            int xdx=i+dx[z];
            int ydy=j+dy[z];

            solve(xdx,ydy,grid,ans,count+1,m,n,valid);
        }



        grid[i][j]=temp;


    }
};