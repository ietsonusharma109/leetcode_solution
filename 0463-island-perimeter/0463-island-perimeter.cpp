class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4; // start by assuming all 4 sides are exposed

                    // check top neighbor
                    if (i > 0 && grid[i-1][j] == 1)
                        perimeter -= 2;
                    // check left neighbor
                    if (j > 0 && grid[i][j-1] == 1)
                        perimeter -= 2;
                }
            }
        }
        return perimeter;   
    }
};