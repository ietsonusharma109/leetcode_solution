class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int M = 0;
        for (auto& it : items) M = max(M, it[0]);
        vector<int> cnt(M + 1), mul(M + 1);
        for (auto& it : items) cnt[it[0]]++;
        for (int f = 1; f <= M; f++) {
            if (cnt[f]) for (int x = f; x <= M; x += f) mul[f] += cnt[x];
        }
        long long m = LLONG_MAX, total = 0;
        vector<pair<long long, int>> v;
        for (auto& it : items) {
            m = min(m, (long long)it[1]);
            v.push_back({it[1], mul[it[0]] - 1});
        }
        sort(v.begin(), v.end());
        for (auto&[p, d] : v) {
            if (p >= 2 * m) break;
            long long k = min<long long>(d, budget / p);
            budget -= k * p;
            total += 2 * k;
        }
        return total + budget / m;   
    }
};