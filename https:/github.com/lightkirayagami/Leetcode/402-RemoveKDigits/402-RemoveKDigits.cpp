// Last updated: 27/04/2026, 21:48:36
class Solution {
public:
    string removeKdigits(string nums, int k) {

        stack<char> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.empty() || nums[i] >= st.top()) {
                st.push(nums[i]);
            } else {
                while (!st.empty() && k > 0 && nums[i] < st.top()) {
                    st.pop();
                    k--;
                }
                st.push(nums[i]);
            }
        }

        while (!st.empty()&&k> 0) {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());


        
        bool can=true;

        string ans2="";

        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='0'&&can==true)
            {
                continue;
            }
            else
            {
                ans2.push_back(ans[i]);
                can=false;
            }

        }
        if(ans2=="")
        {
            return "0";
        }


        return ans2;
    }
};