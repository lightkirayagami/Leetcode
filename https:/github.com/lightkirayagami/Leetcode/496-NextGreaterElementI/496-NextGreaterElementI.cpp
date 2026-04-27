// Last updated: 27/04/2026, 21:48:07
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans=ngm(nums2);
        vector<int>ans1;
        map<int ,int>m;
        for(int i=0;i<nums2.size();i++)
        {
            m.insert({nums2[i],ans[i]});
        }
        for(auto it:nums1)
        {
            ans1.push_back(m[it]);    
        }
        return ans1;
    }

    vector<int>ngm(vector<int>& arr)
    {
        vector<int>ans;
        stack<int> s;
     for(int i=arr.size()-1;i>=0;i--)
     {
        int ele=arr[i];
         if(s.empty())
        {
            ans.push_back(-1);
            s.push(ele);
            continue;
        }
        while(!s.empty() && ele>=s.top())
        {
            s.pop();
          
           
        }
        if(s.empty())
        {
            s.push(ele);
            ans.push_back(-1);
            continue;
        }
        if(ele<s.top())
        {
            ans.push_back(s.top());
            s.push(ele);
            continue;
        }
    }
     
     reverse(ans.begin(),ans.end());
     return ans;
       
    }
};