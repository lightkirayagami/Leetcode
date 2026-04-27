// Last updated: 27/04/2026, 21:52:42
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        suduko(board,0,0,board.size());
        
    }
    
     bool suduko(vector<vector<char>>& board,int currrow,int currcol,int n)
     {
         if(currrow==n)
         {
             return true;
         }
         int nextrow=-1;
         int nextcol=-1;
         if(currcol!=n-1)
         {
           nextrow=currrow;
           nextcol=currcol+1;
         }
         else
         {
             nextrow=currrow+1;
             nextcol=0;
         }
         if(board[currrow][currcol]!='.')
         {
             return suduko(board,nextrow,nextcol,n);
         }
         for(int i=1;i<=9;i++)
         {
             if(isvalid(board,currrow,currcol,i,n))
             {
                 char ch=i;
                 ch=ch+'0';
                 board[currrow][currcol]=ch;
                 // cout<<ch<<endl;
                 
                 if(suduko(board,nextrow,nextcol,n)==true)
                 {
                     return true;
                }
                 board[currrow][currcol]='.';
             }
             
             
         }
         return false;
     }
         
         bool isvalid(vector<vector<char>>& board,int currrow,int currcol,int currval,int n)
         {
             return(isgrid(board,currrow,currcol,currval,n)&&
                    isrow(board,currrow,currcol,currval,n)&&
                    iscol(board,currrow,currcol,currval,n))  ; 
         }
         
         bool isrow(vector<vector<char>>& board,int currrow,int currcol,int currval,int n)
         {
            for(currcol=0;currcol<n;currcol++)
            {
                char ch=currval;
                ch=ch+'0';
                if(board[currrow][currcol]==ch)
                    return false;
            }
             return true;
         }
         bool iscol(vector<vector<char>>& board,int currrow,int currcol,int currval,int n)
         {
            for( currrow=0;currrow<n;currrow++)
            {
                char ch=currval;
                ch=ch+'0';
                if(board[currrow][currcol]==ch)
                    return false;
            }
             return true;
         }
        bool isgrid(vector<vector<char>>& board,int currrow,int currcol,int currval,int n)
         {
            int startrow=3*(currrow/3);
            int startcol=3*(currcol/3);
            for(int i=startrow;i<=startrow+2;i++)
                
            {
                {
                    for(int j=startcol;j<=startcol+2;j++)
                    {
                         char ch=currval;
                        ch=ch+'0';
                        if(board[i][j]==ch)
                        return false;
                    }
                }
               
            }
             return true;
         }
             
     
};