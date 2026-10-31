class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int M = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        // dp[i][j][0] = right se aaya, dp[i][j][1] = down se aaye
        vector<vector<array<int,2>>> dp(m + 1, vector<array<int,2>>(n + 1));
        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int r = dp[i][j][0], d = dp[i][j][1];
                int toR = grid[i][j] ? d : (r + d) % M;
                int toD = grid[i][j] ? r : (r + d) % M;
                dp[i][j + 1][0] = (dp[i][j + 1][0] + toR) % M;
                dp[i + 1][j][1] = (dp[i + 1][j][1] + toD) % M;
            }
        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % M;
    }
};