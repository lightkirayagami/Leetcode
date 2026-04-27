// Last updated: 27/04/2026, 21:51:45
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n,-1);
        vector<int>nse(n,-1);
        

        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
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
            while(!st.empty()&&heights[st.top()]>=heights[i])
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
        int maxArea=0;
        for(int i=0;i<heights.size();i++)
        {
            int width=nse[i]-pse[i]-1;
            maxArea=max(maxArea,width*heights[i]);
        }
        return maxArea;
        
    }
};