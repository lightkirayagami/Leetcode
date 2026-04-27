// Last updated: 27/04/2026, 21:47:06
class Solution {
public:
    string reorganizeString(string s) {

        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
    

    priority_queue<pair<int, char>> maxh;

    for (auto it : mp)
        
    {
        pair<int, char> p;
        p.first = it.second;
        p.second = it.first;
        maxh.push(p);
    }

    string ans = "";

    while (!maxh.empty()) {
        if (maxh.size() == 1) {
            int num = maxh.top().first;
            if (num >1) {
                return "";
            }
            else
            {
                ans=ans+maxh.top().second;
                return ans;
            }
        }
        char a = maxh.top().second;
        int anum = maxh.top().first;
        maxh.pop();
        char b = maxh.top().second;
        int bnum = maxh.top().first;
        maxh.pop();
        ans = ans + a + b;
        anum--;
        bnum--;
        if(anum>0)
        {
            maxh.push({anum,a});
        }
        if(bnum>0)
        {
            maxh.push({bnum,b});
        }
    }
    return ans;
    }
};