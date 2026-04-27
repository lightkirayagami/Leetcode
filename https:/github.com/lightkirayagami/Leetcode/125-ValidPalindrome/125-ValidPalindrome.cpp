// Last updated: 27/04/2026, 21:51:00
class Solution {
public:
    bool isPalindrome(string s) {

        string s1="";

        for(int i=0;i<s.size();i++)
        {

            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
            s1.push_back(char(tolower(s[i])));
            else if(s[i]>='0'&&s[i]<='9')
            {
                s1.push_back(s[i]);
            }
        }

        string s2=s1;

        reverse(s1.begin(),s1.end());


        if(s1==s2)
        {
            return true;
        }
        return false;


        
    }
};