// Last updated: 27/04/2026, 21:46:04
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>nums;
        nums.push_back(-1);
        int right=-1;
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]>right)
            {
                right=arr[i];
                nums.push_back(arr[i]);
            }
            else{
                nums.push_back(right);
            }
        }
        reverse(nums.begin(),nums.end());
        return nums;
        
    }
};