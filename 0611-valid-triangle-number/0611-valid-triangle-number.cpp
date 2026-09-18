class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // nums[i..j-1] + nums[j] > nums[k] bhi true hoga
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;   
    }
};