class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int j = 1; // odd index pointer

        for (int i = 0; i < n; i += 2) {
            if (nums[i] % 2 == 1) {  // even no pe odd no mila
                while (nums[j] % 2 == 1) // odd index par jab tak odd hai, aage badho
                    j += 2;
                swap (nums[i], nums[j]);
            }
        }
        return nums;
    }
};