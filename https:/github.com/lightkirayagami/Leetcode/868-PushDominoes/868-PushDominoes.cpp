// Last updated: 27/04/2026, 21:46:56
class Solution {
public:
    string pushDominoes(string dominoes) {
 int n = dominoes.size();
        vector<int> left(n,INT_MAX);
        int count = 0;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='L')
            {
                flag = false;
            }    
            else if(dominoes[i]=='R')
            {
                count=0;
                flag = true;
            }
            else
            {
                if(flag)
                {
                    count++;
                    left[i]=count;
                }
            }
        }
        vector<int> right(n,INT_MAX);
        flag = false;
        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='R')
            {
                flag = false;
            }    
            else if(dominoes[i]=='L')
            {
                count=0;
                flag = true;
            }
            else
            {
                if(flag)
                {
                    count++;
                    right[i]=count;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='.')
            {
                if(left[i]<right[i])
                    dominoes[i]='R';
                else if(left[i]>right[i])
                    dominoes[i]='L';
            }
        }
        return dominoes;
        
    }
};