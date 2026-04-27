// Last updated: 27/04/2026, 21:47:23
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        vector<int>nge(n,-1);
        stack<int>st;
        

        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[i]>arr[st.top()])
            {
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++)
        {
            if(nge[i]==-1)
            {
                nge[i]=0;
                continue;
            }

            nge[i]=nge[i]-i;
        }
        return nge;
        
    }
};