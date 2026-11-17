class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // divisors[len] = len ke proper divisor (len itself nahi)
        vector<vector<int>> divs(n + 1);
        for (int d = 1; d <= n; d++)
            for (int len = 2 * d; len <= n; len += d)
                divs[len].push_back(d);

        // cost[i][j] = s[i..j] ko semi palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INF;
                for (int d : divs[len]) {
                    int changes = 0;
                    int m = len / d; // har group mai elements
                    for (int  g = 0; g < d; g++) {
                        // group: i+g, i+g+d, i+g+2d,...
                        int l = 0, r = m - 1;
                        while (l < r) {
                            if (s[i + g + l * d] != s[i + g + r * d]) changes++;
                            l++; r--;
                        }
                    }
                    best = min(best, changes);
                }
                cost[i][j] = best;
            }
        }
        // dp[i][j] = first i chars ko j parts mai todne ka min cost
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int p = 0; p + 2 <= i; p++) {
                    if (dp[p][j - 1] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p][i - 1]);
                }
            }
        }
        return dp[n][k];    
    }
};