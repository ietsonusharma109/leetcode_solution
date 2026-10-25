class Solution {
public:
    int n, m;
    void dsf(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1)
            return;
        grid[i][j] = 1; // visited mark (water bana do)
        dsf(grid, i + 1, j);
        dsf(grid, i - 1, j);
        dsf(grid, i, j + 1);
        dsf(grid, i, j - 1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // step 1: border se connected land (0) ko flood-fill karke hata do
        for (int i = 0; i < n; i++) {
            dsf(grid, i, 0);
            dsf(grid, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dsf(grid, 0, j);
            dsf(grid, n - 1, j);
        }
        // step 2: bacha hua har island closed hai, unhe count karo
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dsf(grid, i, j);
                }
            }
        }
        return count;    
    }
};