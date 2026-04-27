// Last updated: 27/04/2026, 21:45:56
class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char,int>>st;

        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push({s[i],{1}});
            }
            else if(st.top().first!=s[i])
            {
                st.push({s[i],{1}});
            }
            else if(st.top().first==s[i])
            {
                if(st.top().second<k-1)
                {
                    st.top().second++;
                }
                else if(!st.empty()&&st.top().second==k-1)
                {
                    st.pop();
                    continue;
                }
            }
        }

        string ans="";
        while(!st.empty())
        {
            pair<char,int>p=st.top();
            st.pop();
            for(int i=0;i<p.second;i++)
            {
                ans.push_back(p.first);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};