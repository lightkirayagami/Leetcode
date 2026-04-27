// Last updated: 27/04/2026, 21:44:42
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        int sum=0;
        for(int i=0;i<capacity.size();i++)
        {
            sum=sum+capacity[i];
            capacity[i]=sum;
        }

        int total_apples=0;
        for(int i=0;i<apple.size();i++)
        {
            total_apples+=apple[i];
        }

        int ans=0;

        for(int i=0;i<capacity.size();i++)
        {
            if(capacity[i]<total_apples)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        return ans+1;
        
    }
};