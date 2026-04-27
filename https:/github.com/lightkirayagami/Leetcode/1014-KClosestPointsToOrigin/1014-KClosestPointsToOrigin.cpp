// Last updated: 27/04/2026, 21:46:28
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,pair<int,int>>>maxH;
        for(int i=0;i<points.size();i++)
        {
            pair<int,int>p;
            p.first=points[i][0];
            p.second=points[i][1];

            int distance=((abs(0-points[i][0]))*(abs(0-points[i][0])))+((abs(0-points[i][1]))*(abs(0-points[i][1])));
            maxH.push({distance,p});

        }
        vector<vector<int>>ans;
        while(maxH.size()!=k)
        {
            maxH.pop();
        }

        while(!maxH.empty())
        {
            pair<int,int>p=maxH.top().second;
            maxH.pop();
            vector<int>ans1;
            ans1.push_back(p.first);
            ans1.push_back(p.second);
            ans.push_back(ans1);



        }
        return ans;



        
    }
};