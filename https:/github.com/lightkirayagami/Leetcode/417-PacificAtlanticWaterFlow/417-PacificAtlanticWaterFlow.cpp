// Last updated: 27/04/2026, 21:48:26
class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m=heights.size();
        int n=heights[0].size();

        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<int>>ans;


        vector<pair<int,int>>parr;
        vector<pair<int,int>>aarr;

        for(int i=0;i<m;i++)
        {
            parr.push_back({i,0});
        }
        for(int j=0;j<n;j++)
        {
            parr.push_back({0,j});
        }

        for(int i=0;i<m;i++)
        {
            aarr.push_back({i,n-1});
        }
        for(int j=0;j<n;j++)
        {
            aarr.push_back({m-1,j});
        }

        bfs(pacific,parr,heights,m,n);
        bfs(atlantic,aarr,heights,m,n);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(atlantic[i][j]==true&&pacific[i][j]==true)
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;


    }

    void bfs(vector<vector<bool>>&visited,vector<pair<int,int>>&coor,vector<vector<int>>&heights,int m,int n)
    {

            queue<pair<int,int>>q;
            for(int i=0;i<coor.size();i++)
            {
                pair<int,int>p=coor[i];
                q.push({p.first,p.second});
                visited[p.first][p.second]=true;
            }

            while(!q.empty())
            {
                pair<int,int>f=q.front();
                q.pop();

                for(int k=0;k<4;k++)
                {
                    int xdx=f.first+dx[k];
                    int ydy=f.second+dy[k];

                    if(xdx>=0&&xdx<m&&ydy>=0&&ydy<n&&visited[xdx][ydy]==false&&heights[xdx][ydy]>=heights[f.first][f.second])
                    {
                        q.push({xdx,ydy});
                        visited[xdx][ydy]=true;
                    }
                }
            }
    }
};