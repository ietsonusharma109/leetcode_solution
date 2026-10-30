class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX;
        // dist[node][run], run in 1..k
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        using T = tuple<long long, int, int>; // cost, node, run
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top();
            pq.pop();
            if (d > dist[u][run]) continue;
            if (u == n - 1) return (int)d; // pehli baar pahuchana hi minimum hai

            for (auto&[v, w] : adj[u]) {
                int nr = (labels[v] == labels[u]) ? run + 1 : 1;
                if (nr > k) continue;
                if (d + w < dist[v][nr]) {
                    dist[v][nr] = d + w;
                    pq.push({d + w, v, nr});
                }
            }
        }
        return -1; 
    }
};