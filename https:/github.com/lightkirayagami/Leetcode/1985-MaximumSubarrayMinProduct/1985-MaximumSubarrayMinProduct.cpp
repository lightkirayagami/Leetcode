// Last updated: 27/04/2026, 21:45:24
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();

        vector<int>nse(n,-1);
        vector<int>pse(n,-1);
        vector<long long>prefsum(n+1, 0);
        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                nse[i]=-1;
                st.push(i);
            }
            else 
            {
                nse[i]=st.top();
                st.push(i);
            }

        }
        while(!st.empty())
        {
            st.pop();
        }



        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                pse[i]=-1;
                st.push(i);
            }
            else
            {
                pse[i]=st.top();
                st.push(i);
            }
        }


        for(int i=0;i<n;i++)
        {
            if(nse[i]==-1)
            {
                nse[i]=n;
            }
           
        }

       for(int i=0; i<n; i++)
    prefsum[i+1] = prefsum[i] + nums[i];
    


        long long ans=0;

        for(int i=0;i<n;i++)
        {
             int left=pse[i];
             int right=nse[i];
             long long sum = prefsum[right] - prefsum[left+1];
             ans=max(ans,sum*nums[i]);
        }
        return ans% 1000000007;


        

        
    }
};