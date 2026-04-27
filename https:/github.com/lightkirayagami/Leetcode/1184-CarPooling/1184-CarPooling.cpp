// Last updated: 27/04/2026, 21:46:07
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minh;

        int i = 0;

        int n = trips.size();
        int cap=0;

        while (i < n) {
            int start = trips[i][1];

                while (!minh.empty() && minh.top().first <= start) {
                cap = cap - minh.top().second;
                minh.pop();
            }

            minh.push({trips[i][2], trips[i][0]});
            cap = cap + trips[i][0];
            i++;

            if (cap > capacity) {
                return false;
            }
        }
        return true;
    }
};