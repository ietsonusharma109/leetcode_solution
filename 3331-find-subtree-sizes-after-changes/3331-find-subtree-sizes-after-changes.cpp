class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) g[parent[i]].push_back(i);


        vector<int> newpar(parent);
        vector<int> last(26, -1);
        vector<pair<int,int>> st;
        vector<int> saved(n, -1);
        st.push_back({0, 0});
        saved[0] = last[s[0] - 'a'];
        last[s[0] - 'a'] = 0;

        while (!st.empty()) {
            auto &top = st.back();
            int u = top.first;
            if (top.second < (int)g[u].size()) {
                int v = g[u][top.second++];
                int c = s[v] - 'a';
                if (last[c] != -1) newpar[v] = last[c];
                saved[v] = last[c];
                last[c] = v;
                st.push_back({v, 0});
            } else {
                last[s[u] - 'a'] = saved[u];
                st.pop_back();
            }
        }
        vector<vector<int>> ng(n);
        for (int i = 1; i < n; i++) ng[newpar[i]].push_back(i);

        vector<int> order;
        order.reserve(n);
        vector<int> stk = {0};
        while (!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            order.push_back(u);
            for (int v : ng[u]) stk.push_back(v);
        }
        vector<int> ans(n, 1);
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newpar[u]] += ans[u];
        }
        return ans;  
    }
};