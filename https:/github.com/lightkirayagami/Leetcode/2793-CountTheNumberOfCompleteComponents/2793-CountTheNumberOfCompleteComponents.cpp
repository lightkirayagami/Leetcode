// Last updated: 27/04/2026, 21:44:46
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        map<int,vector<int>>adj;
        for(auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int m=edges.size();


        vector<int>visited(n,0);

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                int edgecount =0;
                int nodes=0;
                ans++;
                bfs(i,visited,adj,edgecount,nodes);

                if((nodes*(nodes-1))/2!=edgecount/2)
                {
                    ans--;
                }
            }
        }
        return ans;
        
    }

    void bfs(int node,vector<int>&visited,map<int,vector<int>>&adj,int &edgecount,int &nodecount)
    {
        queue<int>q;
        q.push(node);
        visited[node]=1;

        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            nodecount++;
            edgecount=edgecount+adj[f].size();
            for(auto &nbr:adj[f])
            {
                if (visited[nbr]==0) {
                visited[nbr] = 1;
                q.push(nbr);
            }
            }
        }
    }
};