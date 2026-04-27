// Last updated: 27/04/2026, 21:45:40
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for (int i = 0; i < connections.size(); i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<vector<int>> realadj(n);
        for (int i = 0; i < connections.size(); i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            realadj[a].push_back(b);
        }

        int ans = 0;
        dfs(adj, realadj, 0, visited, ans);
        return ans;
    }
    void dfs(vector<vector<int>>& adj, vector<vector<int>>& realadj, int node,
             vector<int>& visited, int& ans) {
        visited[node] = 1;
        
        for (int nbr : adj[node]) // node->nei
        {
            

            if (!visited[nbr]) {
                bool backward_edge = false;
            vector<int> temp = realadj[nbr];
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == node) {
                    backward_edge = true;
                }
            }
            if (backward_edge==false) {
                ans++;
            }
                dfs(adj,realadj, nbr, visited, ans);
            }
        }
    }
};