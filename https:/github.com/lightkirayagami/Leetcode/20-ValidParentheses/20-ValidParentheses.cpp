// Last updated: 27/04/2026, 21:53:00
class Solution {
public:
    bool isValid(string s) {

        stack<int> st;
        for (int i = 0; i < s.size(); i++) {

            if(st.empty())
            {
                st.push(s[i]);
            }

            else if (((s[i] == ')' && st.top() == '(') ||
                      (s[i] == '}' && st.top() == '{') ||
                      (s[i] == ']' && st.top() == '[')) ) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        if (st.empty() == true) {
            return true;
        }
        return false;
    }
};