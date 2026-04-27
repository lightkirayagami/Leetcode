// Last updated: 27/04/2026, 21:50:33
class Solution {
public:
    int evalRPN(vector<string>& token) {

        stack<int>st;
        for(int i=0;i<token.size();i++)
        {
            if(token[i]=="+")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b+a;
                st.push(c);
            }
            else if(token[i]=="-")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b-a;
                st.push(c);
            }
            else if(token[i]=="/")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b/a;
                st.push(c);
            }
            else if(token[i]=="*")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a*b;
                st.push(c);
            }
            else
            {
                st.push(stoi(token[i]));
            }
        }
        return st.top();







    }
};