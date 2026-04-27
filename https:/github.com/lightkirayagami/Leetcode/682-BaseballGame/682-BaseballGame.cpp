// Last updated: 27/04/2026, 21:47:35
class Solution {
public:
    int calPoints(vector<string>& op) {

        stack<int>st;
        for(int i=0;i<op.size();i++)
        {
            if(op[i]=="C")
            {
                st.pop();
            }
            else if(op[i]=="D")
            {
                int a=st.top();
                a=a+a;
                st.push(a);
            }
            else if(op[i]=="+")
            {
                int a1=st.top();
                st.pop();
                int a2=st.top();
                st.pop();
                int a3=a1+a2;
                st.push(a2);
                st.push(a1);
                st.push(a3);

            }
            else
            {
                int a=stoi(op[i]);
                st.push(a);
            }
        }

        int sum=0;
        while(!st.empty())
        {
            sum=sum+st.top();
            st.pop();
        }
        return sum;
    }
};