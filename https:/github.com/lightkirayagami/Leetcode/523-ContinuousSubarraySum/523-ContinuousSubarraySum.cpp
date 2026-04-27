// Last updated: 27/04/2026, 21:48:02
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       map<int,int>m;
       m.insert({0,-1});
       int sum=0;
       for(int i=0;i<nums.size();i++)
       {
        sum=sum+nums[i];
        int r=sum%k;
        if(m.find(r)==m.end())
        {
            m[r]=i;
        }
        else if(i-m[r]>1)
        {
            return true;
        }
       }
       return false;
}};