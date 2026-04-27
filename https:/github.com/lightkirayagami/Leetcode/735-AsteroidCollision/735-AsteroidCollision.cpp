// Last updated: 27/04/2026, 21:47:24
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {

        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < as.size(); i++) {
            bool can = true;
            if (st.empty()) {
                st.push(as[i]);
                continue;
            }

            while(can==true&&!st.empty()&&as[i]<0&&st.top()>0)
            {
                if(abs(as[i])==abs(st.top()))
                {
                    st.pop();
                    can=false;
                }
                else if(abs(as[i])<abs(st.top()))
                {
                    can=false;
                }
                else
                {
                    st.pop();
                    continue;
                }
            }

            if(can==true)
            {
                st.push(as[i]);
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};