class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size(), h = (x + 1) / 2;
        multiset<int> L, R;
        long long sl = 0, sh = 0, INF = 1e18;
        vector<long long> c(n + 1, 0);
        auto fix = [&]() {
            while ((int)L.size() > h) { auto it = prev(L.end()); sl -= *it; sh += *it; R.insert(*it); L.erase(it); }
            while ((int)L.size() < h && !R.empty()) {auto it = R.begin(); sh -= *it; sl += *it; L.insert(*it); R.erase(it); }
        };
        for (int i = 0; i < n; i++) {
            L.insert(nums[i]); sl += nums[i];
            auto t = prev(L.end()); sl -= *t; sh += *t; R.insert(*t); L.erase(t);
            if (i >= x) {
                int v = nums[i - x]; auto it = L.find(v);
                if (it != L.end()) L.erase(it), sl -= v; else R.erase(R.find(v)), sh -= v;
            }
            fix();
            if (i >= x - 1) {long long m = *L.rbegin(); c[i -  x + 1] = m * L.size() - sl + sh - m * R.size(); }
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (auto& r : dp) r[0] = 0;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= x) dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + c[i - x]);
            }
        return dp[n][k];
    }
};