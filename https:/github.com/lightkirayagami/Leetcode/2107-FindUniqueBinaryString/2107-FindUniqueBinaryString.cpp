// Last updated: 27/04/2026, 21:45:07
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        string ans="";
        for(int i=0;i<nums.size();i++)
        {
            char c=nums[i][i];
            if(c=='0')
            {
                ans=ans+"1";
            }
            else
            {
                ans=ans+"0";
            }
        }
        return ans;
        
    }
};