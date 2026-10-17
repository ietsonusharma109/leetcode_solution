class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                // minimum right half mein hai
                low = mid + 1;
            } else {
                // minimum mid ya left half mein hai
                high = mid;
            }
        }
        return nums[low]; 
    }
};