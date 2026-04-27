// Last updated: 27/04/2026, 21:48:39
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        int i=0;
        int j=0;

        while(i<m && j<n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        cout<<i<<" "<<j<<" "<<" "<<m<<" "<<n<<endl;
        if(i==m)
        {
            return 1;
        }
       return 0;
    }
};