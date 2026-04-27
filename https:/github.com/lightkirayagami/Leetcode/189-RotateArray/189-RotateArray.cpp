// Last updated: 27/04/2026, 21:50:16
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    
    int n=nums.size();
    k=k%n;
    reverse(nums.begin(),nums.end()-k);
    reverse(nums.begin()+n-k,nums.end());
    reverse(nums.begin(),nums.end());
    
    
    
    



        
    }
};