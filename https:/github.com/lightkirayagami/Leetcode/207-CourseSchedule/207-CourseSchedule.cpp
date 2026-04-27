// Last updated: 27/04/2026, 21:49:59
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<int>ind(numCourses,0);
        vector<int>ans;
        

        for(auto &x: prerequisites)
        {
            int u=x[0];
            int v=x[1];
            adj[v].push_back(u);
            ind[u]++;
        }

        queue<int>q;

        for(int i=0;i<ind.size();i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x);

            for(auto &nbr : adj[x])
            {
                ind[nbr]--;
                if(ind[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }


        if(ans.size()==numCourses)
        {
            return true;
        }
        return false;
    }
};