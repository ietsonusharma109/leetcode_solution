class Solution {
    int n, T = 0;
    vector<int> in, out, dep, fw, p0;
    vector<vector<int>> g, up;
    void add(int i, int v) { for (; i <= n + 1; i += i & -i) fw[i] ^= v; }
    int get(int i) { int r = 0; for (; i > 0; i -= i & -i) r ^= fw[i]; return r; }
    void dfs(int u, int p, string& s) {
        in[u] = ++T; up[0][u] = p;
        p0[u] = (p == u ? 0 : p0[p]) ^ (1 << (s[u] - 'a'));
        for (int v : g[u]) if (v != p) { dep[v] = dep[u] + 1; dfs(v, u, s); }
        out[u] = T;
    }
public:
    int lca(int a, int b) {
        if (dep[a] < dep[b]) swap(a, b);
        for (int k = 16; k >= 0; k--) if (dep[a] - (1 << k) >= dep[b]) a = up[k][a];
        if (a == b) return a;
        for (int k = 16; k >= 0; k--) if (up[k][a] != up[k][b]) a = up[k][a], b = up[k][b];
        return up[0][a];
    }
    vector<bool> palindromePath(int N, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = N; g.assign(n, {}); in.assign(n, 0); out.assign(n, 0); dep.assign(n, 0);
        p0.assign(n, 0); fw.assign(n + 3, 0); up.assign(17, vector<int>(n, 0));
        for (auto& e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        dfs(0, 0, s);
        for (int k = 1; k < 17; k++) for (int i = 0; i < n; i++) up[k][i] = up[k-1][up[k-1][i]];
        vector<bool> ans;
        for (auto& q : queries) {
            istringstream is(q); string t; is >> t;
            if (t == "update") {
                int u; char c; is >> u >> c;
                int d = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                add(in[u], d); add(out[u] + 1, d); s[u] = c;
            } else {
                int u, v; is >> u >> v; int L = lca(u, v);
                int m = p0[u] ^ get(in[u]) ^ p0[v] ^ get(in[v]) ^ (1 << (s[L] - 'a'));
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;  
    }
};