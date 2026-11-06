class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) { return a[1] < b[1];});
        int m = queries.size();
        vector<int> id(m), ans(m), cnt(n + 1);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int a, int b) {return queries[a] < queries[b]; });

        int l = 0, r = 0, active = 0, L = logs.size();
        for (int i : id) {
            int q = queries[i];
            while (r < L && logs[r][1] <= q) active += cnt[logs[r++][0]]++ == 0;
            while (l < r && logs[l][1] < q - x) active -= --cnt[logs[l++][0]] == 0;
            ans[i] = n - active;
        }
        return ans;
    }
};