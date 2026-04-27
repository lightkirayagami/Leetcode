// Last updated: 27/04/2026, 21:47:20
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>> adj(n + 1);
        for(int i=0;i<times.size();i++)
        {
            vector<int>temp=times[i];

            int src=temp[0];
            int dest=temp[1];
            int dist=temp[2];

            
            adj[src].push_back({dest, dist});
        }

        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int dis_from_src=p.first;
            int node=p.second;

            for(auto &nbr:adj[node])
            {
                int nbr_val=nbr.first;
                int weight=nbr.second;

                int old_distance=distance[nbr_val];
                int new_distance=dis_from_src+weight;
                if(new_distance<old_distance)
                {
                    pq.push({new_distance,nbr_val});
                    distance[nbr_val]=new_distance;
                }
            }
        }

         int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(distance[i] == INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }

        return ans;
        
    }
};