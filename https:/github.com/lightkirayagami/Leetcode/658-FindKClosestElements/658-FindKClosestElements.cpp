// Last updated: 27/04/2026, 21:47:40
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int,int>>maxH;
        for(int i=0;i<arr.size();i++)
        {
            maxH.push({abs(x-arr[i]),arr[i]});
        }
        k=arr.size()-k;
        while(k!=0)
        {
            maxH.pop();
            k--;
        }
        vector<int>ans;
        while(!maxH.empty())
        {
            pair<int,int>p=maxH.top();
            ans.push_back(p.second);
            maxH.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};