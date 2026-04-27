// Last updated: 27/04/2026, 21:47:44
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        priority_queue<pair<int, char>> maxh;
        for (auto it : mp) {
            maxh.push({it.second, it.first});
        }
        int ans = 0;

        while (!maxh.empty()) {

            stack<pair<int, char>> st;

            int i = 0;
            while (!maxh.empty() && i <= n) {
                pair<int, char> p = maxh.top();
                maxh.pop();
                p.first--;
                st.push(p);
                i++;
                ans++;
            }

           

            while(!st.empty())
            {
                pair<int,char>p=st.top();
                st.pop();
                if(p.first>0)
                {
                    maxh.push(p);
                }

            }

            if(maxh.empty())
            {
                break;
            }
             while (i <= n) {
                ans++;
                i++;
            }
            
        }
        return ans;
    }
    };