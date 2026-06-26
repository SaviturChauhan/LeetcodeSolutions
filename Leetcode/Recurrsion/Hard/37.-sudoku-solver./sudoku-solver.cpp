class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int r, int c, char d) {
        // row and col check
        for (int i = 0; i < 9; i++) {
            if (grid[i][c] == d)
                return false;
            if (grid[r][i] == d)
                return false;
        }
        // box check
        int x = r / 3 * 3;
        int y = c / 3 * 3;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (grid[x + k][y + l] == d)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& grid) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(grid, i, j, d)) {
                            grid[i][j] = d;
                            if (solve(grid) == true) {
                                return true;
                            }
                            grid[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& grid) { solve(grid); }
};