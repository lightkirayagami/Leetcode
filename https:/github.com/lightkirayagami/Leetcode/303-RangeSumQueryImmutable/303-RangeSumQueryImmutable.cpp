// Last updated: 27/04/2026, 21:49:07
class NumArray {
    

public:
vector<int> num;
    NumArray(vector<int>& nums) { 
        for(int i=0;i<nums.size();i++)
        {
            num.push_back(nums[i]);
        }
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum = sum + num[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */