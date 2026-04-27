// Last updated: 27/04/2026, 21:46:39
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        sort(nums, start, end);
        return nums;
    }
    void sort(vector<int>& nums, int start, int end) {

        if (start < end) {
            int middle = start + (end - start) / 2;
            sort(nums, start, middle);
            sort(nums, middle + 1, end);
            merge(nums, start, middle, end);
        }
    }

    void merge(vector<int>& nums, int start, int middle, int end) {
        int n1 = middle - start + 1;
        int n2 = end - middle;

        int arr1[n1] ;
        int arr2[n2] ;
        for (int i = 0; i < n1; i++) {
            arr1[i] = nums[start + i];
        }
        for (int i = 0; i < n2; i++) {
            arr2[i] = nums[middle + i + 1];
        }
        int i = 0;
        int j = 0;
        int k = start;
        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                nums[k] = arr1[i];
                i++;
                k++;
            } else {
                nums[k] = arr2[j];
                j++;
                k++;
            }
        }
            while (i < n1) {
                nums[k] = arr1[i];
                i++;
                k++;
            }
            while (j < n2) {
                nums[k] = arr2[j];
                j++;
                k++;
            }
        
    }
};