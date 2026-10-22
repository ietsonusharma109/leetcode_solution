class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), best = INT_MAX;
        bool asc = true, desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n) asc = false;
            if (nums[i] != ((nums[0] - i) % n + n) % n) desc = false;
        }
        if (asc) best = min((n - nums[0]) % n, nums[0] + 2);
        if (desc) {
            int m = (nums[0] + 1) % n;
            best = min(best, 1 + min(m, (n - m) % n));
        }
        return best == INT_MAX ? -1 : best;
    }
};