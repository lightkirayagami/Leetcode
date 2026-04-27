// Last updated: 27/04/2026, 21:47:49
class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        if(n==0)
        {
            return true;
        }
        if(n==1&&arr[0]==1&&arr.size()==1)
        {
            return false; 
        }
        if(n==1&&arr[0]==0&&arr.size()==1)
        {
            return true;
        }

        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if(i==0)
            {
                if(arr[0]==0&&arr[1]==0)
                {
                    count++;
                    arr[0]=1;
                }
                
            }
            else if(i==arr.size()-1)
            {
                if(arr[arr.size()-1]==0&&arr[arr.size()-2]==0)
                {
                    count++;
                }
            }
            else
            {
                if(arr[i]==0&&arr[i-1]==0&&arr[i+1]==0)
                {
                    count++;
                    arr[i]=1;
                }
            }
        }
        if(count>=n)
        {
            return true;
        }
        return false;
        
    }
};