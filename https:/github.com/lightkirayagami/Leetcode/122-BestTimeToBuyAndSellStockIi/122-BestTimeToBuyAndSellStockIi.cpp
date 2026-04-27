// Last updated: 27/04/2026, 21:51:05
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<int>v;
        // NGE(prices,v,n);
        // reverse(v.begin(),v.end());
        int maxP=0;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1 && prices[i]<prices[i+1])
            {
                maxP=maxP+prices[i+1]-prices[i];
                
        }
        }
        return maxP;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // return 10;
        
    }
    void NGE(vector<int>& prices,vector<int>& v,int n)
    {
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                v.push_back(-1);
                s.push(prices[i]);
                continue;
            }
            while(!s.empty()&&s.top()<prices[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                v.push_back(-1);
                s.push(prices[i]);
                continue;
            }
            if(s.top()>prices[i])
            {
                v.push_back(s.top());
                s.push(prices[i]);
            }
        }
    }



    
};