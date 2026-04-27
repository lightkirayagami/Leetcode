// Last updated: 27/04/2026, 21:50:20
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)
        {
            vector<string>ans;
            return ans;
        }
        set<string>st;
        int i=0;
        int j=0;
        int k=10;
        vector<string>arr;
        while(j<s.size())
        {
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                string s1=s.substr(i,k);
                if(st.find(s1)!=st.end())
                {
                    arr.push_back(s1);
                }
                st.insert(s1);
                i++;
                j++;
            }
        }
        
    set<string> sttr(arr.begin(), arr.end());
    vector<string>temp;
    int index = 0;
    for (auto& value : sttr) {
        temp.push_back(value);
    }

      return temp;
        
    }
        
    
};