// Last updated: 27/04/2026, 21:46:53
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, float>> v;

        int n = position.size();
        for (int i = 0; i < n; i++) {
            float time =
                ((float)(target) - (float)(position[i])) / (float)speed[i];
            v.push_back({position[i], time});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            cout << v[i].first << " " << v[i].second << endl;
        }
        // stack<float> st;

        //    for(int i=n-1;i>=0;i--)
        //    {
        //     if(st.empty())
        //     {

        //         st.push(v[i].second);
        //     }
        //     else if(st.top()<v[i].second)
        //     {
        //         st.push(v[i].second);
        //     }

        //    }

        int ans=0;
        float maxtime=-1;

        for(int i=n-1;i>=0;i--)
        {
            if(v[i].second>maxtime)
            {
                maxtime=v[i].second;
                ans++;
            }
        }


        return ans;
    }
};