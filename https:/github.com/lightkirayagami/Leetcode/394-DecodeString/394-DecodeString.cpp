// Last updated: 27/04/2026, 21:48:37
class Solution {
public:
    string decodeString(string s) {

        stack<string> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != ']') {
                st.push(string(1, s[i]));
                continue;
            } else {
                string s1 = "";
                while (st.top() != "[") {
                    s1 = st.top() + s1;
                    st.pop();
                }
                st.pop(); // removes [
                string num = "";

                while (!st.empty()&&st.top()[0] >= '0' && st.top()[0] <= '9') {
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());

                int x = stoi(num);
                string s2 = "";

                for (int c = 0; c < x; c++) {
                    s2 = s2 + s1;
                }

                st.push(s2);
            }
        }

        string ans="";

        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};