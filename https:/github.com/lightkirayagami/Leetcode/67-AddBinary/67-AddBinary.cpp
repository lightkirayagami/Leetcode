// Last updated: 27/04/2026, 21:52:09
class Solution {
public:
    string addBinary(string a, string b) {

        if (a.size() > b.size()) {
            int x = a.size() - b.size();
            for (int i = 0; i < x; i++) {
                b='0'+b;
            }
        } else {
            int x = b.size() - a.size();
            for (int i = 0; i < x; i++) {
                a='0'+a;
            }
        }

        int carry = 0;
        int n=a.size();
        string c="";

        for (int i =n-1;i>=0;i--)
        {
            if(a[i]=='0'&&b[i]=='0'&&carry==0)
            {
                c.push_back('0');
                carry=0;
            }
           else if(a[i]=='0'&&b[i]=='0'&&carry==1)
            {
                c.push_back('1');
                carry=0;
            }
            else if(a[i]=='0'&&b[i]=='1'&&carry==0)
            {
                c.push_back('1');
                carry=0;
            }
            else if(a[i]=='1'&&b[i]=='0'&&carry==0)
            {
                c.push_back('1');
                carry=0;
            }
            else if(a[i]=='0'&&b[i]=='1'&&carry==1)
            {
                c.push_back('0');
                carry=1;
            }
            else if(a[i]=='1'&&b[i]=='0'&&carry==1)
            {
                c.push_back('0');
                carry=1;
            }
             else if(a[i]=='1'&&b[i]=='1'&&carry==0)
            {
                c.push_back('0');
                carry=1;
            }
             else if(a[i]=='1'&&b[i]=='1'&&carry==1)
            {
                c.push_back('1');
                carry=1;
            }
        }


        if(carry==1)
        {
            c.push_back('1');
        }

        reverse(c.begin(),c.end());
        return c;
    }
};