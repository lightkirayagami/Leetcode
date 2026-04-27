// Last updated: 27/04/2026, 21:49:54
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<int>ans;
        vector<int>ind(numCourses,0);


        for(auto &x : prerequisites)
        {
            int a=x[0];
            int b=x[1];
            adj[b].push_back(a);
            ind[a]++;
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
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(int nbr: adj[f])
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
            return ans;
        }
        vector<int>ans1;
        return ans1;
        
    }
};