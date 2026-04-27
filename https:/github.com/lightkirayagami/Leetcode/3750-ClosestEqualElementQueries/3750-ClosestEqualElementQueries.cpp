// Last updated: 27/04/2026, 21:44:38
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        map<int, vector<int>> mp;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int>& temp = mp[nums[queries[i]]];
            if (temp.size() == 1) {
                ans.push_back(-1);
            } else {
                int idx = bs(temp, queries[i]);
                int curr = temp[idx];
                int size = temp.size();

                int next = temp[(idx + 1) % size];
                int prev = temp[(idx - 1 + size) % size];

                int distNext = (next - curr + n) % n;
                int distPrev = (curr - prev + n) % n;

                ans.push_back(min(distNext, distPrev));
            }
        }
        return ans;
    }

    int bs(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                return mid;

            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};