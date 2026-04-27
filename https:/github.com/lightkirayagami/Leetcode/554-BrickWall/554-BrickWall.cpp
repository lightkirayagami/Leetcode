// Last updated: 27/04/2026, 21:47:55
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        int wall_len = 0;
        map<int,int>m;
        for (int i = 0; i < wall[0].size(); i++) {
            wall_len = wall_len + wall[0][i];
        }
        for (int i = 0; i < wall.size(); i++) {
            int pref = 0;
            for (int j = 0; j < wall[i].size(); j++) {
                wall[i][j] = pref + wall[i][j];
                pref = wall[i][j];
                if(wall[i][j]!=wall_len)
                {
                    m[wall[i][j]]++;
                }
            }
        }

        int max1=0;
        for(auto it:m)
        {
            if(it.second>max1)
            {
                max1=max(max1,it.second);
            }
        }
        return wall.size()- max1;
    }
};