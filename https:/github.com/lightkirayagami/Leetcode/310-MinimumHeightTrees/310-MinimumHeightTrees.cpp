// Last updated: 27/04/2026, 21:49:04
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        vector<int>ans;
        if(n==1)
        {
            ans.push_back(0);
            return ans;
        }


       for(int i=0;i<edges.size();i++)
       {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[v]++;
            indegree[u]++;
       }
       queue<int>q;
       for(int i=0;i<n;i++)
       {
        if(indegree[i]==1)
        {
            q.push(i);
        }
       }

       while(n>2)
       {
            int size=q.size();
            n=n-size;
            while(size--)
            {
                int front=q.front();
                q.pop();
                for(int nbr: adj[front])
                {
                    indegree[nbr]--;
                    if(indegree[nbr]==1)
                    {
                        q.push(nbr);
                    }
                }
            }
       }
       

       while(!q.empty())
       {
        ans.push_back(q.front());
        q.pop();
       }
       return ans;

        
        
    }
};