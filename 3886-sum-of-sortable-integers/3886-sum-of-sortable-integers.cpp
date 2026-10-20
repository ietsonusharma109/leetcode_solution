class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        auto& a = nums;
        int n = a.size();
        long long ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            int prev = 0, ok = 1;
            for (int s = 0; s < n && ok; s += k) {
                int d = 0, mn = 1e9, mx = 0;
                for (int i = 0; i < k; i++) {
                    d += a[s + i] > a[s + (i + 1) % k];
                    mn = min(mn, a[s + i]);
                    mx = max(mx, a[s + i]);
                }
                ok = d <= 1 && prev <= mn;
                prev = mx;
            }
            if (ok) ans += k;
        }
        return ans;  
    }
};