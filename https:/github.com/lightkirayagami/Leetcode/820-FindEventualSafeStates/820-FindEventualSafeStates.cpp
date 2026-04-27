// Last updated: 27/04/2026, 21:46:58
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        vector<int> outdegree(n, 0);
        vector<vector<int>> rev(n);
        for (int u = 0; u < n; u++) {
            outdegree[u] = adj[u].size();
            for (auto v : adj[u]) {
                rev[v].push_back(u);
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int nbr : rev[f]) {
                outdegree[nbr]--;
                if (outdegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};