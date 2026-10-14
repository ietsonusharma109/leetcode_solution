class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;      // empty prefix (0 odd numbers)
        int odd = 0, ans = 0;

        for (int x : nums) {
            odd += (x & 1);  // odd count so far
            if (odd >= k)
                ans += cnt[odd - k];
            cnt[odd]++;
        }
        return ans; 
    }
};