class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        // pehli row poori free
        grid[0] = string(n, '.');

        // last column poori free
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }
        return grid;  
    }
};