class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0; // gcd(0, x) = x
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = __gcd(g, (long long)nums[j]);
                l = l / __gcd(l, (long long)nums[j]) * nums[j];

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
                // prod bahut bada ho jaye to aage equal nahi ho sakta
                if (prod > 1e12) break;
            }
        }
        return ans;
    }
};