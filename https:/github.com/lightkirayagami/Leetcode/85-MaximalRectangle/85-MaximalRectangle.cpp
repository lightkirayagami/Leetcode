// Last updated: 27/04/2026, 21:51:44
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }

                
            }
            int area = calculateArea(heights);
                maxArea = max(area, maxArea);
        }

        return maxArea;
    }

    int calculateArea(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>pse(n,-1);
        vector<int>nse(n,n);


        stack<int>st;


        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[i]<=nums[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                nse[i]=n;
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
            while(!st.empty()&&nums[i]<=nums[st.top()])
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

        int maxArea=0;

        for(int i=0;i<n;i++)
        {
            int area=nse[i]-pse[i]-1;
            area=area*nums[i];
            maxArea=max(area,maxArea);
        }
        return maxArea;




    }



    // 2,3,5,1,3,2,8
    // 1,1,1,2,2,-1,-1


};