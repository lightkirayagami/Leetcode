// Last updated: 27/04/2026, 21:47:33
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    void Union(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);
        if (x_p == y_p) {
            return;
        }
        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        } else if (rank[x_p] < rank[y_p]) {
            parent[x_p] = y_p;
        } else {
            parent[x_p] = y_p;
            rank[y_p] += 1;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;

        parent.resize(edges.size()+1);
        rank.resize(edges.size()+1, 0);
        for (int i = 0; i < edges.size(); i++) {
            parent[i] = i;
        }

        for (auto& v : edges) {
            int x = v[0];
            int y = v[1];

            if (find(x) != find(y)) {
                Union(x, y);
            } else {
                ans.push_back(x);
                ans.push_back(y);
            }
        }
        return ans;
    }
};