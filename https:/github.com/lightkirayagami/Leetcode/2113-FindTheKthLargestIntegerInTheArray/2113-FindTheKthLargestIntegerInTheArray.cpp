// Last updated: 27/04/2026, 21:45:04
class Solution {
public:
    struct cmp{
        bool operator()(const string&a,const string&b)
        const{
            if(a.size()!=b.size())
            {
                return a.size()<b.size();
            }
            return a<b;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {

        priority_queue<string,vector<string>,cmp>maxH;
        for(int i=0;i<nums.size();i++)
        {
            maxH.push(nums[i]);
        }

        while(k>1)
        {
            maxH.pop();
            k--;
        }
        return maxH.top();
        
    }
};