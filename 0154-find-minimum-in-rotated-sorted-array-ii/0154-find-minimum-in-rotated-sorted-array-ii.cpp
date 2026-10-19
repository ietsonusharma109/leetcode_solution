class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // minimum right half mai hai
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // minimum left half mai hai (mid bhi ho sakta hai)
                right = mid;
            } else {
                // nums[mid] == nums[right]: pata nahi kis side hai,
                // right ko safely 1 se kam karo
                right--;
            }
        }
        return nums[left];   
    }
};