class Solution {
public:
    int rev (int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long ans = 0;

        for (int x : nums) {
            int key = x - rev(x);
            ans = (ans + freq[key]) % MOD;
            freq[key]++;
        }
        return (int)ans;  
    }
};