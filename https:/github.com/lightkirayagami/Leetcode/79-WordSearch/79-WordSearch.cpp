// Last updated: 27/04/2026, 21:51:51
class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int ans =false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    bool ans1=solve(board,word,m,n,i,j,0);
                    ans=ans1||ans;
                }
            }
        }
        return ans;
    }

    bool solve(vector<vector<char>>& board,string word,int m,int n,int i,int j,int k)

    {
          if(k==word.size())
        {
            return true;
        }
       
        if(i<0||j<0||i>=m||j>=n||board[i][j]=='$')
        {
            return false;
        }
       
        if(board[i][j]!=word[k])
        {
            return false;
        }

        char temp=board[i][j];
        board[i][j]='$';
        bool ans=false;

        for(int z=0;z<4;z++)
        {
            int xdx=i+dx[z];
            int ydy=j+dy[z];

            bool ans1=solve(board,word,m,n,xdx,ydy,k+1);
            ans=ans1||ans;
            
        }

        board[i][j]=temp;
        return ans;
    }
};